#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"
#include "enum.h"
#define MAGIC_NUMBER 8123475

struct Stack
{
 Vector *m_vector; 
 int m_magicNumber;
};



/********************* StackCreate ************************/

Stack *StackCreate (size_t _size , size_t _blockSize) 
{
 Stack *ptr;
 Vector *vector;
 
 	if ( _size == 0 && _blockSize == 0 )
 	{
  		return NULL ;
 	}

 	if ((ptr = (Stack*) malloc (sizeof(Stack))) == NULL)
 	{
 		 return NULL ;
 	}
 
 	if ((vector = VectorCreate( _size, _blockSize)) == NULL )
 	{
 		 free (ptr); 
 		 return NULL;
 	} 
 	
 	ptr -> m_vector = vector;
	return ptr;
}


/*************** StackDestroy ***************/

void StackDestroy (Stack *_stack) 
{
 	if ( _stack == NULL && _stack -> m_magicNumber != MAGIC_NUMBER)
 	{
 		return;
 	}
 	 _stack -> m_magicNumber  = 0;
  	VectorDestroy(_stack-> m_vector);
 	free (_stack);
}


/******************* StackPush *******************/

ADTErr StackPush (Stack *_stack, int _item) 
{
 	if (_stack == NULL)
 	{
  		return ERR_NOT_INITIALIZED;
 	}
 	
 return VectorAdd(_stack -> m_vector, _item); 
}


/******************** StackPop *********************/

ADTErr StackPop ( Stack * _stack , int *_item) 
{
 	if (_stack == NULL)
 	{
 		 return ERR_NOT_INITIALIZED;
 	}
 	
 return VectorDelete(_stack -> m_vector, _item); 
}

/******************* StackTop ***********************/

ADTErr StackTop (Stack *_stack, int  *_item) 
{
 size_t numOfElements;
 ADTErr VectorItemsNumErr;
 
 	if ( _stack == NULL )
 	{
  		return ERR_NOT_INITIALIZED ;
	}
 	if ((VectorItemsNumErr = VectorItemsNum(_stack -> m_vector, &numOfElements)) != ERR_OK) 
 	{
  		return VectorItemsNumErr;
 	} 
 	
 return VectorGet(_stack -> m_vector, numOfElements -1 , _item); 
 
}

/*************** StackIsEmpty ***************/

int StackIsEmpty (Stack *_stack) 
{
 size_t numOfElements;
 
	 if (_stack == NULL)
 	{
 	 	return STACK_EMPTY;
 	}
 	
 	 VectorItemsNum (_stack -> m_vector, &numOfElements);
 	  
 	if (numOfElements == 0)
 	{
  		return STACK_EMPTY;
 	}
 		return STACK_NOT_EMPTY;
}	

/*************** StackPrint ***************/

void StackPrint(Stack *_stack) 
{
 	if (_stack == NULL)
 	{
  		return;
 	}
 	
 VectorPrint(_stack -> m_vector);
}








