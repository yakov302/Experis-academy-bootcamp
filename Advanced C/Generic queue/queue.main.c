#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/***************struct Person****************/

struct Person
{
int m_id;
char m_name[128];
int m_age;
}; 

/***************ItemDestroy****************/

void ItemDestroy(void* _item)
{
	if(_item == NULL)
	{
		return;
	}
	free(_item);
	_item = NULL;
}

/***************printPerson****************/

int printPerson (const void*_elemnent, void* _context)
{
	if(_elemnent == NULL)
	{
		return 0;
	}
	
	printf("id: %d\n",((struct Person*) _elemnent) -> m_id);
	printf("name: %s\n",((struct Person*) _elemnent) -> m_name);
	printf("age: %d\n\n",((struct Person*) _elemnent) -> m_age);
	
return 1;
}

/***************isIdExist****************/

int isIdExist(const void*_elemnent, void* _context)
{
	if( _elemnent == NULL || _context == NULL)
	{
		return;
	}
	
	if(((struct Person*) _elemnent) -> m_id == *(int*) _context)
	{
		return 0;
	}
return 1;
}

main(void)
{
int IsEmpty;
int findId;
Queue *ptr;
void* item;
int id;

struct Person* p1;
struct Person* p2;
struct Person* p3;
struct Person* p4;
struct Person* p5;

p1 = (struct Person*)malloc(sizeof(struct Person)*1);		
p1 -> m_id = 50;
strcpy(p1 -> m_name, "yakov");
p1 -> m_age = 30;

p2 = (struct Person*)malloc(sizeof(struct Person)*1);		
p2 -> m_id = 20;
strcpy(p2 -> m_name, "dana");
p2 -> m_age = 15;

p3 = (struct Person*)malloc(sizeof(struct Person)*1);		
p3 -> m_id = 16;
strcpy(p3 -> m_name, "david");
p3 -> m_age = 17;

p4 = (struct Person*)malloc(sizeof(struct Person)*1);		
p4 -> m_id = 80;
strcpy(p4 -> m_name, "gal");
p4 -> m_age = 35;

p5 = (struct Person*)malloc(sizeof(struct Person)*1);		
p5 -> m_id = 28;
strcpy(p5 -> m_name, "yoni");
p5 -> m_age = 95;

ptr = QueueCreate(5);

IsEmpty = QueueIsEmpty(ptr);
printf("\nIsEmpty - YES: %d\n", IsEmpty);

QueueInsert(ptr, p1);
QueueInsert(ptr, p2);
QueueInsert(ptr, p3);
QueueInsert(ptr, p4);
QueueInsert(ptr, p5);

QueueRemove(ptr, &item);
free(item);
QueueRemove(ptr, &item);
free(item);


IsEmpty = QueueIsEmpty(ptr);
printf("\nIsEmpty - NO: %d\n\n", IsEmpty);

QueueForEach(ptr, printPerson , 0);

id = 126;
findId = QueueForEach(ptr, isIdExist,  &id);
printf("\nQueueForEach, isIdExist - NO : %d\n", findId);

id = 80;
findId = QueueForEach(ptr, isIdExist,  &id);
printf("\nQueueForEach, isIdExist - YES: %d\n", findId);

QueueDestroy(&ptr , ItemDestroy);
QueueDestroy(&ptr , ItemDestroy);
}
