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

/*
 * Wrappers that make possible to call thread (set|get)affinity from Python2
 */
#pragma once
#include <Python.h>
#include <structmember.h>
#include <unistd.h>
#include <sched.h>
#include <vector>

/*
  Wrapper for sched_setaffinity.
  Arguments:
  - mask: a list of integers that denote the CPU identifiers (0-based) that we
          want to allow
  - pid: if zero, this will be transformed to the current pid
  Returns None
*/
static PyObject* pysched_setaffinity(PyObject* self, PyObject* args);


/*
  Wrapper for sched_getaffinity.
  Arguments:
  - pid (OPTIONAL): if zero or ommited, this will be transformed to the current pid
  Returns the list of allowed CPUs
*/
static PyObject* pysched_getaffinity(PyObject* self, PyObject* args);


extern "C" {
    PyMODINIT_FUNC
    PyInit_process_affinity(void);
}
