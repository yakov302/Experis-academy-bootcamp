#include <stdio.h>
#include <stdlib.h>
#include "cstack.h"
#define MAGIC_NUMBER 8123475

/*************************StructStack****************************/

struct Stack
{
	int *m_array; 
	size_t m_capacity;
	size_t m_numOfItems;
 	int m_magicNumber;
};

/*************************StackCreate****************************/

Stack *StackCreate (size_t _capacity) 
{
 Stack *stack;
 
 	if (_capacity == 0)
 	{
  		return NULL ;
 	}

 	if ((stack = (Stack*) malloc (sizeof(Stack))) == NULL)
 	{
 		 return NULL ;
 	}
 
 	if ((stack ->  m_array = (int*) malloc (sizeof(int)*_capacity)) == NULL )
 	{
 		 free (stack); 
 		 return NULL;
 	} 
 	
 	stack -> m_capacity = _capacity;
 	stack -> m_numOfItems = 0;
 	stack -> m_magicNumber = MAGIC_NUMBER;
 	
return stack;
}

/*************************StackDestroy****************************/

void StackDestroy (Stack *_stack) 
{
 	if (_stack == NULL || _stack -> m_magicNumber != MAGIC_NUMBER)
 	{
 		return;
 	}
 	_stack -> m_magicNumber  = 0;
  	free (_stack -> m_array);
 	free (_stack);
}

/*************************StackPush****************************/

ReturnMessages StackPush (Stack *_stack, int _item) 
{

 	if (_stack == NULL)
 	{
  		return STACK_NOT_INITIALIZED;
 	}

	if(_stack -> m_numOfItems == _stack -> m_capacity)
	{
		return STACK_OVERFLOW;
	}
	
	_stack -> m_array[_stack -> m_numOfItems] = _item;
	_stack -> m_numOfItems++;
	
return STACK_SUCCESS;
}

/*************************StackPop****************************/

ReturnMessages StackPop ( Stack* _stack , int *_item) 
{

 	if (_stack == NULL)
 	{
 		 return STACK_NOT_INITIALIZED;
 	}
 	
 	 if (_item == NULL)
 	{
 		 return ITEM_NOT_INITIALIZED;
 	}

	if (_stack -> m_numOfItems == 0)
	{
		return STACK_UNDERFLOW;
	}
	
	*_item =  _stack -> m_array [_stack -> m_numOfItems - 1];
	_stack -> m_numOfItems--;
	
return STACK_SUCCESS;
}

/*************************StackTop****************************/

ReturnMessages StackTop (Stack *_stack, int  *_item) 
{ 

 	if (_stack == NULL)
 	{
 		 return STACK_NOT_INITIALIZED;
 	}
 	
 	 if (_item == NULL)
 	{
 		 return ITEM_NOT_INITIALIZED;
 	}


	if (_stack -> m_numOfItems == 0)
	{
		return STACK_UNDERFLOW;
	}
	
	*_item =  _stack -> m_array[_stack -> m_numOfItems - 1];

return STACK_SUCCESS;
}

/*************************StackIsEmpty****************************/

ReturnMessages StackIsEmpty (Stack* _stack) 
{
	if (_stack == NULL)
 	{
 	 	return STACK_NOT_INITIALIZED;
 	}
 	  
 	if (_stack -> m_numOfItems  == 0)
 	{
  		return STACK_EMPTY;
 	}
 	
return STACK_NOT_EMPTY;
}	

/*************************StackIsFull****************************/

ReturnMessages StackIsFull (Stack* _stack) 
{
	if (_stack == NULL)
 	{
 	 	return STACK_NOT_INITIALIZED;
 	}
 	  
 	if (_stack -> m_numOfItems  == _stack -> m_capacity)
 	{
  		return STACK_FULL;
 	}
 	
return STACK_NOT_FULL;
}	







