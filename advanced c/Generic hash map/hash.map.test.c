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
p1 -> m_age = 56;
rank1 = (void*)malloc(sizeof(void*)*1);


p2 = (struct Person*)malloc(sizeof(struct Person)*1);		
p2 -> m_id = 50;
strcpy(p2 -> m_name, "dana");
p2 -> m_age = 15;
rank2 = (void*)malloc(sizeof(void*)*1);


p3 = (struct Person*)malloc(sizeof(struct Person)*1);		
p3 -> m_id = 50;
strcpy(p3 -> m_name, "david");
p3 -> m_age = 17;
rank3 = (void*)malloc(sizeof(void*)*1);


p4 = (struct Person*)malloc(sizeof(struct Person)*1);		
p4 -> m_id = 8;
strcpy(p4 -> m_name, "gal");
p4 -> m_age = 35;
rank4 = (void*)malloc(sizeof(void*)*1);


p5 = (struct Person*)malloc(sizeof(struct Person)*1);		
p5 -> m_id = 15;
strcpy(p5 -> m_name, "yoni");
p5 -> m_age = 95;
rank5 = (void*)malloc(sizeof(void*)*1);


printf("\n");
printf("------------HashMapCreate test-------------\n");
hashMap = HashMapCreate(0 , HashForId , EqualityId);
if(hashMap == NULL){printf("HashMapCreate test1 - PASS!\n");}
else{printf("HashMapCreate test1 - FAIL!\n");}
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);

hashMap = HashMapCreate(20 , NULL , EqualityId);
if(hashMap == NULL){printf("HashMapCreate test2 - PASS!\n");}
else{printf("HashMapCreate test2 - FAIL!\n");}
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);

hashMap = HashMapCreate(20 , HashForId , NULL);
if(hashMap == NULL){printf("HashMapCreate test3 - PASS!\n");}
else{printf("HashMapCreate test3 - FAIL!\n");}
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);

hashMap = HashMapCreate(20 , HashForId , EqualityId);
if(GetCapasity(hashMap) == 23){printf("HashMapCreate test4 - PASS!\n");}
else{printf("HashMapCreate test4 - FAIL!\n");}
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);

printf("\n");
printf("------------HashMapDestroy test-------------\n");
hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);
if(hashMap == NULL){printf("HashMapDestroy test1 - PASS!\n");}


printf("\n");
printf("------------HashMapInsert test-------------\n");
hashMap = HashMapCreate(20 , HashForId , EqualityId);
if(HashMapInsert(NULL, p1, rank1) == MAP_UNINITIALIZED_ERROR)
{printf("HashMapInsert test1 - PASS!\n");}
else{printf("HashMapInsert test1 - FAIL!\n");}
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);

hashMap = HashMapCreate(20 , HashForId , EqualityId);
if(HashMapInsert(hashMap, NULL, rank1) == MAP_KEY_NULL_ERROR)
{printf("HashMapInsert test2 - PASS!\n");}
else{printf("HashMapInsert test2 - FAIL!\n");}
HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p1, rank1);
if(FindIndex(hashMap, p1) == 7){printf("HashMapInsert test3 - PASS!\n");}
else{printf("HashMapInsert test3 - FAIL!\n");}


hashMap = HashMapCreate(20 , HashForId , EqualityId);
if(HashMapInsert(hashMap, p2, rank2) == MAP_SUCCESS )
{printf("HashMapInsert test4 - PASS!\n");}
else{printf("HashMapInsert test4 - FAIL!\n");}


hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p2, rank2);
if(HashMapInsert(hashMap, p3, rank3) == MAP_KEY_DUPLICATE_ERROR)
{printf("HashMapInsert test5 - PASS!\n");}
else{printf("HashMapInsert test5 - FAIL!\n");}

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p1, rank2);
HashMapInsert(hashMap, p3, rank2);
HashMapInsert(hashMap, p4, rank2);
if(HashMapSize(hashMap) == 3)
{printf("HashMapInsert test6 - PASS!\n");}
else{printf("HashMapInsert test6 - FAIL!\n");}

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p1, rank2);
HashMapInsert(hashMap, p2, rank2);
HashMapInsert(hashMap, p3, rank2);
HashMapInsert(hashMap, p4, rank2);
if(HashMapSize(hashMap) == 3)
{printf("HashMapInsert test7 - PASS!\n");}
else{printf("HashMapInsert test7 - FAIL!\n");}

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p1, rank1);
if(GetKey(hashMap, 7, p1) == p1)
{printf("HashMapInsert test8 - PASS!\n");}
else{printf("HashMapInsert test8 - FAIL!\n");}

hashMap = HashMapCreate(6 , HashForId , EqualityId);
if(HashMapInsert(hashMap, p4, rank4) == MAP_SUCCESS && HashMapInsert(hashMap, p5, rank5) == MAP_SUCCESS)
{printf("HashMapInsert test9 - PASS!\n");}
else{printf("HashMapInsert test9 - FAIL!\n");}
if(GetKey(hashMap, 1, p5) == p5 && GetKey(hashMap, 1, p4) == p4)
{printf("HashMapInsert test10 - PASS!\n");}
else{printf("HashMapInsert test10 - FAIL!\n");}

printf("\n");
printf("------------HashMapRemove test-------------\n");
hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
if(HashMapRemove(NULL, p4, pKey1, pValue1) == MAP_UNINITIALIZED_ERROR)
{printf("HashMapRemove test1 - PASS!\n");}
else{printf("HashMapRemove test1 - FAIL!\n");}

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
if(HashMapRemove(hashMap, NULL, pKey1, pValue1) == MAP_KEY_NULL_ERROR)
{printf("HashMapRemove test2 - PASS!\n");}
else{printf("HashMapRemove test2 - FAIL!\n");}

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
if(HashMapRemove(hashMap, p4, NULL, pValue1) == MAP_NULL_INPUT_ERROR)
{printf("HashMapRemove test3 - PASS!\n");}
else{printf("HashMapRemove test3 - FAIL!\n");}

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
if(HashMapRemove(hashMap, p4, pKey1, NULL) == MAP_NULL_INPUT_ERROR)
{printf("HashMapRemove test4 - PASS!\n");}
else{printf("HashMapRemove test4 - FAIL!\n");}

hashMap = HashMapCreate(6 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
if(FindIndex(hashMap, p4) == 1)
{printf("HashMapRemove test6 - PASS!\n");}
else{printf("HashMapRemove test6 - FAIL!\n");}

hashMap = HashMapCreate(6 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapRemove(hashMap, p4, &pKey1, &pValue1);
if(GetKey(hashMap, 1, p4) == NULL)
{printf("HashMapRemove test7 - PASS!\n");}
else{printf("HashMapRemove test7 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(6 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapRemove(hashMap, p4, &pKey1, &pValue1);
if(pKey1 == p4 && pValue1 == rank4)
{printf("HashMapRemove test8 - PASS!\n");}
else{printf("HashMapRemove test8 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(6 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);
HashMapRemove(hashMap, p4, &pKey1, &pValue1);
if(GetKey(hashMap, 1, p4) == NULL && GetKey(hashMap, 1, p5) == p5)
{printf("HashMapRemove test9 - PASS!\n");}
else{printf("HashMapRemove test9 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(6 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapRemove(hashMap, p4, &pKey1, &pValue1);
if(HashMapRemove(hashMap, p4, &pKey1, &pValue1) == MAP_KEY_NOT_FOUND_ERROR)
{printf("HashMapRemove test10 - PASS!\n");}
else{printf("HashMapRemove test10 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(6 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);
if(HashMapSize(hashMap) == 2)
{printf("HashMapRemove test11 - PASS!\n");}
else{printf("HashMapRemove test11 - FAIL!\n");}
HashMapRemove(hashMap, p4, &pKey1, &pValue1);
if(HashMapSize(hashMap) == 1)
{printf("HashMapRemove test12 - PASS!\n");}
else{printf("HashMapRemove test12 - FAIL!\n");}
HashMapRemove(hashMap, p5, &pKey1, &pValue1);
if(HashMapSize(hashMap) == 0)
{printf("HashMapRemove test13 - PASS!\n");}
else{printf("HashMapRemove test13 - FAIL!\n");}
free(hashMap);

printf("\n");
printf("------------HashMapFind test-------------\n");
hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);
if(HashMapFind(NULL, p1, pValue1) == MAP_UNINITIALIZED_ERROR)
{printf("HashMapFind test1 - PASS!\n");}
else{printf("HashMapFind test1 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);
if(HashMapFind(hashMap, NULL, pValue1) == MAP_KEY_NULL_ERROR)
{printf("HashMapFind test2 - PASS!\n");}
else{printf("HashMapFind test2 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);
if(HashMapFind(hashMap,p4, NULL) == MAP_NULL_INPUT_ERROR)
{printf("HashMapFind test3 - PASS!\n");}
else{printf("HashMapFind test3 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);
if(HashMapFind(hashMap,p1, pValue1) == MAP_KEY_NOT_FOUND_ERROR)
{printf("HashMapFind test4 - PASS!\n");}
else{printf("HashMapFind test4 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);
if(HashMapFind(hashMap,p4, pValue1) == MAP_SUCCESS)
{printf("HashMapFind test5 - PASS!\n");}
else{printf("HashMapFind test5 - FAIL!\n");}
free(hashMap);

hashMap = HashMapCreate(20 , HashForId , EqualityId);
HashMapInsert(hashMap, p4, rank4);
HashMapInsert(hashMap, p5, rank5);
HashMapFind(hashMap,p4, &pValue4);
if(pValue4 == rank4)
{printf("HashMapFind test6 - PASS!\n");}
else{printf("HashMapFind test6 - FAIL!\n");}








HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);



}
