#include <stdio.h>
#include <stdlib.h>
#include "listdo.h"
#include "enum.h"

/***********************ListCreate**********************/

IsListCreateWork(void)
{
List* list;
	list = ListCreate();
	if(GetmHeadMPrev(list) == NULL)
	{
		 printf("ListCreate test - Is creater work              - PASS! \n");	
	}
	else
	{
		printf("ListCreate test - Is creater work               - FAILS! \n");	
	}	
ListDestroy(list);
}

/***********************ListPushHead**********************/

ListPushHeadIsNullWork(void)
{
List* list;
	list = ListCreate();
	if(ListPushHead(NULL, 5) == ERR_NOT_INITIALIZED)
	{
		 printf("ListPushHead test - Is list NULL give NULL err - PASS! \n");	
	}
	else
	{
		printf("ListPushHead test - Is list NULL give NULL err - FAILS! \n");	
	}	
ListDestroy(list);
}

ListPushHeadIsPushWork(void)
{
List* list;
	list = ListCreate();
	ListPushHead(list,1);
	ListPushHead(list,2);
	ListPushHead(list,3);
	if(GetData(list, 0) == 3 && GetData(list, 1) == 2 && GetData(list, 2) == 1)
	{
		 printf("ListPushHead test - Is push work               - PASS! \n");	
	}
	else
	{
		printf("ListPushHead test - Is push work                 - FAILS! \n");	
	}	

ListDestroy(list);
}

/***********************ListPushTail**********************/

ListPushTailIsNullWork(void)
{
List* list;
	list = ListCreate();
	if(ListPushTail(NULL, 5) == ERR_NOT_INITIALIZED)
	{
		 printf("ListPushTail test - Is list NULL give NULL err - PASS! \n");	
	}
	else
	{
		printf("ListPushTail test - Is list NULL give NULL err - FAILS! \n");	
	}	
ListDestroy(list);
}

ListPushTailIsPushWork(void)
{
List* list;
	list = ListCreate();
	ListPushTail(list,1);
	ListPushTail(list,2);
	ListPushTail(list,3);
	if(GetData(list, 0) == 1 && GetData(list, 1) == 2 && GetData(list, 2) == 3)
	{
		 printf("ListPushTail test - Is push work               - PASS! \n");	
	}
	else
	{
		printf("ListPushTail test - Is push work                - FAILS! \n");	
	}	

ListDestroy(list);
}

/***********************ListPopHead**********************/
ListPopHeadIsNullWork(void)
{
List* list;
int *node;
	list = ListCreate();
	if(ListPopHead(NULL, node) == ERR_NOT_INITIALIZED)
	{
		 printf("ListPopHead test - Is list NULL give NULL err  - PASS! \n");	
	}
	else
	{
		printf("ListPopHead test - Is list NULL give NULL err   - FAILS! \n");	
	}	
ListDestroy(list);
}

ListPopHeadIsNullWork2(void)
{
List* list;
int *node;
	list = ListCreate();
	if(ListPopHead(list, NULL) == ERR_NOT_INITIALIZED)
	{
		 printf("ListPopHead test - Is item NULL give NULL err  - PASS! \n");	
	}
	else
	{
		printf("ListPopHead test - Is item NULL give NULL err  - FAILS! \n");	
	}	
ListDestroy(list);
}

ListPopHeadIsUnderFlowlWork(void)
{
List* list;
int *node;
	list = ListCreate();
	if(ListPopHead(list, node) == ERR_UNDERFLOW)
	{
		 printf("ListPopHead test - Is under flow err work      - PASS! \n");	
	}
	else
	{
		printf("ListPopHead test - Is under flow err work       - FAILS! \n");	
	}	
ListDestroy(list);
}

ListPopHeadIsPopWork(void)
{
List* list;
int *node;
	list = ListCreate();
	ListPushHead(list, 1);
	ListPushHead(list, 2);
	ListPopHead(list, node);
	if(GetData(list,0) == 1)
	{
		 printf("ListPopHead test - Is pop work                 - PASS! \n");	
	}
	else
	{
		printf("ListPopHead test - Is Is pop work              - FAILS! \n");	
	}	
ListDestroy(list);
}

/***********************ListPopTail**********************/

ListPopTailIsNullWork(void)
{
List* list;
int *node;
	list = ListCreate();
	if(ListPopTail(NULL, node) == ERR_NOT_INITIALIZED)
	{
		 printf("ListPopTail test - Is list NULL give NULL err - PASS! \n");	
	}
	else
	{
		printf("ListPopTail test - Is list NULL give NULL err - FAILS! \n");	
	}	
ListDestroy(list);
}

ListPopTailIsNullWork2(void)
{
List* list;
int *node;
	list = ListCreate();
	if(ListPopTail(list, NULL) == ERR_NOT_INITIALIZED)
	{
		 printf("ListPopTail test - Is item NULL give NULL err - PASS! \n");	
	}
	else
	{
		printf("ListPopTail test - Is item NULL give NULL err - FAILS! \n");	
	}	
ListDestroy(list);
}

ListPopTailIsUnderFlowlWork(void)
{
List* list;
int *node;
	list = ListCreate();
	if(ListPopTail(list, node) == ERR_UNDERFLOW)
	{
		 printf("ListPopTail test - Is under flow err work     - PASS! \n");	
	}
	else
	{
		printf("ListPopTail test - Is under flow err work      - FAILS! \n");	
	}	
ListDestroy(list);
}

ListPopTailIsPopWork(void)
{
List* list;
int *node;
	list = ListCreate();
	ListPushHead(list, 1);
	ListPushHead(list, 2);
	ListPopTail(list, node);
	if(GetData(list,0) == 2)
	{
		 printf("ListPopTail test - Is pop work                - PASS! \n");	
	}
	else
	{
		printf("ListPopTail test - Is Is pop work             - FAILS! \n");	
	}	
ListDestroy(list);
}


/***********************ListCountItems**********************/

ListCountItemsIsNullWork(void)
{
List* list;
int *node;
	list = ListCreate();
	if(ListCountItems(NULL) == ERR_NOT_INITIALIZED)
	{
		 printf("ListCountItems test - Is list NULL give NULL err - PASS! \n");	
	}
	else
	{
		printf("ListCountItems test - Is list NULL give NULL err - FAILS! \n");	
	}	
ListDestroy(list);
}

ListCountItemsIsCountWork(void)
{
List* list;
int *node;
	list = ListCreate();
	ListPushHead(list, 1);
	ListPushHead(list, 2);
	ListPopTail(list, node);
	if(ListCountItems(list) == 1)
	{
		 printf("ListCountItems test - Is count work              - PASS! \n");	
	}
	else
	{
		printf("ListCountItems test - Is count work               - FAILS! \n");	
	}	
ListDestroy(list);
}

/***********************ListIsEmpty**********************/

ListIsEmptyIsNullWork(void)
{
List* list;
int *node;
	list = ListCreate();
	if(ListIsEmpty(NULL) == ERR_NOT_INITIALIZED)
	{
		 printf("ListIsEmpty test - Is list NULL give NULL err - PASS! \n");	
	}
	else
	{
		printf("ListIsEmpty test - Is list NULL give NULL err - FAILS! \n");	
	}	
ListDestroy(list);
}


IsListIsEmptyWork(void)
{
List* list;
int *node;
	list = ListCreate();
	ListPushHead(list, 1);
	ListPushHead(list, 2);
	ListPopTail(list, node);
	ListPopTail(list, node);
	if(ListIsEmpty(list) == ERR_NO_ELEMENTS)
	{
		 printf("ListIsEmpty test - Is list is empty work      - PASS! \n");	
	}
	else
	{
		printf("ListIsEmpty test - Is list is empty work       - FAILS! \n");	
	}	
ListDestroy(list);
}


/***********************ListDestroy**********************/

ListDestroyIsdoubDestroyWork(void)
{
List* list;
int *node;
	list = ListCreate();
	ListPushHead(list, 1);
	ListPushHead(list, 2);
	ListDestroy(list);
	ListDestroy(list);
	

		 printf("ListDestroy test - Is doub destroy work          - PASS! \n");	

}



int main()
{
printf("\n");
printf("------------ListCreate test-------------\n");
IsListCreateWork();

printf("\n");
printf("------------ListPushHead test-------------\n");
ListPushHeadIsNullWork();
ListPushHeadIsPushWork();

printf("\n");
printf("------------ListPushTail test-------------\n");
ListPushTailIsNullWork();
ListPushTailIsPushWork();

printf("\n");
printf("------------ListPopHead test-------------\n");
ListPopHeadIsNullWork();
ListPopHeadIsNullWork2();
ListPopHeadIsUnderFlowlWork();
ListPopHeadIsPopWork();

printf("\n");
printf("------------ListPopTail test-------------\n");
ListPopTailIsNullWork();
ListPopTailIsNullWork2();
ListPopTailIsUnderFlowlWork();
ListPopTailIsPopWork();

printf("\n");
printf("------------ListCountItems test-------------\n");
ListCountItemsIsNullWork();
ListCountItemsIsCountWork();

printf("\n");
printf("------------ListIsEmpty test-------------\n");
ListIsEmptyIsNullWork();
IsListIsEmptyWork();

printf("\n");
printf("------------ListDestroy test-------------\n");
ListDestroyIsdoubDestroyWork();




}
