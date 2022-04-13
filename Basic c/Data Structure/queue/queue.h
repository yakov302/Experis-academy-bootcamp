#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdio.h>
#include "enum.h"
#define ERR_NO_ELEMENTS 1
#define THERE_ARE_ELEMENTS 0

/*new name to structure type*/
typedef struct Queue Queue;

/*QueueCreate function description:
1. Creates a memory allocation for structure that contains objects that managing the memory allocation.
2. creates memory allocation for array of int.
3.insert values to the structure elements of the structure:
*m_que: Pointer to the array.
m_size: Array size, comes as input - parameter in the function.
m_head:index that counts the removals.
m_tail:index that counts the inserts.
m_nItems:the number of members in the array.
m_magicNumber:number to prevent double free of the structure. Defined as a define at the top of the page.

input parameters:
_size: Array size.

output parameter:
NULL: if the array size is equal to 0 or if the memory allocation to the structure or array failed.
ptr: pointer to the structure if the allocations were made successfully.*/
Queue *QueueCreate(size_t _size);

/*QueueDestroy function description:
Release allocation of the array and the structure.

input parameters:
*_queue: pointer to the structure.*/
void QueueDestroy(Queue *_queue);

/*QueueInsert function description:
1. checks if the number of elements (m_nItems) is smaller than the size allocated to the array, and if is smaller, insert "_item" to the array and increases the number of elements (m_nItems) and the m_tail index by 1;

input parameters:
*_queue: pointer to the structure.
_item: the value that needs to by enter the array.

output parameter:
NERR_NOT_INITIALIZED: if the *_queue pointer is equal to NUUL.
ERR_OVERFLOW: If the number of members in the array is equal to the array size.
OK: if the value of "_item" variable enters the array*/
ADTErr QueueInsert(Queue *_queue, int _item);

/*QueueRemove function description:
insert the first member (The first to enter) in the array into pointer "_item" and decrease the number of elements(m_nItems) by 1 and increas the m_head index by 1.

input parameters:
*_queue: pointer to the structure.
*_item: pointer to "_item" variable, the first element in the array will be inserted into it.

output parameter:
ERR_NOT_INITIALIZED: if the *_queue pointer or the *_item poinret is equal to NUUL.
ERR_UNDERFLOW: If the number of elements (m_nItems) is 0.
ERR_OK: If the first element in the array insert into "_item" and the number of elements decreases by 1 and m_head index  increas by 1*/
ADTErr QueueRemove(Queue *_queue, int *_item);

/*QueueIsEmpty function description:
Checks if the array is empty or not.

input parameters:
*_queue: pointer to the structure.

output parameter:
ERR_NO_ELEMENTS:If the *_queue pointer is equal to NULL or if the array is empty. 
THERE_ARE_ELEMENTS: If the array is not empty*/
int QueueIsEmpty(Queue *_queue);

/*QueuePrint function description:
Prints all the members in the array.

input parameters:
*_queue: pointer to the structure.*/
void QueuePrint(Queue *_queue);











#endif /*#ifndef__QUEUE_H__*/
