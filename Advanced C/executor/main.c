#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include "executor.h"

/**********************print1Sec***********************/

int print1Sec(void* _i)
{
	printf("\n1 sec!\n");
		
	if(*(int*)_i <  10)
	{		
		(*(int*)_i)++;
		return 0;
	}

return 1;
}

/**********************print3Sec***********************/

int print3Sec(void* _i)
{
	printf("\n3 sec!\n");
	
	if(*(int*)_i <  3)
	{	
		(*(int*)_i)++;
		return 0;
	}
	
return 1;
}

/**********************print6Sec***********************/

int print6Sec(void* _i)
{
	printf("\n6 sec!\n");
	
	if(*(int*)_i <  1)
	{		
		(*(int*)_i)++;
		return 0;
	}
	
return 1;
}

/**********************pause***********************/

int pause(void* _executor)
{
	printf("\nPause 5 sec! \n");
	PeriodicExecutorPause((PeriodicExecutor*) _executor);
	sleep(5);
	
return 1;
}


int main()
{
PeriodicExecutor* executor;
char name[] = "name";
int * i;
int * i2;
int * i3;
int x = 0;
int x2 = 0;
int x3 = 0;
i = &x;
i2 = &x2;
i3 = &x3;

/**********************PeriodicExecutorCreate***********************/

executor = PeriodicExecutorCreate(name,CLOCK_REALTIME);

/**********************PeriodicExecutorAdd***********************/

PeriodicExecutorAdd(executor,pause, executor, 8000);
PeriodicExecutorAdd(executor,print1Sec, i, 1000);
PeriodicExecutorAdd(executor,print3Sec, i2, 3000);
PeriodicExecutorAdd(executor,print6Sec, i3, 6000);

/**********************PeriodicExecutorRun***********************/

PeriodicExecutorRun(executor);
PeriodicExecutorRun(executor);

/**********************PeriodicExecutorDestroy***********************/

PeriodicExecutorDestroy(executor);
PeriodicExecutorDestroy(executor);
}
