#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>  
#include <sys/types.h>
#include "executor.h"
#include "heap.h"
#include "task.h"
#include "time.h"
#define MAGIC_NUMBER 8123475
#define TRUE 1
#define ON 1
#define OFF 0
#define SIZE 20
#define INCREASE_SIZE 5
#define FAIL 0
#define SUCCESS 1

/************************structPeriodicExecutor*********************/

struct PeriodicExecutor
{
	Vector* m_vector;
	Heap* m_heap;
	clockid_t m_clockId;
	int m_numOfTask;
	int m_numOfCycles;
	char m_pause;
	char m_name[30];
	int m_magicNumber;
};

/**********************Function Signatures***********************/

void static SetTasksNextTimeRun (Vector* _vector, clockid_t _clockId);

/**********************PeriodicExecutorCreate***********************/

PeriodicExecutor* PeriodicExecutorCreate(const char* _name, clockid_t _clockId)
{
PeriodicExecutor* executor;

	if((executor = ((PeriodicExecutor*)malloc(sizeof(PeriodicExecutor)))) == NULL)
	{
		return NULL;
	}
	
	if((executor -> m_vector = VectorCreate (SIZE, INCREASE_SIZE)) == NULL)
	{
		free(executor);
		return NULL;
	}
	
	executor -> m_heap = NULL;
	executor -> m_clockId = _clockId;
	executor -> m_numOfTask = 0;
	executor -> m_numOfCycles = 0;
	executor -> m_pause = 0;
	strcpy(executor -> m_name, _name);
	executor -> m_magicNumber = MAGIC_NUMBER;

return executor;
}

/**********************PeriodicExecutorDestroy***********************/

void PeriodicExecutorDestroy(PeriodicExecutor* _executor)
{

	if(_executor == NULL || _executor -> m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	
	_executor -> m_magicNumber = 0;
	VectorDestroy (&_executor -> m_vector, DestroyTask);
	free(_executor);
}

/**********************PeriodicExecutorAdd***********************/

int PeriodicExecutorAdd(PeriodicExecutor* _executor, taskFunction _func, void* _context, size_t _periodTime)
{
Task* task;

	if(_executor == NULL || _func == NULL)
	{
		return FAIL;
	}
	
	if((task = CreateTask (_func, _context, _periodTime)) == NULL)
	{
		return FAIL;
	}
	
	if(VectorAppend (_executor -> m_vector , task) != VECTOR_SUCCESS)
	{
		return FAIL;
	}
	
	_executor -> m_numOfTask++;

return SUCCESS;
}

/**********************PeriodicExecutorRun***********************/

size_t PeriodicExecutorRun(PeriodicExecutor* _executor)
{
Task* task;
int taskStatus;

	if(_executor == NULL)
	{
		return FAIL;
	}
	
	_executor -> m_pause = OFF;
	
	SetTasksNextTimeRun (_executor -> m_vector, _executor -> m_clockId);
	
   	if((_executor -> m_heap = HeapBuild(_executor -> m_vector, NextRunTimeComparator)) == NULL)
   	{
   		return FAIL;
   	}  	
   	
	while(TRUE)
	{				
		if(_executor -> m_pause == ON)
		{
			break;
		}
		
		if((task = HeapHxtract (_executor -> m_heap)) == NULL)  /*if Heap is empty*/
		{
			break;
		}
		
		taskStatus = RunTask(task, _executor -> m_clockId);
		if(taskStatus != 0)
		{
			DestroyTask (task);
			_executor -> m_numOfTask--;
		}
		else
		{
			CalculateNextRunTime(task,_executor -> m_clockId);			
			HeapInsert(_executor -> m_heap, task);
		}
		
		_executor ->  m_numOfCycles++;			
	}

	HeapDestroy(&_executor -> m_heap);

return _executor ->  m_numOfCycles;
}

void static SetTasksNextTimeRun (Vector* _vector, clockid_t _clockId)
{
size_t vectorSize;
Task* task;
size_t i;

	vectorSize = VectorSize (_vector);
   	for(i = 0; i < vectorSize; i++)
   	{
   		VectorGet(_vector, i, (void*) &task);		
		CalculateNextRunTime(task, _clockId);	
   	}
}

/**********************PeriodicExecutorPause***********************/

size_t PeriodicExecutorPause(PeriodicExecutor* _executor)
{
	if(_executor == NULL)
	{
		return FAIL;
	}

	_executor -> m_pause = ON;

return _executor -> m_numOfTask;
}







