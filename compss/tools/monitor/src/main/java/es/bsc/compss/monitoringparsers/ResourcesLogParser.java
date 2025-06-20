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

package es.bsc.compss.monitoringparsers;

import es.bsc.compss.commons.Loggers;
import es.bsc.compss.ui.Constants;
import es.bsc.compss.ui.Properties;
import es.bsc.compss.ui.StateData;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.Vector;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;


public class ResourcesLogParser {

    private static final Logger LOGGER = LogManager.getLogger(Loggers.RESOURCES_LOG_PARSER);

    private static Vector<StateData> states = new Vector<>();
    private static String resourcesLogPath = "";

    private static int lastParsedLine = -1;
    private static long referenceTimestamp = 0L;
    private static long lastSeenTimestamp = 0L;
    private static int scaleTimeStamp = 0; // To scale X-axe for long applications
    private static boolean processInformation = false;


    /**
     * Format: Each entry separated by " ". Entry = "time:totalLoad:numResources" (int:float:int) TODO: javadoc.
     * 
     * @return String
     */
    public static String getTotalLoad() {
        StringBuilder result = new StringBuilder("'");
        for (int i = 0; i < states.size(); i++) {
            if (i != 0) {
                result.append(" ");
            }
            result.append(states.get(i).getTimestamp()).append(":").append(states.get(i).getTotalLoad()).append(":")
                .append(states.get(i).getTotalResources());
        }
        result.append("'");

        LOGGER.debug("TotalLoadPoints: " + result.toString());
        return result.toString();
    }

    /**
     * Format: Each entry separated by " ". Entry = "time:loadC0:...:loadCN:numResources" (int:float:...:int) TODO:
     * javadoc.
     * 
     * @return String
     */
    public static String getLoadPerCore() {
        // Calculate matrix dimensions with the maximum number of cores in a execution
        int maxCores = 0;
        for (int i = 0; i < states.size(); ++i) {
            maxCores = Math.max(maxCores, states.get(i).getMeanTime().size());
        }

        // Generate string state
        StringBuilder coreData = new StringBuilder("'");
        for (int i = 0; i < states.size(); i++) {
            if (i != 0) {
                coreData.append(" ");
            }
            // Add timestamp
            coreData.append(states.get(i).getTimestamp());
            // Add information about cores in this state
            for (Float coreLoad : states.get(i).getMeanTime()) {
                if (coreLoad != null) {
                    coreData.append(":").append(coreLoad);
                } else {
                    coreData.append(":").append(0.0);
                }
            }
            // Add 0 for non existing cores
            for (int j = states.get(i).getMeanTime().size(); j < maxCores; ++j) {
                coreData.append(":").append(0.0);
            }
            // Add number of resources in this state
            coreData.append(":").append(states.get(i).getTotalResources());
        }
        coreData.append("'");

        LOGGER.debug("LoadPerCorePoints: " + coreData.toString());
        LOGGER.debug("LoadPerCorePointsMAXCORES: " + maxCores);
        return "'" + String.valueOf(maxCores) + "'," + coreData.toString();
    }

    /**
     * Format: Each entry separated by " ". Entry = "time:totalRunningCores:numResources" (int:int:int) TODO: javadoc.
     * 
     * @return
     */
    public static String getTotalRunningCores() {
        StringBuilder result = new StringBuilder("'");
        for (int i = 0; i < states.size(); i++) {
            if (i != 0) {
                result.append(" ");
            }
            result.append(states.get(i).getTimestamp()).append(":").append(states.get(i).getTotalCoresRunning())
                .append(":").append(states.get(i).getTotalResources());
        }
        result.append("'");

        LOGGER.debug("TotalRunningCoresPoints: " + result.toString());
        return result.toString();
    }

    //

    /**
     * Format: Each entry separated by " ". Entry = "time:#runningCore0:...:numResources" (int:int:...:int) TODO:
     * javadoc.
     * 
     * @return String
     */
    public static String getRunningCoresPerCore() {
        // Calculate matrix dimensions with the maximum number of cores in a execution
        int maxCores = 0;
        for (int i = 0; i < states.size(); ++i) {
            maxCores = Math.max(maxCores, states.get(i).getMeanTime().size());
        }

        // Generate string state
        StringBuilder coreData = new StringBuilder("'");
        for (int i = 0; i < states.size(); i++) {
            if (i != 0) {
                coreData.append(" ");
            }
            // Add timestamp
            coreData.append(states.get(i).getTimestamp());
            // Add information about cores in this state
            for (Integer numRunning : states.get(i).getRunningCores()) {
                if (numRunning != null) {
                    coreData.append(":").append(numRunning);
                } else {
                    coreData.append(":").append(0);
                }
            }
            // Add 0 for non existing cores
            for (int j = states.get(i).getRunningCores().size(); j < maxCores; ++j) {
                coreData.append(":").append(0);
            }
            // Add number of resources in this state
            coreData.append(":").append(states.get(i).getTotalResources());
        }
        coreData.append("'");

        LOGGER.debug("RunningCoresPerCorePoints: " + coreData.toString());
        LOGGER.debug("RunningCoresPerCorePointsMAXCORES: " + maxCores);
        return "'" + String.valueOf(maxCores) + "'," + coreData.toString();
    }

    /**
     * Format: Each entry separated by " ". Entry = "time:totalPendingCores:numResources" (int:int:int) TODO: javadoc.
     * 
     * @return String
     */
    public static String getTotalPendingCores() {
        StringBuilder result = new StringBuilder("'");
        for (int i = 0; i < states.size(); i++) {
            if (i != 0) {
                result.append(" ");
            }
            result.append(states.get(i).getTimestamp()).append(":").append(states.get(i).getTotalCoresPending())
                .append(":").append(states.get(i).getTotalResources());
        }
        result.append("'");

        LOGGER.debug("TotalPendingCoresPoints: " + result.toString());
        return result.toString();
    }

    /**
     * Format: Each entry separated by " ". Entry = "time:#pendingCore0:...:numResources" (int:int:...:int) TODO:
     * javadoc.
     * 
     * @return String
     */
    public static String getPendingCoresPerCore() {
        // Calculate matrix dimensions with the maximum number of cores in a execution
        int maxCores = 0;
        for (int i = 0; i < states.size(); ++i) {
            maxCores = Math.max(maxCores, states.get(i).getMeanTime().size());
        }

        // Generate string state
        StringBuilder coreData = new StringBuilder("'");
        for (int i = 0; i < states.size(); i++) {
            if (i != 0) {
                coreData.append(" ");
            }
            // Add timestamp
            coreData.append(states.get(i).getTimestamp());
            // Add information about cores in this state
            for (Integer numPending : states.get(i).getPendingCores()) {
                if (numPending != null) {
                    coreData.append(":").append(numPending);
                } else {
                    coreData.append(":").append(0);
                }
            }
            // Add 0 for non existing cores
            for (int j = states.get(i).getPendingCores().size(); j < maxCores; ++j) {
                coreData.append(":").append(0);
            }
            // Add number of resources in this state
            coreData.append(":").append(states.get(i).getTotalResources());
        }
        coreData.append("'");

        LOGGER.debug("PendingCoresPerCorePoints: " + coreData.toString());
        LOGGER.debug("PendingCoresPerCorePointsMAXCORES: " + maxCores);
        return "'" + String.valueOf(maxCores) + "'," + coreData.toString();
    }

    /**
     * Format: Last entry only. Entry = "time:CPU:MEM" (int:int:int) TODO: javadoc.
     * 
     * @return String
     */
    public static String getResourcesStatus() {
        StringBuilder result = new StringBuilder("'");
        result.append(states.lastElement().getTimestamp()).append(":");
        result.append(states.lastElement().getTotalCPUConsumption()).append(":");
        result.append(states.lastElement().getTotalMemoryConsumption());
        result.append("'");

        if (LOGGER.isDebugEnabled()) {
            LOGGER.debug("ResourcesStatusPoints: " + result.toString());
        }
        return result.toString();
    }

    /**
     * TODO: javadoc.
     */
    public static void parse() {
        LOGGER.debug("Parsing resources.log file...");
        if (!Properties.getBasePath().equals("")) {
            // Check if applicaction has changed
            String newPath = Properties.getBasePath() + File.separator + Constants.RESOURCES_LOG;
            if (!resourcesLogPath.equals(newPath)) {
                // Load new application
                clear();
                resourcesLogPath = newPath;
            }

            // Parse
            try (FileReader fr = new FileReader(resourcesLogPath); BufferedReader br = new BufferedReader(fr)) {

                String line = br.readLine(); // Parsed line
                int i = 0; // Line counter
                while (line != null) {
                    if (i > lastParsedLine) {
                        // Check first for the TIMESTAMP flag
                        if (line.contains("TIMESTAMP = ")) {
                            LOGGER.debug("* Timestamp flag");
                            scaleTimeStamp++;
                            if (scaleTimeStamp >= Properties.getxScaleForLoadGraph()) {
                                // Received information needs to be processed
                                processInformation = true;
                                scaleTimeStamp = 0;
                                lastSeenTimestamp = Long.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                // Init structures
                                if (states.isEmpty()) {
                                    // First entry. Set all to 0
                                    referenceTimestamp = lastSeenTimestamp;
                                    states.add(new StateData(0)); // seconds
                                } else {
                                    // Generic entry. Set values as the before entry
                                    states.add(new StateData(states.lastElement()));
                                    // Timestamp in seconds
                                    states.lastElement()
                                        .setTimestamp(((int) (lastSeenTimestamp - referenceTimestamp)) / 1_000);
                                }
                            } else {
                                processInformation = false;
                            }
                        }
                        // Check line information and add it to structures
                        if (processInformation) {
                            if (line.contains("INFO_MSG = [New resource available in the pool")) {
                                // !!! We do not parse this message anymore because the RESOURCES_INFO contains full
                                // information
                                LOGGER.debug("* New resource available flag");
                                // String resourceName = line.substring(line.lastIndexOf("=") + 2);
                                // Add resource information
                                // states.lastElement().addResource(resourceName, "WORKER");
                            } else if (line.contains("INFO_MSG = [New service available")) {
                                LOGGER.debug("* New service available flag");
                                // String resourceName = line.substring(line.lastIndexOf("=") + 2);
                                // Add resource information
                                // TODO: Runtime doesn't register services as resources (tab Resources) so we don't
                                // register services
                                // states.lastElement().addResource(resourceName, "SERVICE");
                            } else if (line.contains("INFO_MSG = [Resource removed from the pool")) {
                                LOGGER.debug("* Resource removed flag");
                                String resourceName = line.substring(line.lastIndexOf("=") + 2);
                                // Remove resource information
                                states.lastElement().removeResource(resourceName);
                            } else if (line.contains("LOAD_INFO = [")) {
                                LOGGER.debug("* Load Information flag");
                                states.lastElement().purgeLoadValues();
                                line = br.readLine();
                                i = i + 1;
                                while ((line != null) && (line.contains("CORE_INFO = ["))) {
                                    line = br.readLine(); // id
                                    i = i + 1;
                                    final int id = Integer.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                    line = br.readLine(); // no_resource
                                    i = i + 1;
                                    final int no_resource = Integer.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                    line = br.readLine(); // ready
                                    i = i + 1;
                                    final int ready = Integer.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                    line = br.readLine(); // running
                                    i = i + 1;
                                    final int running = Integer.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                    // Skip min
                                    line = br.readLine();
                                    i = i + 1;
                                    // Get mean
                                    line = br.readLine();
                                    i = i + 1;
                                    final int mean = Integer.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                    // Skip max
                                    line = br.readLine();
                                    i = i + 1;
                                    // Get mean exec time (Mean time of the running tasks)
                                    line = br.readLine();
                                    i = i + 1;
                                    int meanExec = Integer.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                    // Skip ] of CORE_INFO
                                    line = br.readLine();
                                    i = i + 1;
                                    // Add information
                                    float pendingLoad = Float.valueOf((no_resource + ready) * (mean));
                                    float remainingTime = Math.max(mean - meanExec, 0);
                                    float runningLoad = Float.valueOf(running * remainingTime);
                                    float load = (pendingLoad + runningLoad) / Float.valueOf(1000); // seconds
                                    states.lastElement().addCoreLoad(id, load);
                                    states.lastElement().addCorePending(id, no_resource + ready);
                                    states.lastElement().addCoreRunning(id, running);
                                    // Loop
                                    line = br.readLine();
                                    i = i + 1;
                                }
                            } else if (line.contains("RESOURCES_INFO = [")) {
                                LOGGER.debug("* Resources Information flag");
                                states.lastElement().purgeResourcesValues();
                                line = br.readLine();
                                i = i + 1;
                                while ((line != null) && (line.contains("RESOURCE = ["))) {
                                    line = br.readLine(); // Name
                                    i = i + 1;
                                    final String resourceName = line.substring(line.lastIndexOf("=") + 2);
                                    line = br.readLine(); // Type
                                    i = i + 1;
                                    final String type = line.substring(line.lastIndexOf("=") + 2);
                                    line = br.readLine(); // CPUS
                                    i = i + 1;
                                    int cpus = Integer.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                    line = br.readLine(); // Memory
                                    i = i + 1;
                                    float memory = Float.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                    // Add resource information
                                    states.lastElement().addResource(resourceName, type, cpus, memory);

                                    // Process CAN_RUN
                                    line = br.readLine(); // CAN_RUN = [
                                    i = i + 1;
                                    line = br.readLine(); // CORE = [ or ]
                                    i = i + 1;
                                    while ((line != null) && (line.contains("CORE = ["))) {
                                        line = br.readLine(); // COREID
                                        i = i + 1;
                                        // int coreId = Integer.valueOf(line.substring(line.lastIndexOf("=") + 2));
                                        line = br.readLine(); // NUM_SLOTS
                                        i = i + 1;
                                        // int numSlotsCore = Integer.valueOf(line.substring(line.lastIndexOf("=")
                                        // + 2));
                                        // Add core information to resource
                                        // TODO: Display runnable cores per resource
                                        // states.lastElement().addCanRunCoreSlots(coreId, numSlotsCore);
                                        // Skip ] of CORE
                                        line = br.readLine();
                                        i = i + 1;
                                        // Loop
                                        line = br.readLine();
                                        i = i + 1;
                                    }
                                    // Skip ] of RESOURCE
                                    line = br.readLine();
                                    i = i + 1;
                                    // Loop
                                    line = br.readLine();
                                    i = i + 1;
                                }
                            } else if (line.contains("CLOUD_INFO = [")) {
                                LOGGER.debug("* Cloud info flag");
                                // TODO: Display cloud information
                            } else if (line.contains("INFO_MSG = [Stopping all workers]")) {
                                LOGGER.debug("* Stop all workers flag");
                                // No more workers. End point
                                states.lastElement().purgeValues();
                            }
                        }
                    }
                    line = br.readLine();
                    i = i + 1;
                }
                lastParsedLine = i - 1;
            } catch (Exception e) {
                clear();
                LOGGER.error("Cannot parse resrouces.log file: " + resourcesLogPath);
            }
        } else {
            // Load default value
            clear();
        }
        LOGGER.debug("resources.log file parsed");
    }

    /**
     * TODO: javadoc.
     */
    public static void clear() {
        resourcesLogPath = "";

        lastParsedLine = -1;
        referenceTimestamp = 0L;
        lastSeenTimestamp = 0L;
        scaleTimeStamp = 0;
        processInformation = false;

        states.clear();
    }

}
