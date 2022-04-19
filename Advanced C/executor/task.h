#ifndef __TASK_H__
#define __TASK_H__
#include "time.h"

/*RenameToStructTask*/

typedef struct Task Task;

/*RenameToFunction*/

typedef int (*taskFunction)(void *);
typedef void(*elementDestroy)(void* _item);

/*Description:
Creates new task.

Input:
_func - Pointer to the task function.
*_context - The input for the task function.
_periodTime - Time between the task runs (in milliseconds - number of seconds divided by a thousand)
	
Output:
NULL - If _funk == NULL or if the memory allocations failed.
task - pointer to the task struct.*/
Task* CreateTask (taskFunction _funk,  void* _context, size_t periodTime);


/*Description:
Calculates the next run time of the task.

Input:
_task - pointer to the task struct.
_clockId - Clock type:
	* CLOCK_REALTIME,
	* CLOCK_REALTIME_COARSE,
	* CLOCK_MONOTONIC.
	
Output:
0 - If _task == NULL.
1 - if The calculation was performed successfully.*/
int CalculateNextRunTime(Task* _task, clockid_t _clockId);

/*Description:
Runs the task function after the wait of the period time.

Input:
_task - pointer to the task struct.
_clockId - Clock type:
	* CLOCK_REALTIME,
	* CLOCK_REALTIME_COARSE,
	* CLOCK_MONOTONIC.
	
Output:
0 - If _task == NULL.
0/1 - The return value of the function.*/
int RunTask(Task* _task, clockid_t _clockId);

/*Description:
Destroy the task.

Input:
_task - pointer to the task struct.*/
void DestroyTask (void* _task);

/*Description:
Compares the times of two different tasks.

Input:
_task1 - task 1.
_task2 - task 2.
	
Output:
1 - If the time of task 1 is smaller than the time of task 2.
0 - If the time of task 1 is biger than the time of task 2.*/
int NextRunTimeComparator(const void* _task1, const void* _task2);

















#endif /*#ifndef__TASK_H__*/
