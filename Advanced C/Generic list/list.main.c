#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"



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

ListPushHead(list, p1);
ListPushHead(list, p2);
ListPushHead(list, p3);

ListPushTail(list, p4);
ListPushTail(list, p5);

ListPrint(list);

ListPopHead(list, &item);
printf("\nListPopHead: %d\n", ((struct Person*) item) -> m_id);
free(item);

printf("\n");
ListPrint(list);

ListPopTail(list, &item);
printf("\nListPopTail: %d\n", ((struct Person*) item) -> m_id);
free(item);

printf("\n");
ListPrint(list);

size = ListSize(list);
printf("\nsize: %ld\n", size);

ListDestroy(&list, ItemDestroy);
ListDestroy(&list, ItemDestroy);
}
