#ifndef __STACK_H__
#define __STACK_H__

/*************************ReturnMessages****************************/

typedef enum ReturnMessages{
	STACK_NOT_INITIALIZED,
	STACK_OVERFLOW,
	STACK_SUCCESS,
	STACK_UNDERFLOW,
	STACK_EMPTY,
	STACK_NOT_EMPTY,
	STACK_FULL,
	STACK_NOT_FULL,
	ITEM_NOT_INITIALIZED
}ReturnMessages;

/*************************TypedefStructStack****************************/

typedef struct Stack Stack;


/*Description:
Create new Stack.

Input:
_capacity - Array size.

Output:
NULL - if _capacity == 0 or if one of the memory allocations failed.
stack - pointer to the stack struct.*/
Stack *StackCreate (size_t _capacity);

/*Description:
Destroy the stack.

Input:
*_stack - pointer to the stack struct.*/
void StackDestroy (Stack *_stack);

/*Description:
Insert new item (int) to the stack.

Input:
*_stack - pointer to the stack struct.
_item - The item that will enter the struct.

Output:
STACK_NOT_INITIALIZED - If *_stack == NULL.
STACK_OVERFLOW - If the stack is full.
STACK_SUCCESS - If the new item enters the stack successfully.*/
ReturnMessages StackPush (Stack *_stack, int _item);
 
/*Description:
Delete the lest item from the stack and insert it into the *_item variable.

Input:
*_stack - pointer to the stack struct.
*_item - The variable to which the deleted item enters.

Output:
STACK_NOT_INITIALIZED - If *_stack == NULL.
STACK_UNDERFLOW -  If the stack is empty.
STACK_SUCCESS - If the lest item from the stack deleted successfully.*/
ReturnMessages StackPop ( Stack* _stack , int *_item);

/*Description:
Insert the lest item from the stack into the *_item variable.

Input:
*_stack - pointer to the stack struct.
*_item - The variable to which the item enters.

Output:
STACK_NOT_INITIALIZED - If *_stack == NULL.
STACK_UNDERFLOW - If the stack is empty.
 STACK_SUCCESS -  If the lest item from the stack enter into *_item variable successfully. */
ReturnMessages StackTop (Stack *_stack, int  *_item);

/*Description:
Checks if the stack is empty or not.

Input:
*_stack - pointer to the stack struct.

Output:
STACK_NOT_INITIALIZED - If *_stack == NULL.
STACK_EMPTY: if the stack is empty. 
STACK_NOT_EMPTY: If the stack is not empty*/ 
ReturnMessages StackIsEmpty (Stack* _stack);

/*Description:
Checks if the stack is full or not.

Input:
*_stack - pointer to the stack struct.

Output:
STACK_NOT_INITIALIZED - If *_stack == NULL.
STACK_FULL: if the stack is full. 
STACK_NOT_FULL: If the stack is not full*/ 
ReturnMessages StackIsFull (Stack* _stack);


#endif /*#ifndef__STACK_H__*/
