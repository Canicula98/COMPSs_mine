/*
 *  Copyright 2002-2025 Barcelona Supercomputing Center (www.bsc.es)
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */
package es.bsc.compss.util.parsers;

import es.bsc.compss.log.Loggers;
import es.bsc.compss.types.CoreElementDefinition;
import es.bsc.compss.types.implementations.ImplementationDescription;
import es.bsc.compss.types.implementations.MethodType;
import es.bsc.compss.types.resources.MethodResourceDescription;
import es.bsc.compss.util.ErrorManager;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.regex.Pattern;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;


public class IDLParser {

    // Logger
    private static final Logger LOGGER = LogManager.getLogger(Loggers.TS_COMP);

    // Error constants
    private static final String CONSTR_LOAD_ERR = "Error loading constraints";

    // Parser IDL Tags
    private static final String CONSTRAINT_IDL = "@Constraints";
    private static final String IMPLEMENTS_IDL = "@Implements";
    private static final String PROCESSOR_IDL = "processors";
    private static final String CLASS_METHOD_SEPARATOR = "::";


    private static enum CodeRegion {
        COMMENT, // For comments
        TASK, // For tasks
        CONSTRAINT, // For constraints annotation
        FUNCTION, // Function (not task)
        IMPLEMENTATION // Implementation
    }


    /**
     * Parses the methods found in the IDL file.
     *
     * @param constraintsFile IDL file location.
     * @return list CE defined in the IDL
     */
    public static List<CoreElementDefinition> parseIDLMethods(String constraintsFile) {
        LOGGER.debug("Loading file " + constraintsFile);
        List<CoreElementDefinition> detectedCEDs = new LinkedList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(constraintsFile))) {
            MethodResourceDescription defaultCtr = MethodResourceDescription.EMPTY_FOR_CONSTRAINTS.copy();
            boolean isReadingCodeRegion = false;
            StringBuilder structureString = new StringBuilder();
            CodeRegion type = null;
            CImplementation implementation = null;
            MethodResourceDescription currConstraints = new MethodResourceDescription(defaultCtr);
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                // System.out.println("Read line: "+ line);
                if (isReadingCodeRegion && type != null) {
                    if (line.startsWith("//")) {
                        // Line is a comment inside the core region ignoring it
                        continue;
                    } else {
                        if (type.equals(CodeRegion.COMMENT)) {
                            if (line.endsWith("*/")) {
                                isReadingCodeRegion = false;
                            } else {
                                continue;
                            }
                        } else {
                            if (line.matches(".*[)];")) {
                                isReadingCodeRegion = false;
                                structureString.append(line);
                                if (type.equals(CodeRegion.CONSTRAINT)) {
                                    LOGGER.debug("[IDL Parser] Loading constraint: " + structureString.toString());
                                    currConstraints = loadCConstraints(structureString.toString());
                                } else {
                                    if (type.equals(CodeRegion.IMPLEMENTATION)) {
                                        LOGGER.debug(
                                            "[IDL Parser] Loading implementation: " + structureString.toString());
                                        implementation = loadCImplementation(structureString.toString());
                                    } else {
                                        if (type.equals(CodeRegion.FUNCTION)) {
                                            LOGGER.debug("[IDL Parser] Loading function: " + structureString.toString()
                                                + " constraint:" + currConstraints);
                                            CoreElementDefinition ced = parseCFunction(structureString.toString(),
                                                currConstraints, implementation);
                                            detectedCEDs.add(ced);
                                            currConstraints = new MethodResourceDescription(defaultCtr);
                                            implementation = null;
                                        }
                                    }
                                }
                            } else {
                                structureString.append(line);
                            }
                        }
                    }

                } else {
                    if (line.startsWith("//") || line.startsWith("#")
                        || (line.startsWith("/*") && line.endsWith("*/"))) {
                        // Line is a comment of pre-processor pragma ignoring it
                        continue;
                    } else {
                        if (line.startsWith("/*")) {
                            // Line starts comment region
                            isReadingCodeRegion = true;
                            type = CodeRegion.COMMENT;
                        } else {
                            if (line.matches(CONSTRAINT_IDL + "[(].*[)];")) {
                                // Line contains
                                LOGGER.debug("[IDL Parser] Loading constraint: " + line);
                                currConstraints = loadCConstraints(line);
                                continue;
                            } else {
                                if (line.matches(CONSTRAINT_IDL + "[(].*")) {
                                    // Line starts a constraints region
                                    isReadingCodeRegion = true;
                                    structureString = new StringBuilder(line);
                                    type = CodeRegion.CONSTRAINT;
                                } else {
                                    if (line.matches(IMPLEMENTS_IDL + "[(].*[)];")) {
                                        // Line implements
                                        LOGGER.debug("[IDL Parser] Loading implementation: " + line);
                                        implementation = loadCImplementation(line);
                                        continue;
                                    } else {
                                        if (line.matches(IMPLEMENTS_IDL + "[(].*")) {
                                            // Line starts a constraints region
                                            isReadingCodeRegion = true;
                                            structureString = new StringBuilder(line);
                                            type = CodeRegion.IMPLEMENTATION;
                                        } else {
                                            if (line.matches(".*[(].*[)];")) { // NOSONAR safe regex.
                                                // Line contains a function
                                                LOGGER.debug("[IDL Parser] Loading function: " + line + " constraint:"
                                                    + currConstraints);
                                                CoreElementDefinition ced =
                                                    parseCFunction(line, currConstraints, implementation);
                                                detectedCEDs.add(ced);

                                                currConstraints = new MethodResourceDescription(defaultCtr);
                                                implementation = null;
                                            } else {
                                                if (line.matches(".*[(].*")) { // NOSONAR safe regex.
                                                    // Line starts a function region
                                                    isReadingCodeRegion = true;
                                                    structureString = new StringBuilder(line);
                                                    type = CodeRegion.FUNCTION;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } catch (IOException ioe) {
            LOGGER.fatal(CONSTR_LOAD_ERR, ioe);
        }
        return detectedCEDs;
    }

    private static CImplementation loadCImplementation(String line) {
        if (line.startsWith(IMPLEMENTS_IDL)) {
            line = line.substring(line.indexOf("(") + 1, line.indexOf(")"));
        }
        int indexOfSeparator = line.indexOf(CLASS_METHOD_SEPARATOR);
        if (indexOfSeparator > 0) {
            String className = line.substring(0, indexOfSeparator);
            // String methodName = line.substring(indexOfSeparator + CLASS_METHOD_SEPARATOR.length());
            StringBuilder methodNameBuilder = new StringBuilder();
            methodNameBuilder.append(className).append(CLASS_METHOD_SEPARATOR)
                .append(line.substring(indexOfSeparator + CLASS_METHOD_SEPARATOR.length()));
            String methodName = methodNameBuilder.toString();
            // logger.debug("New C method implementation: "+className+"::"+methodName);
            LOGGER.debug("New C method implementation:");
            LOGGER.debug("\t Classname: " + className);
            LOGGER.debug("\t Methodname: " + methodName);
            return new CImplementation(className, methodName);
        } else {
            // logger.debug("New C method implementation: "+line);
            return new CImplementation("NULL", line);
        }
    }

    private static CoreElementDefinition parseCFunction(String line, MethodResourceDescription currConstraints,
        CImplementation implementation) {

        final StringBuilder implementedTaskSignatureBuffer = new StringBuilder();
        final StringBuilder implementationSignatureBuffer = new StringBuilder();

        if (line.startsWith("static ")) {
            // isStatic = true;
            line = line.replace("static ", "");
        }
        if (!line.startsWith("void ")) {
            // hasReturn = true;
        }
        // remove spaces before square-brackets
        line = line.replaceAll(Pattern.quote(" ["), "[");

        line = line.replaceAll("[(|)|,|;|\n|\t]", " ");
        String[] splits = line.split("\\s+");
        CImplementation task = loadCImplementation(splits[1]);
        String methodName = task.getMethodName();
        String declaringClass = task.getClassName();
        if (implementation != null) {
            implementedTaskSignatureBuffer.append(implementation.getMethodName()).append("(");
        } else {
            implementedTaskSignatureBuffer.append(methodName).append("(");
        }
        implementationSignatureBuffer.append(methodName).append("(");

        // Computes the method's signature
        for (int i = 2; i < splits.length; i++) {
            String paramDirection = splits[i++];
            String paramType = splits[i++];
            // String paramName = splits[i];
            String type = "BINDING_OBJECT_T";

            /*
             * OLD version C-binding String type = "FILE_T";
             */
            if (paramType.toUpperCase().compareTo("FILE") == 0) {
                type = "FILE_T";
            } else {
                if (paramDirection.toUpperCase().compareTo("INOUT") == 0) {
                    type = "BINDING_OBJECT_T";
                } else {
                    if (paramDirection.toUpperCase().compareTo("OUT") == 0) {
                        type = "BINDING_OBJECT_T";
                    } else {
                        if (paramType.compareTo("boolean") == 0) {
                            type = "BOOLEAN_T";
                        } else {
                            if (paramType.compareTo("char") == 0) {
                                type = "CHAR_T";
                            } else {
                                if (paramType.compareTo("int") == 0) {
                                    type = "INT_T";
                                } else {
                                    if (paramType.compareTo("float") == 0) {
                                        type = "FLOAT_T";
                                    } else {
                                        if (paramType.compareTo("double") == 0) {
                                            type = "DOUBLE_T";
                                        } else {
                                            if (paramType.compareTo("byte") == 0) {
                                                type = "BYTE_T";
                                            } else {
                                                if (paramType.compareTo("short") == 0) {
                                                    type = "SHORT_T";
                                                } else {
                                                    if (paramType.compareTo("long") == 0) {
                                                        type = "LONG_T";
                                                    } else {
                                                        if (paramType.compareTo("string") == 0) {
                                                            type = "STRING_T";
                                                        } else {
                                                            if (paramType.compareTo("enum") == 0) {
                                                                type = "INT_T";
                                                                i++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            implementedTaskSignatureBuffer.append(type).append(",");
            implementationSignatureBuffer.append(type).append(",");
        }

        if (splits.length > 2) {
            implementedTaskSignatureBuffer.deleteCharAt(implementedTaskSignatureBuffer.lastIndexOf(","));
            implementationSignatureBuffer.deleteCharAt(implementationSignatureBuffer.lastIndexOf(","));
        }
        implementedTaskSignatureBuffer.append(")");
        implementationSignatureBuffer.append(")");

        if (implementation != null) {
            implementedTaskSignatureBuffer.append(implementation.getClassName());
        } else {
            implementedTaskSignatureBuffer.append(declaringClass);
        }
        implementationSignatureBuffer.append(declaringClass);

        final String taskSignature = implementedTaskSignatureBuffer.toString();
        final String implementationSignature = implementationSignatureBuffer.toString();

        final CoreElementDefinition ced = new CoreElementDefinition();
        ced.setCeSignature(taskSignature);

        // Register method implementation
        ImplementationDescription<?, ?> implDef = null;
        try {
            implDef = ImplementationDescription.defineImplementation(MethodType.METHOD.toString(),
                implementationSignature, false, currConstraints, null, null, null, declaringClass, methodName);
        } catch (Exception e) {
            ErrorManager.error(e.getMessage());
        }
        ced.addImplementation(implDef);
        return ced;
    }

    private static MethodResourceDescription loadCConstraints(String line) {
        line = line.substring(CONSTRAINT_IDL.length() + 1);
        String proc = "";

        if (line.matches(".*" + PROCESSOR_IDL + ".*")) { // NOSONAR safe regex.
            int procStart = line.indexOf("{");
            int procEnd = line.indexOf("}");
            proc = line.substring(procStart, procEnd + 1);
            line = line.replace(proc, "");
            line = line.replace("processors=", "");
            proc = proc.replaceAll("[{}]", "");
            LOGGER.debug("[IDL Parser] Loading processors: " + proc);
            line = line.replaceFirst(",", "");
        }

        line = line.replaceAll("[() ;\n\t]", "");
        String[] constraints = line.split(",");

        return new MethodResourceDescription(constraints, proc);
    }


    private static class CImplementation {

        private final String className;
        private final String methodName;


        public CImplementation(String className, String methodName) {
            this.className = className;
            this.methodName = methodName;
        }

        public String getClassName() {
            return this.className;
        }

        public String getMethodName() {
            return this.methodName;
        }

    }

}
