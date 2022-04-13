#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.set.h"

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
	free(_item);
}

/***************HashForId****************/

size_t HashForId(void* _data)
{
	if(_data == NULL)
	{
		return 0;
	}
	
return ((struct Person*) _data) -> m_id;
}

/***************EqualityId****************/

int EqualityId(void* _firstData, void* _secondData)
{
	if(_firstData == NULL || _secondData == NULL)
	{
		return 0;
	}
	
	if(((struct Person*)_firstData) -> m_id == ((struct Person*)_secondData) -> m_id)
	{
		return 1;
	}
	
return 0;
}

/***************PrintPerson****************/

void PrintPerson(void* _key)
{
	if( _key == NULL)
	{
		printf("NULL KEY!");
	}

	printf("id: %d\n",((struct Person*) _key) -> m_id);
	printf("name: %s\n",((struct Person*) _key) -> m_name);
	printf("age: %d\n\n",((struct Person*) _key) -> m_age);
}

int main()
{
Hash* hash;
void* data;
int found;

struct Person* p1;
struct Person* p2;
struct Person* p3;
struct Person* p4;
struct Person* p5;

p1 = (struct Person*)malloc(sizeof(struct Person)*1);		
p1 -> m_id = 30;
strcpy(p1 -> m_name, "yakov");
p1 -> m_age = 30;

p2 = (struct Person*)malloc(sizeof(struct Person)*1);		
p2 -> m_id = 50;
strcpy(p2 -> m_name, "dana");
p2 -> m_age = 15;

p3 = (struct Person*)malloc(sizeof(struct Person)*1);		
p3 -> m_id = 20;
strcpy(p3 -> m_name, "david");
p3 -> m_age = 17;

p4 = (struct Person*)malloc(sizeof(struct Person)*1);		
p4 -> m_id = 10;
strcpy(p4 -> m_name, "gal");
p4 -> m_age = 35;

p5 = (struct Person*)malloc(sizeof(struct Person)*1);		
p5 -> m_id = 25;
strcpy(p5 -> m_name, "yoni");
p5 -> m_age = 95;

/*************************HashCreate*****************************/

hash = HashCreate(5, HashForId, EqualityId);

/*************************HashInsert*****************************/

HashInsert(hash, p1);
HashInsert(hash, p2);
HashInsert(hash, p3);
HashInsert(hash, p4);
HashInsert(hash, p5);

/*************************HashPrint*****************************/

HashPrint(hash, PrintPerson);

/*************************HashRemove*****************************/

HashRemove(hash, p1,&data);
printf("\nHashRemove P1: %d\n",((struct Person*) data) -> m_id);

HashRemove(hash, p5,&data);
printf("\nHashRemove P5: %d\n",((struct Person*) data) -> m_id);

HashRemove(hash, p3,&data);
printf("\nHashRemove P3: %d\n",((struct Person*) data) -> m_id);

/*************************HashIsFound*****************************/

found = HashIsFound(hash, p4);
printf("\nHashIsFound - YES: %d\n", found);

found = HashIsFound(hash, p3);
printf("\nHashIsFound - NO: %d\n", found);

/*************************HashNumOfItem*****************************/

printf("\nNumOfItem: %ld\n", HashNumOfItem(hash));

/*************************HashCapacity*****************************/

printf("\nHashCapacity: %ld\n", HashCapacity(hash));

/*************************HashMaxEeHash*****************************/

printf("\nHashMaxEeHash: %ld\n", HashMaxEeHash(hash));

/**********************HashAverageRehashes**************************/

printf("\nHashAverageRehashes: %.2f\n",HashAverageRehashes(hash));

/*************************HashDestroy*****************************/

HashDestroy(&hash, ItemDestroy);
HashDestroy(&hash, ItemDestroy);
}
