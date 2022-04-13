#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.map.h"
#include "gen.list.h"

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


int main()
{
HashMap* hashMap;

void* pKey1;
void* pValue1;
void* pKey4;
void* pValue4;

void* pValue2;

struct Person* p1;
struct Person* p2;
struct Person* p3;
struct Person* p4;
struct Person* p5;
void* rank1;
void* rank2;
void* rank3;
void* rank4;
void* rank5;

p1 = (struct Person*)malloc(sizeof(struct Person)*1);		
p1 -> m_id = 30;
strcpy(p1 -> m_name, "yakov");
p1 -> m_age = 30;
rank1 = (void*)malloc(sizeof(void*)*1);


p2 = (struct Person*)malloc(sizeof(struct Person)*1);		
p2 -> m_id = 50;
strcpy(p2 -> m_name, "dana");
p2 -> m_age = 15;
rank2 = (void*)malloc(sizeof(void*)*1);


p3 = (struct Person*)malloc(sizeof(struct Person)*1);		
p3 -> m_id = 20;
strcpy(p3 -> m_name, "david");
p3 -> m_age = 17;
rank3 = (void*)malloc(sizeof(void*)*1);


p4 = (struct Person*)malloc(sizeof(struct Person)*1);		
p4 -> m_id = 10;
strcpy(p4 -> m_name, "gal");
p4 -> m_age = 35;
rank4 = (void*)malloc(sizeof(void*)*1);


p5 = (struct Person*)malloc(sizeof(struct Person)*1);		
p5 -> m_id = 25;
strcpy(p5 -> m_name, "yoni");
p5 -> m_age = 95;
rank5 = (void*)malloc(sizeof(void*)*1);


hashMap = HashMapCreate(20, HashForId, EqualityId);

HashMapInsert(hashMap, p1, rank1);
HashMapInsert(hashMap, p2, rank2);
HashMapInsert(hashMap, p3, rank3);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);

HashMapRemove(hashMap, p1 , &pKey1, &pValue1);
HashMapRemove(hashMap, p4 , &pKey4, &pValue4);
free(p1);
free(p4);
free(rank1);
free(rank4);

HashMapFind(hashMap, p2, &pValue2);

printf("HashMapSize: %ld", HashMapSize(hashMap));

HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);

}
