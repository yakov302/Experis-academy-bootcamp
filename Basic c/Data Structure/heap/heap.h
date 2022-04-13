#ifndef __HEAP_H__
#define __HEAP_H__
#include <stdio.h>
#include "enum.h"
#include "vector.h"

/*new name to the heap structure*/
typedef struct Heap Heap;

Heap* HeapBuild(Vector* _vec);
/*Description:
	The function gets vector of integers, makes memory allocation to the heap structure and sorts all the nods according to the "max heap" conditions - for each node, his two child are smaller than him.
Input:
	_vec - Pointer to the vrctor.
Output:
	NULL - if _vec == NULL or if the memory allocation failed.
	heapPtr - Pointer to the heap structure.*/
	
void HeapDestroy(Heap* _heap);
/*Description:
	The function free the heap structure (not the vector).
Input:
	_heap - Pointer to the heap structure.*/
	
ADTErr HeapInsert(Heap* _heap, int _data);
/*Description:
	The function insert new item to the vector and sorts the heap according to the "max heap" conditions - for each node, his two child are smaller than him.
Input:
	_heap - Pointer to the heap structure.
Output:
	ERR_NOT_INITIALIZED - if _heap == NULL.
	addErr - if the insertion fails, returns the error type that VectorAdd function returns.
	ERR_OK - if the insertion was done successfully*/

ADTErr HeapMax (Heap* _heap, int* _data);
/*Description:
	Inserts to _data the max number (first node)
Input:
	_heap - Pointer to the heap structure.
	_data - Pointer to integer that will get the max number from the function.
Output:
	ERR_NOT_INITIALIZED - if _heap or _data == NULL.
	addErr - returns the error type that VectorGet function returns.
	ERR_UNDERFLOW - if the number of elements in the heap is 0*/

ADTErr HeapHxtractMax (Heap* _heap, int* _data);
/*Description:
	Inserts to _data the max number (first node) and then deletes it, moves the last node to the first place and then sorts the heap according to the "max heap" conditions - for each node, his two child are smaller than him.
Input:
	_heap - Pointer to the heap structure.
	_data - Pointer to integer that will get the max number from the function.
Output:
	ERR_NOT_INITIALIZED - if _heap or _data == NULL.
	ERR_UNDERFLOW - if the number of elements in the heap is 0
	ERR_OK - if everything done successfully*/

int HeapItemsNum(Heap* _heap);
/*Description:
	The function returns the number of elements that are in the heap.
Input:
	_heap - Pointer to the heap structure.
Output:
	ERR_NOT_INITIALIZED - if _heap == NULL.
	_heap -> m_heapSize - number of elements in the heap.*/

void HeapPrint(Heap* _heap);
/*Description:
	The function prints all the integers in the vector (the nodes of the heap).
Input:
	_heap - Pointer to the heap structure.*/

#endif /*#ifndef__HEAP_H__*/










