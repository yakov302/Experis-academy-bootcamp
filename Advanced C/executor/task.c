#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/types.h>
#include "task.h"
#include "time.h"
#define MAGIC_NUMBER2 81475
#define FAIL 0
#define SUCCESS 1

/**********************structTask***********************/

struct Task
{
	taskFunction m_functionPointer;
	timespec m_nextRunTime;
	size_t m_periodTime;
	void* m_context;
	int m_magicNumber;		
};

/**********************CreateTask***********************/

Task* CreateTask (taskFunction _funk,  void* _context, size_t periodTime)
{
Task* task;

	if(_funk == NULL)
	{
		return NULL;
	}
	
	if((task = ((Task*)malloc(sizeof(Task)))) == NULL)
	{
		return NULL;
	}
	
	task -> m_functionPointer = _funk;
	task -> m_periodTime = periodTime;
	task -> m_context = _context;
	task -> m_magicNumber = MAGIC_NUMBER2;
	
return task;
}

/**********************CalculateNextRunTime***********************/

int CalculateNextRunTime(Task* _task, clockid_t _clockId)
{
	if(_task == NULL)
	{
		return FAIL;
	}
	
	_task -> m_nextRunTime = CalculateNextTime(_task -> m_periodTime, _clockId);
	
return SUCCESS;
}

/**********************RunTask***********************/

int RunTask(Task* _task, clockid_t _clockId)
{

	if(_task == NULL)
	{
		return FAIL;
	}
	
	sleepTime (_task -> m_nextRunTime, _clockId);
	 
return  _task -> m_functionPointer (_task -> m_context);
}

/**********************DestroyTask***********************/

void DestroyTask (void* _task)
{
	if(_task == NULL || ((Task*)_task) -> m_magicNumber != MAGIC_NUMBER2)
	{
		return;
	}
	
	free(_task);
}

/**********************NextRunTimeComparator***********************/

int NextRunTimeComparator(const void* _task1, const void* _task2)
{
timespec nextTime1;
timespec nextTime2;

	nextTime1 = ((Task*)_task1) -> m_nextRunTime;
	nextTime2 = ((Task*)_task2) -> m_nextRunTime;
		
	if(TimesDifference(nextTime1, nextTime2) < 0)
	{
		return 1;
	}
	
return 0;
}





