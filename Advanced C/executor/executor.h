#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/types.h>
#include "time.h"
#include "task.h"

/*RenameToStructPeriodicExecutor*/

typedef struct PeriodicExecutor PeriodicExecutor;

/*Description:
Creates new tasks executor.

Input:
*_name - the name of executor.
_clk_id - Clock type:
	* CLOCK_REALTIME,
	* CLOCK_REALTIME_COARSE,
	* CLOCK_MONOTONIC.
	
Output:
NULL - If one of the memory allocations failed.
executor - pointer to the executor struct.*/
PeriodicExecutor* PeriodicExecutorCreate(const char* _name, clockid_t _clk_id);


/*Description:
Destroy the executor and the tasks inside.

Input:
*_executor - pointer to the executor struct.*/
void PeriodicExecutorDestroy(PeriodicExecutor* _executor);


/*Description:
Enter a new task to the executor.

Input:
*_executor - pointer to the executor struct.
_func - Pointer to the task function.
*_context - The input for the task function.
_periodTime - Time between the task runs (in milliseconds - number of seconds divided by a thousand)
	
Output:
0 - _executor == NULL || _func == NULL or if the task insert failed.
1 -  if the task insert successfully.*/
int PeriodicExecutorAdd(PeriodicExecutor* _executor, taskFunction _func, void* _context, size_t _periodTime);


/*Description:
Runs all tasks in the executor by period time.

Input:
*_executor - pointer to the executor struct.
	
Output:
0 - If the Heap Build failed.
_executor ->  m_numOfCycles - The number of cycles.*/
size_t PeriodicExecutorRun(PeriodicExecutor* _executor);

/*Description:
Stops the task run.

Input:
*_executor - pointer to the executor struct.
	
Output:
0 - If _executor == NULL.
_executor -> m_numOfTask - Number of tasks left in the executor.*/
size_t PeriodicExecutorPause(PeriodicExecutor* _executor);

#endif /*#ifndef__EXECUTOR_H__*/
