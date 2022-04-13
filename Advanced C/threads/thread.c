#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define SIZE 1000
#define NUM_OF_THREADS 5

int globalIndex = 0;

void *printFunc(void* tid)
{
int index = 0;
int i;

	
	for(i = 0; i < 1000; i++)
	{	
		printf("thread no. %d  ->   local: %-4d   global: %-4d\n", *(int*) tid, index , globalIndex);
		index++;
		globalIndex++;	
	}
	pthread_exit(NULL);
}

int main()
{
pthread_t threads[NUM_OF_THREADS];
int status;
int i;
int arr[] = {0,1,2,3,4,5};

	for(i = 0; i < NUM_OF_THREADS; i++)
	{
		status = pthread_create(&threads[i], NULL, printFunc, &arr[i]);
		if(status < 0)
		{
			printf("thread faild!");
			return;
		}
	}
	
	for(i = 0; i < NUM_OF_THREADS; i++)
	{
		pthread_join(threads[i], NULL);	
	}


}




