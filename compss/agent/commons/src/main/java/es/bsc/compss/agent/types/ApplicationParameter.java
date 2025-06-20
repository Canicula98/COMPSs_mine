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
package es.bsc.compss.agent.types;

import es.bsc.compss.types.annotations.parameter.DataType;
import es.bsc.compss.types.annotations.parameter.Direction;


public interface ApplicationParameter {

    /**
     * Returns the name of the parameter.
     *
     * @return parameter name
     */
    public String getParamName();

    /**
     * Returns the type of the data on the parameter.
     *
     * @return type of the data on the parameter.
     */
    public DataType getType();

    /**
     * Returns the direction of the parameter.
     *
     * @return direction of the parameter
     */
    public Direction getDirection();

    /**
     * Returns the StdIOStream to redirect to the parameter.
     *
     * @return stdIOStream to redirect to the parameter
     */
    public Object getStdIOStream();

    /**
     * Returns the prefix to apply to the parameter value.
     *
     * @return prefix to apply to the parameter value
     */
    public Object getPrefix();

    /**
     * Returns the object passed in as parameter value.
     *
     * @return the object passed in as parameter value
     * @throws Exception Error unmarshalling the object
     */
    public Object getValueContent() throws Exception;

    /**
     * Returns a set of sources from where to fetch the param value.
     *
     * @return sources from where to fetch the param value
     */
    public RemoteDataInformation getRemoteData();

    /**
     * Returns the python object type of the parameter, if exists.
     *
     * @return parameter name
     */
    public String getContentType();

    /**
     * Check if parameter should keep the rename.
     * 
     * @return returns true if parameter should keep the rename
     */
    public boolean isKeepRename();

    /**
     * Get the parameter weight for locality.
     * 
     * @return returns the parameter weight
     */
    public double getWeight();

    /**
     * Returns the Id identifying the value generated by the parameter.
     * 
     * @return
     */
    public String getDataMgmtId();

}
