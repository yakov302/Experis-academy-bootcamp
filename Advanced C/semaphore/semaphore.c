#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define N 100
#define TRUE 1
   
int item;
sem_t mutex;
sem_t empty;
sem_t full;


void* Producer(void* _i)
{
	while(TRUE)
	{
		sem_wait(&empty);
		sem_wait(&mutex);	
			item++;
			printf("%d, ", item);
		sem_post(&mutex);
		sem_post(&full);
	}
}

void* Consumer(void* _i)
{
	while(TRUE)
	{
		sem_wait(&full);
		sem_wait(&mutex);
			item--;
			printf("%d, ", item);
		sem_post(&mutex);
		sem_post(&empty);	
	}
}

int main()
{
pthread_t producer;
pthread_t consumer;

sem_init(&mutex,0,1);
sem_init(&empty,0,N);
sem_init(&full,0,0);

pthread_create(&consumer, NULL, Consumer, NULL);
pthread_create(&consumer, NULL, Consumer, NULL);
pthread_create(&producer, NULL, Producer, NULL);
pthread_create(&producer, NULL, Producer, NULL);


pthread_join(producer, NULL);
pthread_join(consumer, NULL);

sem_destroy(&mutex);
sem_destroy(&empty);
sem_destroy(&full);
}




































