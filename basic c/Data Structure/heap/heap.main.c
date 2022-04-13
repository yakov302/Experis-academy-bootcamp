#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "heap.h"
#include "enum.h"



int main()
{
Heap* heapPtr;
Vector*  vectorPtr;
int size;
int MagicNumber;
int max;
int x;

vectorPtr = VectorCreate(10,2);

VectorAdd(vectorPtr, 10);
VectorAdd(vectorPtr, 20);
VectorAdd(vectorPtr, 30);
VectorAdd(vectorPtr, 40);
VectorAdd(vectorPtr, 50);

heapPtr = HeapBuild(vectorPtr);

size = getHeapSize(heapPtr);
printf("\nm_heapSize: %d\n",size);

MagicNumber = getMagicNumber(heapPtr);
printf("\nMagicNumber: %d\n",MagicNumber);

printf("\n\n");
HeapPrint(heapPtr);


HeapInsert(heapPtr, 80);
HeapInsert(heapPtr, 110);
HeapInsert(heapPtr, 15);

printf("\n\n");
HeapPrint(heapPtr);


HeapMax(heapPtr, &max);
printf("\nmax: %d\n", max);


HeapHxtractMax(heapPtr, &max);
printf("\nmax: %d\n", max);
printf("\n\n");
HeapPrint(heapPtr);

HeapHxtractMax(heapPtr, &max);
printf("\nmax: %d\n", max);
printf("\n\n");
HeapPrint(heapPtr);

x = HeapItemsNum(heapPtr);
printf("\nHeapItemsNum: %d\n", x);






HeapDestroy(heapPtr);

VectorDestroy(vectorPtr);

}

