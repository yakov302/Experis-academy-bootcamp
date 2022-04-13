#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "enum.h"

/**************************QueueCreate***************************/

void CreateIsSize0Null(void)
{
	Queue *ptr;
	ptr = QueueCreate(0);
	if(ptr == NULL)
	{
		printf("QueueCreate test - is size 0 NULL   - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("QueueCreate test - is size 0 NULL   - FAILS! \n");	
	}
QueueDestroy(ptr);	
}

void CreateIsNegativeSizeNull(void)
{
	Queue *ptr;
	ptr = QueueCreate(-1);
	if(ptr == NULL)
	{
		printf("QueueCreate test - is size -1 NULL  - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("QueueCreate test - is size -1 NULL  - FAILS! \n");	
	}
QueueDestroy(ptr);		
}

void CreateIsPositiveSizeNull(void)
{
	Queue *ptr;
	ptr = QueueCreate(10);
	if(ptr != NULL)
	{
		printf("QueueCreate test - is size 10 NULL  - PASS! \n");	
	}
	if(ptr == NULL)
	{
		printf("QueueCreate test - is size 10 NULL  - FAILS! \n");	
	}
QueueDestroy(ptr);		
}

void CreateCheckParameters(void)
{

	Queue *ptr;
	ptr = QueueCreate(10);
	if(GrtSize(ptr) == 10 && GetHead(ptr) == 0 && GetTail(ptr) == 0 && GetnItems(ptr) == 0)
	{
		printf("QueueCreate test - Check parameters - PASS! \n");	
	}
	else
	{
		printf("QueueCreate test - Check parameters - FAILS! \n");	
	}

QueueDestroy(ptr);
}

/**************************QueueDestroy***************************/

void DestroyIsNull(void)
{
	Queue *ptr;
	ptr = QueueCreate(0);
	if(ptr == NULL)
	{
		printf("QueueDestroy test - is NULL             - PASS! \n");	
	}
	if(ptr != NULL)
	{
		printf("QueueDestroy - is  NULL             - FAILS! \n");	
	}
QueueDestroy(ptr);
}

void DestroyIsFreeWork(void)
{
	Queue *ptr;
	int GrtSize1;
	int GetHead1;
	int GetTail1;
	int GetnItems1;
	int GrtSize2;
	int GetHead2;
	int GetTail2;
	int GetnItems2;
	
	ptr = QueueCreate(10);
	
	 GrtSize1 = GrtSize(ptr);
	 GetHead1 = GetHead(ptr);
	 GetTail1 =  GetTail(ptr);	
	 GetnItems1= GetnItems(ptr);
	 
	QueueDestroy(ptr);
	
	GrtSize2 = GrtSize(ptr);	
	GetHead2 = GetHead(ptr);	
	GetTail2 =  GetTail(ptr);
	GetnItems2= GetnItems(ptr);
	
	if(GrtSize1 != GrtSize2 || GetHead1 != GetHead2 || GetTail1 != GetTail2 ||GetnItems1!= GetnItems2)
	{
		printf("QueueDestroy test - is free work        - PASS! \n");	
	}
	else
	{
		printf("QueueDestroy test - is free work        - FAILS! \n");	
	}

QueueDestroy(ptr);
}

void DestroyIsDoubleFreeWork(void)
{
	Queue *ptr;
	int GrtSize1;
	int GetHead1;
	int GetTail1;
	int GetnItems1;
	int GrtSize2;
	int GetHead2;
	int GetTail2;
	int GetnItems2;
	
	
	ptr = QueueCreate(10);
	QueueDestroy(ptr);
	
	 GrtSize1 = GrtSize(ptr);
	 GetHead1 = GetHead(ptr);
	 GetTail1 =  GetTail(ptr);	
	 GetnItems1= GetnItems(ptr);
	 
	QueueDestroy(ptr);
	
	GrtSize2 = GrtSize(ptr);	
	GetHead2 = GetHead(ptr);	
	GetTail2 =  GetTail(ptr);
	GetnItems2= GetnItems(ptr);
	
	if(GrtSize1 == GrtSize2 && GetHead1 == GetHead2 && GetTail1 == GetTail2 && GetnItems1 == GetnItems2)
	{
		printf("QueueDestroy test - is double free work - PASS! \n");	
	}
	else
	{
		printf("QueueDestroy test - is double free work - FAILS! \n");	
	}

QueueDestroy(ptr);
}

/**************************QueueInsert***************************/

void InsertIsNullWork(void)
{
	Queue *ptr;
	ptr = QueueCreate(0);
	if(QueueInsert(ptr, 5) == ERR_NOT_INITIALIZED)
	{
		printf("QueueInsert test - is NULL work     - PASS! \n");	
	}
	else
	{
		printf("QueueInsert test - is NULL work     - FAILS! \n");	
	}
QueueDestroy(ptr);	
}

void InsertIsOverFlowWork(void)
{
int i;

	Queue *ptr;
	ptr = QueueCreate(5);
	for (i=0; i<5; i++)
	{
		QueueInsert(ptr, i);
	}
	if(QueueInsert(ptr, 6) == ERR_OVERFLOW)
	{
		printf("QueueInsert test - is OverFlow work - PASS! \n");	
	}
	else
	{
		printf("QueueInsert test - is OverFlow work - FAILS! \n");	
	}
QueueDestroy(ptr);		
}

void InsertIsWork(void)
{
int i;

	Queue *ptr;
	ptr = QueueCreate(5);
	for (i=0; i<3; i++)
	{
		QueueInsert(ptr, i);
	}

	if(Getx(ptr, 2) == 2 && GetTail(ptr) == 3 && GetnItems(ptr) == 3 )
	{
		printf("QueueInsert test - is Insert work   - PASS! \n");	
	}
	else
	{
		printf("QueueInsert test - is Insert work   - FAILS! \n");	
	}
QueueDestroy(ptr);		
}

void InsertIsTailciclic(void)
{
int i;
int item;

	Queue *ptr;
	ptr = QueueCreate(5);
	for (i=0; i<5; i++)
	{
		QueueInsert(ptr, i);
	}
	for (i=0; i<2; i++)
	{
		QueueRemove(ptr, &item);
	}
	for (i=0; i<5; i++)
	{
		QueueInsert(ptr, i);
	}
	if(GetTail(ptr) == 2 )
	{
		printf("QueueInsert test - Is Tail ciclic   - PASS! \n");	
	}
	else
	{
		printf("QueueInsert test - Is Tail ciclic   - FAILS! \n");	
	}
QueueDestroy(ptr);
}


/**************************QueueRemove***************************/

void RemoveIsNullWork(void)
{
	Queue *ptr;
	int item;
	ptr = QueueCreate(5);

	if(QueueRemove(ptr, NULL) == ERR_NOT_INITIALIZED && QueueRemove(NULL, &item) == ERR_NOT_INITIALIZED)
	{
		printf("QueueRemove test - is NULL work      - PASS! \n");	
	}
	else
	{
		printf("QueueRemove test - is NULL work      - FAILS! \n");	
	}
QueueDestroy(ptr);	
}

void RemoveIsUnderFlowWork(void)
{
int item;

	Queue *ptr;
	ptr = QueueCreate(5);
	
	if(QueueRemove(ptr, &item) == ERR_UNDERFLOW)
	{
		printf("QueueRemove test - is UnderFlow work - PASS! \n");	
	}
	else
	{
		printf("QueueRemove test - is UnderFlow work - FAILS! \n");	
	}
}

void RemoveIsWork(void)
{
int item;
int i;

	Queue *ptr;
	ptr = QueueCreate(5);
	for (i=0; i<5; i++)
	{
		QueueInsert(ptr, i);
	}
	for (i=0; i<2; i++)
	{
		QueueRemove(ptr, &item);
	}

	if(item == 1 && GetHead(ptr) == 2 && GetnItems(ptr) == 3)
	{
		printf("QueueRemove test - is Remove work    - PASS! \n");	
	}
	else
	{
		printf("QueueRemove test - is Remove work    - FAILS! \n");	
	}
                 
QueueDestroy(ptr);		
}

void InsertIsHeadciclic(void)
{
int i;
int item;

	Queue *ptr;
	ptr = QueueCreate(5);
	for (i=0; i<5; i++)
	{
		QueueInsert(ptr, i);
	}
	for (i=0; i<5; i++)
	{
		QueueRemove(ptr, &item);
	}
	for (i=0; i<5; i++)
	{
		QueueInsert(ptr, i);
	}
	for (i=0; i<2; i++)
	{
		QueueRemove(ptr, &item);
	}
	if(GetHead(ptr) == 2 )
	{
		printf("QueueInsert test - Is Head ciclic    - PASS! \n");	
	}
	else
	{
		printf("QueueInsert test - Is Head ciclic    - FAILS! \n");	
	}
QueueDestroy(ptr);
}

/**************************QueueIsEmpty***************************/

void QueueIsEmptyIsErrNoEkmentSWork(void)
{
	Queue *ptr;
	ptr = QueueCreate(5);
	if(QueueIsEmpty(NULL) == ERR_NO_ELEMENTS && QueueIsEmpty(ptr) == ERR_NO_ELEMENTS)
	{
		printf("QueueIsEmpty test - is ErrNoEkment work  - PASS! \n");	
	}
	else
	{
		printf("QueueIsEmpty test - is ErrNoEkment work  - FAILS! \n");	
	}
QueueDestroy(ptr);	
}

void QueueIsEmptyIsSWork(void)
{
int i;
	Queue *ptr;
	ptr = QueueCreate(5);
	for (i=0; i<3; i++)
	{
		QueueInsert(ptr, i);
	}
	if(QueueIsEmpty(ptr) == THERE_ARE_ELEMENTS)
	{
		printf("QueueIsEmpty test - is QueueIsEmpty work - PASS! \n");	
	}
	else
	{
		printf("QueueIsEmpty test - is QueueIsEmpty work - FAILS! \n");	
	}
QueueDestroy(ptr);	
}

int main()
{
printf("\n");
printf("------------QueueCreate test-------------\n");
CreateIsSize0Null();
CreateIsNegativeSizeNull();
CreateIsPositiveSizeNull();
CreateCheckParameters();

printf("\n");
printf("------------QueueDestroy test-------------\n");
DestroyIsNull();
DestroyIsFreeWork();
DestroyIsDoubleFreeWork();

printf("\n");
printf("------------QueueInsert test-------------\n");
InsertIsNullWork();
InsertIsOverFlowWork();
InsertIsWork();
InsertIsTailciclic();

printf("\n");
printf("------------QueueRemove test-------------\n");
RemoveIsNullWork();
RemoveIsUnderFlowWork();
RemoveIsWork();
InsertIsHeadciclic();

printf("\n");
printf("------------QueueIsEmpty test-------------\n");
QueueIsEmptyIsErrNoEkmentSWork();
QueueIsEmptyIsSWork();
printf("\n");




}
