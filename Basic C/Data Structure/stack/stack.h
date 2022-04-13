#ifndef __STACK_H__
#define __STACK_H__
#define STACK_EMPTY 1
#define STACK_NOT_EMPTY 0
#include <stdio.h>
#include "enum.h"

/*new name to the structure type*/
typedef struct Stack Stack;


/*StackCreate function description:
1. Creates a memory allocation for structure that contains pointer to array of int.
2. creates memory allocation for the array using "VectorCreate" function.
3.inserting the pointer created in the "VectorCreate" function into the m_vector pointer.

input parameters:
_size: Array size.
_blockSize:Size of the array increases (if necessary).

output parameter:
NULL: if the array size and the array increases size is equal to 0 or if the memory allocation to the structure or array failed.
ptr: pointer to the structure if the allocations were made successfully.*/
Stack * StackCreate (size_t _size , size_t _blockSize);

/*StackDestroy function description:
Release allocation of the array and the structure.

input parameters:
*_stack: pointer to the structure.*/
void StackDestroy (Stack *_stack);

/*StackPush function description:
Insert parmeter to the array using VectorAdd function.

input parameters:
*_stack: pointer to the structure.
_item: The parmeter that will enter the array.

output parameter:
ERR_NOT_INITIALIZED: If the pointer to the structure is equal to NULL */
ADTErr StackPush (Stack *_stack, int _item);
 
/*StackPop function description:
Uses VectorDelete function to delete an element from the array and insert it into the _item variable.

input parameters:
*_stack: pointer to the structure.
_item: The variable to which the deleted value enters

output parameter:
ERR_NOT_INITIALIZED: If the pointer to the structure is equal to NULL */
ADTErr StackPop ( Stack * _stack , int *_item);

/*StackTop function description:
Uses VectorItemsNum and VectorGet functions to Insert the last element in the array into the _item variable.

input parameters:
*_stack: pointer to the structure.
_item: The variable to which the last element in the array will by enter.

output parameter:
ERR_NOT_INITIALIZED: If the pointer to the structure is equal to NULL
VectorItemsNumErr: Error returned from VectorItemsNum function.
 _item: The last parameter in the array */
ADTErr StackTop (Stack *_stack, int  *_item);


/*StackIsEmpty function description:
Checks if the array is empty or not.

input parameters:
*_stack: pointer to the structure.

output parameter:
STACK_EMPTY: if the array is empty. 
STACK_NOT_EMPTY: If the array is not empty*/ 
int StackIsEmpty (Stack *_stack); 

/*StackPrint function description:
Prints all the members in the array.

input parameters:
*_stack: pointer to the structure.*/
void StackPrint (Stack *_stack);

 
/*function that checks whether the resulting bracket order is balanced or not*/
int CheckBrackets(char _brackets[]);







#endif /*#ifndef__STACK_H__*/
