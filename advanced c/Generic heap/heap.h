#ifndef __HEAP_H__
#define __HEAP_H__
#include "vector.h"
#include <stdio.h>

/************************Error messages****************************/

typedef enum Heap_ResultCode{
HEAP_SUCCESS,
HEAP_NOT_INITIALIZED,
HEAP_REALLOCATION_FAILED,
HEAP_UNDERFLOW,
HEAP_VECTOR_APPEND_FAIL
} HeapResultCode;

/************************rename to struct Heap****************************/

typedef struct Heap Heap;

/********************rename to function************************/

typedef int (*ActionFunction)(const void *_element, void* _context);
typedef int (*LessThanComparator)(const void* _left, const void* _right);

/*Description:
get generic vector in which each member is void* and can point to any type and arranges it according to the heap rules.

Input:
*_vector - Pointer to the vector structure.
_checkSwap - generic function that receive two elements and returns if they need to be swap.

Output:
NULL - if _vector == NULL || _checkSwap == NULL or if the memory allocations failed.
heap - Pointer to the Heap structure.*/
Heap* HeapBuild(Vector* _vector, LessThanComparator _checkSwap);

/*Description:
Destroys the Heap structure and returns Pointer to the vector.

Input:
**_heap - pointer to pointer to the Heap structure. get &(*heap).

Output:
vector - Pointer to the vector structure.*/	
Vector* HeapDestroy(Heap** _heap);

/*Description:
insert new element to the last place in the Heap. get void* or pointer to another type.

Input:
*_heap - pointer to the Heap structure.
*_element - new pointer that will enter the last place in Heap.

Output:
HEAP_NOT_INITIALIZED - if _heap == NULL || _element == NULL. 
HEAP_VECTOR_APPEND_FAIL - If the VectorAppend function fails.
HEAP_SUCCESS - If the new pointer enters the Heap successfully.*/	
HeapResultCode HeapInsert(Heap* _heap, void* _element);

/*Description:
return the element in the first place (max element). (Does not delete the element from the Heap)

Input:
*_heap - pointer to the Heap structure.

Output:
NULL - if _heap == NULL or if The number of elements in the Heap is 0.
element - the element in the first place (max element).*/
const void* HeapPeak (const Heap* _heap);

/*Description:
return the element in the first place (max element) and delete it from the Heap.

Input:
*_heap - pointer to the Heap structure.

Output:
NULL - if _heap == NULL or if The number of elements in the Heap is 0.
element - the element in the first place (max element).*/
void* HeapHxtract (Heap* _heap);

/*Description:
Returns the number of elements in the Heap.

Input:
*_heap - pointer to the Heap structure.

Output:
0 - if _heap == NULL.
_heap -> m_heapSize - the number of elements in the Heap.*/
size_t HeapSize(const Heap* _heap);

/*Description:
generic function used for all actions that need to be done on all the Heap elements.

Input:
*_heap - pointer to the Heap structure.
_action - Pointer to function that defines the action required to perform on all the Vector elements. Returns 0 to stop when no need to continue running on the other Heap elements.
*_context - External information (if required) to perform the action. (Eg value you want to check if exsist in the vector)

Output:
0 - if _heap == NULL || _action == NULL.
i - The index where the function _action returned 0. or the index at the last place + 1 if the function ran on all the elements without stopping.*/
size_t HeapForEach(const Heap* _heap, ActionFunction _action, void* _context);

#endif /*#ifndef__HEAP_H__*/










