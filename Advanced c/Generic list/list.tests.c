#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "gen.list.h"


/***********************ListItrBegin**********************/
ListItrBeginNULL(void)
{
	if(ListItrBegin(NULL) == NULL)
	{
		printf("ListItrBegin1 - PASS!\n");
	}
	else
	{
		printf("ListItrBegin1 - FAILS!\n");
	}
}

ListItrBeginIsWork(void)
{
List* list = ListCreate();

	if(ListItrBegin(list) == ListItrEnd(list))
	{
		printf("ListItrBegin2 - PASS!\n");
	}
	else
	{
		printf("ListItrBegin2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

/***********************ListItrEnd**********************/

ListItrEndNULL(void)
{
	if(ListItrEnd(NULL) == NULL)
	{
		printf("ListItrEnd1 - PASS!\n");
	}
	else
	{
		printf("ListItrEnd1 - FAILS!\n");
	}
}

ListItrEndIsWork(void)
{
List* list = ListCreate();

	if(ListItrBegin(list) == ListItrEnd(list))
	{
		printf("ListItrEnd2 - PASS!\n");
	}
	else
	{
		printf("ListItrEnd2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

/***********************ListItrEquals**********************/


ListItrEqualsNULL(void)
{
List* list = ListCreate();

	if(ListItrEquals(NULL, ListItrBegin(list)) == -1  && ListItrEquals(ListItrBegin(list), NULL) == -1)
	{
		printf("ListItrEquals1 - PASS!\n");
	}
	else
	{
		printf("ListItrEquals1 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

ListItrEqualEqual(void)
{
List* list = ListCreate();

	if(ListItrEquals( ListItrBegin(list), ListItrEnd(list)) == 1)
	{
		printf("ListItrEquals2 - PASS!\n");
	}
	else
	{
		printf("ListItrEquals2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

ListItrEqualNotEqual(void)
{
List* list = ListCreate();
int* ptr;
int x = 5;
ptr = &x;
ListPushHead(list, ptr);


	if(ListItrEquals( ListItrBegin(list), ListItrEnd(list)) == 0)
	{
		printf("ListItrEquals3 - PASS!\n");
	}
	else
	{
		printf("ListItrEquals3 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

/***********************ListItrNext**********************/

ListItrNextNULL(void)
{
	if(ListItrNext(NULL) == NULL)
	{
		printf("ListItrNext1 - PASS!\n");
	}
	else
	{
		printf("ListItrNext1 - FAILS!\n");
	}
}

ListItrNextIsWork(void)
{
List* list = ListCreate();
int* ptr;
int x = 5;
ptr = &x;
ListPushHead(list, ptr);


	if(ListItrEquals( ListItrNext(ListItrBegin(list)), ListItrEnd(list)) == 1)
	{
		printf("ListItrNext2 - PASS!\n");
	}
	else
	{
		printf("ListItrNext2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

/***********************ListItrPrev**********************/

ListItrPrevNULL(void)
{
	if(ListItrPrev(NULL) == NULL)
	{
		printf("ListItrPrev1 - PASS!\n");
	}
	else
	{
		printf("ListItrPrev1 - FAILS!\n");
	}
}

ListItrPrevIsWork(void)
{
List* list = ListCreate();
int* ptr;
int x = 5;
ptr = &x;
ListPushHead(list, ptr);


	if(ListItrEquals( ListItrPrev(ListItrEnd(list)),ListItrBegin(list)) == 1)
	{
		printf("ListItrPrev2 - PASS!\n");
	}
	else
	{
		printf("ListItrPrev2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

ListItrPrevIsWork2(void)
{
List* list = ListCreate();
int* ptr;
int* ptr2;
void* old;
int x = 5;
int y = 3;
ptr = &x;
ptr2 = &y;
ListPushHead(list, ptr);
ListPushHead(list, ptr2);


	if( ListItrBegin(list) == ListItrPrev(ListItrBegin(list)))
	{
		printf("ListItrPrev3 - PASS!\n");
	}
	else
	{
		printf("ListItrPrev3 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

/***********************ListItrGet**********************/

ListItrGetNULL(void)
{
List* list = ListCreate();
	if(ListItrGet(NULL) == NULL && ListItrGet(ListItrEnd(list)) == NULL)
	{
		printf("ListItrGet1 - PASS!\n");
	}
	else
	{
		printf("ListItrGet1 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

ListItrGetNULL2(void)
{
List* list = ListCreate();
	if(ListItrGet(ListItrEnd(list)) == NULL)
	{
		printf("ListItrGet2 - PASS!\n");
	}
	else
	{
		printf("ListItrGet2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

ListItrGetIsWork(void)
{
List* list = ListCreate();
int* ptr;
int x = 5;
ptr = &x;
ListPushHead(list, ptr);


	if(ListItrEquals(ListItrGet(ListItrBegin(list)), ptr) == 1)
	{
		printf("ListItrGet3 - PASS!\n");
	}
	else
	{
		printf("ListItrGet3 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

/***********************ListItrSet**********************/

ListItrSetNULL(void)
{
List* list = ListCreate();
int x = 5;
void* ptr = &x;

	if(ListItrSet(NULL, ptr) == NULL && ListItrSet(ptr, NULL) == NULL && ListItrSet(ListItrEnd(list), ptr) == NULL)
	{
		printf("ListItrSet1 - PASS!\n");
	}
	else
	{
		printf("ListItrSet1 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

ListItrSetIsWork(void)
{
List* list = ListCreate();
int* ptr;
int* ptr2;
void* old;
int x = 5;
int y = 3;
ptr = &x;
ptr2 = &y;
ListPushHead(list, ptr);
old = ListItrSet(ListItrBegin(list), ptr2);


	if(old == ptr && ListItrGet(ListItrBegin(list)) == ptr2 )
	{
		printf("ListItrSet2 - PASS!\n");
	}
	else
	{
		printf("ListItrSet2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

/***********************ListItrInsertBefore**********************/

ListItrInsertBeforeNULL(void)
{
int x = 5;
void* ptr = &x;

	if(ListItrInsertBefore(NULL, ptr) == NULL && ListItrInsertBefore(ptr, NULL) == NULL)
	{
		printf("ListItrInsertBefore1 - PASS!\n");
	}
	else
	{
		printf("ListItrInsertBefore1 - FAILS!\n");
	}
}

ListItrInsertBeforeIsWork(void)
{
List* list = ListCreate();
int* ptr;
int* ptr2;
void* old;
int x = 5;
int y = 3;
ptr = &x;
ptr2 = &y;
ListPushHead(list, ptr);
ListItrInsertBefore(ListItrBegin(list), ptr2);


	if(ListItrGet(ListItrBegin(list)) == ptr2 && ListItrGet(ListItrNext( ListItrBegin(list))) == ptr)
	{
		printf("ListItrInsertBefore2 - PASS!\n");
	}
	else
	{
		printf("ListItrInsertBefore2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

/***********************ListItrRemove**********************/

ListItrRemoveNULL(void)
{
List* list = ListCreate();
	if(ListItrRemove(NULL) == NULL && ListItrRemove(ListItrEnd(list)) == NULL)
	{
		printf("ListItrRemove1 - PASS!\n");
	}
	else
	{
		printf("ListItrRemove1 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}

ListItrRemoveIsWork(void)
{
List* list = ListCreate();
int* ptr;
int* ptr2;
void* old;
int x = 5;
int y = 3;
ptr = &x;
ptr2 = &y;
ListPushHead(list, ptr);
ListPushHead(list, ptr2);
old = ListItrRemove(ListItrNext(ListItrBegin(list)));


	if(old == ptr && ListItrGet(ListItrBegin(list)) == ptr2 && ListItrNext(ListItrBegin(list)) == ListItrEnd(list))
	{
		printf("ListItrRemove2 - PASS!\n");
	}
	else
	{
		printf("ListItrRemove2 - FAILS!\n");
	}
ListDestroy(&list, NULL);
}


int main()
{
printf("\n");
printf("------------ListItrBegin-------------\n");
ListItrBeginNULL();
ListItrBeginIsWork();

printf("\n");
printf("------------ListItrEnd-------------\n");
ListItrEndNULL();
ListItrEndIsWork();

printf("\n");
printf("------------ListItrEquals-------------\n");
ListItrEqualsNULL();
ListItrEqualEqual();
ListItrEqualNotEqual();

printf("\n");
printf("------------ListItrNext-------------\n");
ListItrNextNULL();
ListItrNextIsWork();

printf("\n");
printf("------------ListItrPrev-------------\n");
ListItrPrevNULL();
ListItrPrevIsWork();
ListItrPrevIsWork2();

printf("\n");
printf("------------ListItrGet-------------\n");
ListItrGetNULL();
ListItrGetNULL2();
ListItrGetIsWork();

printf("\n");
printf("------------ListItrSet-------------\n");
ListItrSetNULL();
ListItrSetIsWork();

printf("\n");
printf("------------ListItrInsertBefore-------------\n");
ListItrInsertBeforeNULL();
ListItrInsertBeforeIsWork();

printf("\n");
printf("------------ListItrRemove-------------\n");
ListItrRemoveNULL();
ListItrRemoveIsWork();


}
