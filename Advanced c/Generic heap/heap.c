#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "heap.h"
#define FATHER(i) (i == 0)? 0 : ((i)-1)/2
#define RIGHT_CHILD(i) (i)*2 + 2
#define LEFT_CHILD(i) (i)*2 + 1

/*****************************Function signatures******************************/

static void bubbleUp (Heap* _heap);
void Heapify(Heap* _heap, int _index);
static int CheckBigest(Heap* _heap, int _index);

/*********************************struct Heap**********************************/

struct Heap
{
Vector* m_vector;
size_t m_heapSize;
LessThanComparator m_checkFunction;
};

/*********************************HeapBuild**********************************/

Heap* HeapBuild(Vector* _vector, LessThanComparator _checkSwap)
{
size_t sizeOfVector;
Heap* heap;
size_t i;

	if(_vector == NULL || _checkSwap == NULL)
	{
		return NULL;
	}
	
	if((heap = ((Heap*)malloc(sizeof(Heap)))) == NULL)
	{
		return NULL;
	}
	
	sizeOfVector = VectorSize (_vector);
	heap -> m_vector = _vector;
	heap -> m_heapSize = sizeOfVector;
	heap -> m_checkFunction = _checkSwap;
	
	for(i = FATHER(heap -> m_heapSize - 1); i >= 0; i--)
	{
		Heapify(heap,i);
		if(i == 0){break;}
	}
	
return heap;
}

/*********************************HeapDestroy**********************************/

Vector* HeapDestroy(Heap** _heap)
{
Vector* vector;

	if(_heap == NULL || *_heap == NULL)
	{
		return NULL;
	}
	
	vector = (*_heap) -> m_vector;
	free(*_heap);
	*_heap = NULL;
	
return vector;
}

/*********************************HeapInsert**********************************/

HeapResultCode HeapInsert(Heap* _heap, void* _element)
{
VectorResult result;

	if(_heap == NULL || _element == NULL)
	{
		return HEAP_NOT_INITIALIZED;
	}
	
	result = VectorAppend (_heap -> m_vector , _element);
	if( result != VECTOR_SUCCESS)
	{
		return HEAP_VECTOR_APPEND_FAIL;
	}
	
	_heap -> m_heapSize++;
	bubbleUp(_heap);
	
return HEAP_SUCCESS;
}

/*********************************HeapPeek**********************************/

const void* HeapPeak (const Heap* _heap)
{
void* element;

	if(_heap == NULL || _heap -> m_heapSize == 0)
	{
		return NULL;
	}
	
	VectorGet( _heap -> m_vector , 0, &element);

return element;
}

/*********************************HeapHxtract**********************************/

void* HeapHxtract (Heap* _heap)
{
void* element;
void* last;

	if(_heap == NULL || _heap -> m_heapSize == 0)
	{
		return ;
	}

	VectorGet(_heap -> m_vector ,0, &element);
	VectorRemove(_heap -> m_vector,  &last);
	_heap -> m_heapSize--;
	
	if(_heap -> m_heapSize > 0)
	{
		VectorSet(_heap -> m_vector, 0, last);
		Heapify(_heap, 0);
	}
	
return element;	
}

/*********************************HeapSize**********************************/

size_t HeapSize(const Heap* _heap)
{
	if( _heap == NULL)
	{
		return 0;
	}
	
return _heap -> m_heapSize;
}

/*********************************HeapForEach**********************************/

size_t HeapForEach(const Heap* _heap, ActionFunction _action, void* _context)
{
void* item;
size_t i;

	if(_heap == NULL || _action == NULL)
	{
		return 0;
	}

	for(i = 0; i < _heap -> m_heapSize ; i++)
	{
		VectorGet(_heap -> m_vector, i, &item);
		if(_action(item, _context) == 0)
		{
			break;
		}		
	}
return i;
}

/*********************************AuxiliaryFunctions**********************************/

static void bubbleUp (Heap* _heap)
{
void* New;
void* Father;
size_t iNew = 0;
size_t iFather = 0;

	iNew = _heap -> m_heapSize -1;
	iFather = FATHER(iNew);
	
	VectorGet(_heap -> m_vector, iNew, &New);
	VectorGet(_heap -> m_vector,iFather, &Father);
		
	while( _heap -> m_checkFunction(New, Father) == 1 && iNew > 0)
	{
		VectorSet(_heap -> m_vector, iNew, Father);
		VectorSet(_heap -> m_vector, iFather, New);

		iNew = 	iFather;
		iFather = FATHER(iNew);
		
		VectorGet(_heap -> m_vector, iNew, &New);
	        VectorGet(_heap -> m_vector, iFather, &Father);
	}	
}


void Heapify(Heap* _heap, int _index)
{
void* Father;
void* Bigest;
size_t iBigest;
size_t iFather;
size_t iLeftChild;

	iFather = _index;
	iLeftChild = LEFT_CHILD( _index);
	
	if(iLeftChild >  _heap -> m_heapSize - 1)
	{
		return;
	}
	
	iBigest = CheckBigest( _heap, _index);
	
	VectorGet(_heap -> m_vector ,iBigest, &Bigest);
	VectorGet(_heap -> m_vector ,iFather, &Father);
			
	if(iBigest != _index)
	{
		VectorSet(_heap -> m_vector , iBigest, Father);
		VectorSet(_heap -> m_vector , iFather, Bigest);	
		Heapify(_heap, iBigest);	
	}
}


static int CheckBigest(Heap* _heap, int _index)
{
void* Father;
void* LeftChild;
void* RightChild;
size_t iFather;
size_t iLeftChild;
size_t iRightChild;

	iFather = _index;
	iLeftChild = LEFT_CHILD( _index);
	iRightChild = RIGHT_CHILD( _index);
	
	if(iRightChild <= _heap -> m_heapSize -1)
	{
		VectorGet(_heap -> m_vector ,iFather, &Father);
		VectorGet(_heap -> m_vector ,iLeftChild, &LeftChild);		
		VectorGet(_heap -> m_vector  ,iRightChild, &RightChild);
		
		if(_heap -> m_checkFunction(Father, LeftChild) == 1 && _heap -> m_checkFunction(Father, RightChild) == 1)
		{
			return iFather;
		}
		else if ( _heap -> m_checkFunction(LeftChild, RightChild) == 1)
		{
			return iLeftChild;
		}
		else
		{
			return iRightChild;
		}	
	}
	
		VectorGet(_heap -> m_vector ,iFather, &Father);
		VectorGet(_heap -> m_vector ,iLeftChild, &LeftChild);
		
		if(_heap -> m_checkFunction(Father, LeftChild) == 1)
		{
			return iFather;
		}
		else 
		{
			return iLeftChild;
		}		
}














