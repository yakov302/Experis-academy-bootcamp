#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"
#define AEE_SIZE 10

/**************Search conditions functions***********/
struct Person
{
int m_id;
char m_name[128];
int m_age;
}; 


int IntBigToSmall(const void* _data1, const void* _data2)
{

	if(*(int*)_data1 < *(int*)_data2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int PersonById(const void* _data1, const void* _data2)
{

	if(((struct Person*)_data1) -> m_id < ((struct Person*)_data2) -> m_id)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int main()
{
int i;
int arr [AEE_SIZE];
struct Person person[5] = {{12,"Guy", 27},{34,"Tal", 21},{40,"Yossi",33},{32,"Moshe",22},{80,"Roni",25}};

	for (i = 0; i < AEE_SIZE ; i++)
	{
		arr[i] = rand()%1000;
	}
	
	for (i = 0; i < AEE_SIZE ; i++)
	{
	printf("%d\n", arr[i]);
	}
	printf("\n\n");
	
	GenBubble(arr, AEE_SIZE , sizeof(int), IntBigToSmall);
	
	for (i = 0; i < AEE_SIZE ; i++)
	{
	printf("%d\n", arr[i]);
	}
	printf("\n\n");
	
	for (i = 0; i < 5 ; i++)
	{
		printf("%d\n", person[i].m_id);
	}
	printf("\n\n");

	GenBubble(person, 5 , sizeof(struct Person), PersonById);


	for (i = 0; i < 5 ; i++)
	{
		printf("%d\n", person[i].m_id);
	}

}















