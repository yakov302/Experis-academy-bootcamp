#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortingAlgorithms.h"
#include "enum.h"
#define ARR_SIZE 60000

int main()
{
int i;
int baseArr[ARR_SIZE];
int bubbleArr[ARR_SIZE];
int shakeArr[ARR_SIZE];
int ShellArr[ARR_SIZE];
int InsertionArr[ARR_SIZE];
int QuicArr[ARR_SIZE];
int SelectionArr[ARR_SIZE];
int MergeArr[ARR_SIZE];
int CountingArr[ARR_SIZE];
int RadixArr[ARR_SIZE];
Vector* vecPtr;
Vector* vecPtr2;
Vector* vecPtr3;
Vector* vecPtr4;
Vector* vecPtr5;
Vector* vecPtr6;
Vector* vecPtr7;
Vector* vecPtr8;
Vector* vecPtr9;
clock_t bubbleStart;
clock_t bubbleEnd;
clock_t bubbleTotal;
clock_t shakeStart;
clock_t shakeEnd;
clock_t shakeTotal;
clock_t insertionStart;
clock_t insertionEnd;
clock_t insertionTotal;
clock_t QuicStart;
clock_t QuicEnd;
clock_t QuicTotal;
clock_t ShellStart;
clock_t ShellEnd;
clock_t ShellTotal;
clock_t SelectionStart;
clock_t SelectionEnd;
clock_t SelectionTotal;
clock_t MergeStart;
clock_t MergeEnd;
clock_t MergeTotal;
clock_t CountingStart;
clock_t CountingEnd;
clock_t CountingTotal;
clock_t RadixStart;
clock_t RadixEnd;
clock_t RadixTotal;


	for (i = 0; i < ARR_SIZE; i++)
	{
		baseArr[i] = rand()%ARR_SIZE;
	}

		
/**********************bubble**********************/
	
vecPtr = VectorCreate(ARR_SIZE, 50);
	 
	for (i = 0; i < ARR_SIZE; i++)
	{
		bubbleArr[i] = baseArr[i];
	}
		
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr, bubbleArr[i]);
	}
	
bubbleStart = clock();	
BubbleSort(vecPtr);
bubbleEnd = clock();
bubbleTotal = bubbleEnd - bubbleStart;


/**********************shake**********************/

vecPtr2 = VectorCreate(ARR_SIZE, 50);

	for (i = 0; i < ARR_SIZE; i++)
	{
		shakeArr[i] = baseArr[i];
	}
	
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr2, shakeArr[i]);
	}

shakeStart = clock();	
ShakeSort(vecPtr2);
shakeEnd = clock();
shakeTotal =  shakeEnd - shakeStart;


/**********************Insertion**********************/

 vecPtr3 = VectorCreate(ARR_SIZE, 50);

	for (i = 0; i < ARR_SIZE; i++)
	{
		InsertionArr[i] = baseArr[i];
	}
	
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr3, InsertionArr[i]);
	}

insertionStart = clock();
InsertionSort(vecPtr3);
insertionEnd =  clock();
insertionTotal = insertionEnd -  insertionStart;


/**********************Quic**********************/

vecPtr4 = VectorCreate(ARR_SIZE, 50);

	for (i = 0; i < ARR_SIZE; i++)
	{
		QuicArr[i] = baseArr[i];
	}
	
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr4, QuicArr[i]);
	}
	

QuicStart = clock();	
QuickSort(vecPtr4);
QuicEnd = clock();
QuicTotal = QuicEnd - QuicStart;


/**********************Shell**********************/

 vecPtr5 = VectorCreate(ARR_SIZE, 50);

	for (i = 0; i < ARR_SIZE; i++)
	{
		ShellArr[i] = baseArr[i];
	}
	
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr5, ShellArr[i]);
	}

ShellStart = clock();
ShellSort(vecPtr5);
ShellEnd = clock();
ShellTotal = ShellEnd - ShellStart;


/**********************Selection**********************/

 vecPtr6 = VectorCreate(ARR_SIZE, 50);

	for (i = 0; i < ARR_SIZE; i++)
	{
		SelectionArr[i] = baseArr[i];
	}
	
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr6, SelectionArr[i]);
	}

SelectionStart = clock();
SelectionSort(vecPtr6);
SelectionEnd = clock();
SelectionTotal = SelectionEnd - SelectionStart;


/**********************Merge**********************/

 vecPtr7 = VectorCreate(ARR_SIZE, 50);

	for (i = 0; i < ARR_SIZE; i++)
	{
		MergeArr[i] = baseArr[i];
	}
	
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr7, MergeArr[i]);
	}

MergeStart = clock();	
MergeSort(vecPtr7);
MergeEnd = clock();
MergeTotal = MergeEnd - MergeStart;


/**********************Counting**********************/

 vecPtr8 = VectorCreate(ARR_SIZE, 50);

	for (i = 0; i < ARR_SIZE; i++)
	{
		CountingArr[i] = baseArr[i];
	}
	
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr8, CountingArr[i]);
	}
	
CountingStart = clock();	
CountingSort(vecPtr8, ARR_SIZE);
CountingEnd = clock();
CountingTotal = CountingEnd - CountingStart;

/**********************Radix**********************/

 vecPtr9 = VectorCreate(ARR_SIZE, 50);

	for (i = 0; i < ARR_SIZE; i++)
	{
		RadixArr[i] = baseArr[i];
	}
	
	for (i = 0; i < ARR_SIZE; i++)
	{
		VectorAdd (vecPtr9, RadixArr[i]);
	}

RadixStart = clock();	
RadixSort(vecPtr9,5);
RadixEnd = clock();
RadixTotal = RadixEnd - RadixStart;

	
/**********************print**********************/
printf("Running time in seconds on a 60,000 array\n");
printf("Bubble:    %0.3f\n", (double)bubbleTotal/1000000);
printf("Shake:     %0.3f\n", (double)shakeTotal/1000000);
printf("Insertion: %0.3f\n", (double)insertionTotal/1000000);
printf("Selection: %0.3f\n", (double)SelectionTotal/1000000);
printf("Shell:     %0.3f\n", (double)ShellTotal/1000000);
printf("Merge:     %0.3f\n", (double)MergeTotal/1000000);
printf("Quic:      %0.3f\n", (double)QuicTotal/1000000);
printf("Radix:     %0.3f\n", (double)RadixTotal/1000000);
printf("Counting:  %0.3f\n", (double)CountingTotal/1000000);



/**********************Destroy**********************/

VectorDestroy(vecPtr);
VectorDestroy(vecPtr2);
VectorDestroy(vecPtr3);
VectorDestroy(vecPtr4);
VectorDestroy(vecPtr5);
VectorDestroy(vecPtr6);
VectorDestroy(vecPtr7);
VectorDestroy(vecPtr8);
VectorDestroy(vecPtr9);
}

