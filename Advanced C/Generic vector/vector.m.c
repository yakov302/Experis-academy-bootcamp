#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#define ARR_SIZE 5

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

int printPerson (void*_elemnent, size_t _index, void* _context)
{
	if(_elemnent == NULL)
	{
		return 0;
	}
	printf("Person %ld:\n",_index);
	printf("id: %d\n",((struct Person*) _elemnent) -> m_id);
	printf("name: %s\n",((struct Person*) _elemnent) -> m_name);
	printf("age: %d\n\n",((struct Person*) _elemnent) -> m_age);
	
return 1;
}

/***************isIdExist****************/

int isIdExist(void*_elemnent, size_t _index, void* _context)
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

/***************FindMaxId****************/

int FindMaxId (void*_elemnent, size_t _index, void* _context)
{
	if(((struct Person*) _elemnent) -> m_id > *(int*)_context)
	{
		*(int*) _context = ((struct Person*) _elemnent) -> m_id;
	}
return 1;	
}

int main()
{
Vector *ptr;
int findId;
void* item;
int* maxId;
int id;
int i;


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

ptr = VectorCreate (1, 1);

VectorAppend (ptr, p1);
VectorAppend (ptr, p2);
VectorAppend (ptr, p3);
VectorAppend (ptr, p4);
VectorAppend (ptr, p5);

VectorRemove(ptr, &item);
free(item);
VectorRemove(ptr, &item);
free(item);

VectorForEach(ptr, printPerson, 0);

VectorGet(ptr, 2,  &item);
printf("\nVectorGet i = 2 name: %s\n\n",((struct Person*) item) -> m_name);

/*VectorSet(ptr, 0, (void*) p4);
free(p1);*/

VectorForEach(ptr, printPerson, 0);

VectorSize(ptr);
printf("\nVectorSize: %ld\n", VectorSize(ptr));
printf("\nVectorCapacity: %ld\n", VectorCapacity(ptr));

id = 126;
findId = VectorForEach(ptr, isIdExist,  &id);
printf("\nVectorForEach, isIdExist - NO : %d\n", findId);

id = 16;
findId = VectorForEach(ptr, isIdExist,  &id);
printf("\nVectorForEach, isIdExist - YES: %d\n", findId);

VectorForEach(ptr, FindMaxId, maxId);
printf("\nmax id: %d\n", *maxId);

VectorDestroy (&ptr, ItemDestroy);
VectorDestroy (&ptr, ItemDestroy);
}


