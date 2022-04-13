#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "heap.h"

/***************structPerson****************/

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

/***************isLeftIdBiger****************/

int isLeftIdBiger(const void* _left, const void* _right)
{
int left;
int right;

	left = ((struct Person*) _left) -> m_id;
	right = ((struct Person*) _right) -> m_id;
	
	if(left > right)
	{
		return 1;
	}
return 0;
}

/***************isIdExist****************/

int isIdExist(const void*_elemnent,  void* _context)
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

/***************printPerson****************/

int printPerson (const void *_element, void* _context)
{
	if(_element == NULL)
	{
		return 0;
	}

	printf("id: %d\n",((struct Person*)_element) -> m_id);
	printf("name: %s\n",((struct Person*) _element) -> m_name);
	printf("age: %d\n\n",((struct Person*) _element) -> m_age);
	
return 1;
}


int main()
{
const void* item;
void* element;
Vector *vector;
size_t findId;
size_t size;
Heap* heap;
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

vector = VectorCreate (1, 1);

VectorAppend (vector, p1);
VectorAppend (vector, p2);
VectorAppend (vector, p3);

heap = HeapBuild(vector, isLeftIdBiger);

HeapInsert(heap, p4);
HeapInsert(heap, p5);

item = HeapPeak (heap);
printf("\nHeapPeek: %d\n", ((struct Person*) item) -> m_id);

element = HeapHxtract(heap);
printf("\nHeapHxtract: %d\n\n", ((struct Person*) element) -> m_id);
free(element);

HeapForEach(heap, printPerson, 0);

size = HeapSize(heap);
printf("\nsize: %ld\n", size);

id = 153;
findId = HeapForEach(heap, isIdExist, &id);
printf("\nHeapForEach, isIdExist - NO: %ld\n", findId);

id = 20;
findId = HeapForEach(heap, isIdExist, &id);
printf("\nHeapForEach, isIdExist - YES: %ld\n", findId);

HeapDestroy(&heap);
HeapDestroy(&heap);
VectorDestroy (&vector, ItemDestroy);
}

