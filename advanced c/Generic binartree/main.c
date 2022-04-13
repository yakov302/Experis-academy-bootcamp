#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "gen.binartree.h"

/***************struct Person****************/
struct Person
{
int m_id;
char m_name[128];
int m_age;
}; 

/***************ComparatorForId****************/

int ComparatorForId (void* _left, void* _right)
{
	if(((struct Person*)_left) -> m_id == ((struct Person*)_right) -> m_id)
	{
		return 0;
	}
	
	if(((struct Person*)_left) -> m_id > ((struct Person*)_right) -> m_id)
	{
		return 1;
	}
return -1;
}

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
BSTree* tree;
BSTree* tree2;
BSTree* begin;
BSTree* nextP1;
BSTree* nextP2;
BSTree* nextP3;
BSTree* nextP4;
BSTree* nextP5;
BSTree* preve;
void* data;
void* remove;
int compare;

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

/*************************BSTreeCreate****************************/

tree =  BSTreeCreate(ComparatorForId);

/*************************BSTreeInsert****************************/

BSTreeInsert(tree,p1);
BSTreeInsert(tree,p2);
BSTreeInsert(tree,p3);
BSTreeInsert(tree,p4);
BSTreeInsert(tree,p5);

TreePrint(tree);

/*************************BSTreeItrEnd****************************/

BSTreeItrEnd(tree);

/*************************BSTreeItrBegin****************************/

begin = BSTreeItrBegin(tree);
data = BSTreeItrGet(begin);
printf("\nbegin: %d\n",((struct Person*) data) -> m_id);

/*************************BSTreeItrEquals****************************/

compare = BSTreeItrEquals(BSTreeItrEnd(tree), BSTreeItrBegin(tree));
printf("\ncompare - NO! %d\n", compare);

tree2 =  BSTreeCreate(ComparatorForId);
compare = BSTreeItrEquals(BSTreeItrBegin(tree2), BSTreeItrEnd(tree2));
printf("\ncompare - YES! %d\n", compare);
BSTreeDestroy(&tree2, NULL);

/*************************BSTreeItrNext****************************/

nextP1 = BSTreeItrNext(BSTreeItrBegin(tree));
data = BSTreeItrGet(nextP1);
printf("\nnext P1: %d\n",((struct Person*) data) -> m_id);

nextP2 = BSTreeItrNext(nextP1);
data = BSTreeItrGet(nextP2);
printf("\nnext P2: %d\n",((struct Person*) data) -> m_id);

nextP3 = BSTreeItrNext(nextP2);
data = BSTreeItrGet(nextP3);
printf("\nnext P3: %d\n",((struct Person*) data) -> m_id);

nextP4 = BSTreeItrNext(nextP3);
data = BSTreeItrGet(nextP4);
printf("\nnext P4: %d\n",((struct Person*) data) -> m_id);

nextP5 = BSTreeItrNext(nextP4);
compare = BSTreeItrEquals(BSTreeItrEnd(tree), nextP5);
printf("\nnext P5: %d\n", compare);

/*************************BSTreeItrPrev****************************/

preve = BSTreeItrPrev(nextP5);
data = BSTreeItrGet(preve);
printf("\nPrev P5: %d\n",((struct Person*) data) -> m_id);

preve = BSTreeItrPrev(nextP4);
data = BSTreeItrGet(preve);
printf("\nPrev P4: %d\n",((struct Person*) data) -> m_id);

preve = BSTreeItrPrev(nextP3);
data = BSTreeItrGet(preve);
printf("\nPrev P3: %d\n",((struct Person*) data) -> m_id);

preve = BSTreeItrPrev(nextP2);
data = BSTreeItrGet(preve);
printf("\nPrev P2: %d\n",((struct Person*) data) -> m_id);

preve = BSTreeItrPrev(nextP1);
data = BSTreeItrGet(preve);
printf("\nPrev P1: %d\n",((struct Person*) data) -> m_id);

compare = BSTreeItrEquals(BSTreeItrBegin(tree), BSTreeItrPrev(BSTreeItrBegin(tree)));
printf("\nPrev Begin: %d\n", compare);

/*************************BSTreeItrRemove****************************/

remove = BSTreeItrRemove(nextP4);
printf("\nremove: %d\n\n",((struct Person*) remove) -> m_id);
/*free(nextP4);*/
TreePrint(tree);

/*************************BSTreeDestroy****************************/

BSTreeDestroy(&tree, ItemDestroy);
BSTreeDestroy(&tree, ItemDestroy);
}
