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
package es.bsc.compss.checkpoint.types;

import es.bsc.compss.checkpoint.CheckpointGroup;
import es.bsc.compss.types.Task;
import es.bsc.compss.types.data.info.DataVersion;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class CheckpointGroupImpl implements CheckpointGroup {

    public enum GroupState {
        OPEN, CLOSED
    }


    private final String name;
    private GroupState state;
    private final HashMap<Integer, DataVersion> outputData;
    private final Set<Task> finishedTasks;
    private final Set<Task> tasks;


    /**
     * CheckpointGroupImpl.
     *
     * @param name of the checkpointGroup.
     */
    public CheckpointGroupImpl(String name) {
        this.name = name;
        this.state = GroupState.OPEN;
        this.tasks = new HashSet();
        this.outputData = new HashMap<>();
        this.finishedTasks = new HashSet<>();
    }

    /**
     * Puts data as an output of the group.
     *
     * @param dv DataVersion of the output data
     */
    public void producesData(DataVersion dv) {
        DataVersion dataId = outputData.get(dv.getDataInstanceId().getDataId());
        if (dataId != null) {
            if (dv.getDataInstanceId().getVersionId() > dataId.getDataInstanceId().getVersionId()) {
                outputData.put(dv.getDataInstanceId().getDataId(), dv);
            }
        } else {
            outputData.put(dv.getDataInstanceId().getDataId(), dv);
        }
    }

    /**
     * Returns the name of the checkpointing group.
     * 
     * @return name of the group
     */
    public String getName() {
        return name;
    }

    /**
     * Get size of the group.
     * 
     * @return number of tasks within the group
     */
    public int getSize() {
        return this.tasks.size();
    }

    /**
     * Gets the state of a group.
     * 
     * @return state of the group
     */
    public GroupState getState() {
        return this.state;
    }

    /**
     * Closes a group.
     */
    public void close() {
        state = GroupState.CLOSED;
    }

    /**
     * Adds a task to the group.
     *
     * @param task Task to be added.
     */
    public void addTask(Task task) {
        this.tasks.add(task);
    }

    /**
     * Gets the set of finished tasks.
     * 
     * @return tasks belonging to the group that have finished the execution
     */
    public Set<Task> getFinishedTasks() {
        return finishedTasks;
    }

    /**
     * Adds a finished task.
     *
     * @param task Task to be added.
     */
    public void addFinishedTask(Task task) {
        finishedTasks.add(task);
    }

    /**
     * Gets the data of a group.
     *
     * @return list the data values generated by the task group.
     */
    public List<DataVersion> getOutputData() {
        return new ArrayList<>(outputData.values());
    }

}
