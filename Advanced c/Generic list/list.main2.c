#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
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
	if(_item == NULL)
	{
		return;
	}
	free(_item);
	_item = NULL;
}

int main()
{
size_t size;
List* list;
void* item;
void* item2;
void* item3;
void* item4;
void* item5;
void* item6;
void* data;
int Equals;

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

list = ListCreate();

item = ListItrInsertBefore(ListItrBegin(list), p1);
item2 = ListItrInsertBefore(ListItrBegin(list), p2);
item3 = ListItrInsertBefore(ListItrBegin(list), p3);
item4 = ListItrInsertBefore(ListItrBegin(list), p4);
item5 = ListItrInsertBefore(ListItrBegin(list), p5);

ListItrRemove(item);
ListItrRemove(item5);


ListPrint(list);

data = ListItrGet(item2);
printf("\nListItrGet - p2: %d\n",((struct Person*) data) -> m_id);


data = ListItrGet(ListItrNext(item4));
printf("\nListItrNext - p4: %d\n",((struct Person*) data) -> m_id);


data = ListItrGet(ListItrPrev(item2));
printf("\nListItrPrev - p2: %d\n",((struct Person*) data) -> m_id);

item6 = ListItrSet(item3, p5);
data = ListItrGet(item3);
printf("\nListItrSet - Old data p3: %d\n",((struct Person*) item6) -> m_id);
printf("\nListItrSet - New data p3: %d\n",((struct Person*) data) -> m_id);

Equals = ListItrEquals(item2, item2);
printf("\nEquals - YES: %d\n", Equals);

Equals = ListItrEquals(item2, item3);
printf("\nEquals - NO: %d\n", Equals);


item = ListItrEnd(list);
printf("\nListItrEnd: %p\n", item);



ListDestroy(&list, ItemDestroy);
ListDestroy(&list, ItemDestroy);
}
