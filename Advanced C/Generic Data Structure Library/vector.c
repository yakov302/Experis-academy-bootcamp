#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#define REDUCTION_CRITERION 2

/***struct Vector***/

struct Vector
{
void **m_items;
size_t m_originalSize;
size_t m_size;
size_t m_nItems;
size_t m_blockSize;
};

/******************************FunctionSignatures*******************************/

static VectorResult VectorReallocIncreases (Vector* _vector);
static void CheckVectorReallocDecreases(Vector* _vector);

/*********************************VectorCreate**********************************/

Vector *VectorCreate (size_t _initialSize, size_t _extensionBlockSize)
{
Vector *vector;
	
	if (_initialSize == 0 && _extensionBlockSize == 0)
	{
		return NULL;
	}
	
	if((vector = ((Vector*)malloc(sizeof(Vector)))) == NULL)
	{
		return NULL;
	}

	if (( vector -> m_items = ((void**) malloc(_initialSize * sizeof(void*)))) == NULL)
	{
		free(vector);
		return NULL;
	}

	vector -> m_originalSize = _initialSize;
	vector -> m_size = _initialSize;
	vector -> m_nItems = 0;
	vector -> m_blockSize = _extensionBlockSize;
	
return vector;
}

/*********************************VectorDestroy**********************************/

void VectorDestroy (Vector** _vector, void(*_elementDestroy)(void* _item))
{
size_t i;
	if(_vector == NULL || *_vector == NULL)
	{
		return;
	}
	
	if(_elementDestroy != NULL)
	{
		for(i = 0; i < (*_vector)-> m_nItems ; i++)
		{
			(*_elementDestroy)((*_vector) -> m_items[i]);
		}
	}
	
	free ((*_vector) -> m_items);
	free(*_vector);
	*_vector = NULL;
}

/*********************************VectorAppend**********************************/

VectorResult VectorAppend (Vector* _vector,void* _item)
{

	if(_vector == NULL || _item == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}

	if((_vector -> m_nItems) >= (_vector -> m_size))
	{
		if(_vector -> m_blockSize == 0)
		{
			return VECTOR_OVERFLOW_ERROR;
		}
		if(VectorReallocIncreases(_vector) == VECTOR_UNITIALIZED_ERROR)
		{
			return VECTOR_UNITIALIZED_ERROR;
		}
	}
	
	_vector -> m_items[_vector -> m_nItems] = _item;
	_vector -> m_nItems++;
	
return VECTOR_SUCCESS;
}

static VectorResult VectorReallocIncreases (Vector* _vector)
{

void **temp;

	temp = (void**)realloc(_vector -> m_items, (_vector -> m_size + _vector -> m_blockSize) * sizeof(void*));
	if(temp == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}
		
	_vector -> m_items = temp;
	_vector ->  m_size = _vector ->  m_size + _vector -> m_blockSize;	
}

/*********************************VectorRemove**********************************/

VectorResult VectorRemove(Vector* _vector, void** _item)
{

	if(_vector == NULL || _item == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}
	if (_vector -> m_nItems == 0)
	{
		return VECTOR_OVERFLOW_ERROR;
	}
	
	CheckVectorReallocDecreases( _vector);

	*_item =  _vector -> m_items [_vector -> m_nItems - 1];
	_vector -> m_nItems--;
	
return VECTOR_SUCCESS;
}

static void CheckVectorReallocDecreases(Vector* _vector)
{
void **temp;

	if ((_vector -> m_size) - (_vector -> m_nItems) >= (_vector -> m_blockSize)*REDUCTION_CRITERION && (_vector -> m_size) - (_vector ->  m_blockSize) >= (_vector ->  m_originalSize))
	{
		temp = (void**)realloc(_vector -> m_items, (_vector -> m_size - _vector -> m_blockSize) * sizeof(void*));
		if(temp != NULL)
		{
			_vector -> m_items = temp;
			_vector -> m_size = (_vector -> m_size - _vector -> m_blockSize);		 
		}		
	}	
}
 
/*********************************VectorGet**********************************/

VectorResult VectorGet(const Vector* _vector, size_t _index, void** _item)
{
	if(_vector == NULL || _item == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}
	
	if(_index >= _vector -> m_nItems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}
	
	*_item =  _vector -> m_items[_index];
	
return VECTOR_SUCCESS;
} 

/*********************************VectorSet**********************************/

VectorResult VectorSet(Vector* _vector, size_t _index, void* _item)
{
	if(_vector == NULL || _item == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}
	
	if(_index >=  _vector -> m_nItems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR ;
	}
	
	_vector -> m_items[_index] = _item;
	
return VECTOR_SUCCESS;
} 

/*********************************VectorSize**********************************/

size_t  VectorSize (const Vector* _vector)
{
	if(_vector == NULL)
	{
		return 0;
	}

	return _vector -> m_nItems;
}

/*********************************VectorCapacity**********************************/

size_t  VectorCapacity (const Vector* _vector)
{
	if(_vector == NULL)
	{
		return 0;
	}

	return _vector -> m_size;
}

/*********************************VectorForEach**********************************/

size_t VectorForEach(const Vector* _vector, int(*_vectorElementAction)(void*, size_t , void*), void* _context)
{
size_t i;
void* item;

	if(_vector == NULL || _vectorElementAction == NULL)
	{
		return;
	}

	for(i = 0; i < _vector -> m_nItems; i++)
	{
		VectorGet(_vector, i, &item);
		if(_vectorElementAction(item, i, _context) == 0)
		{
			break;
		}
	}
return i;
}



/************testFunction**************/

int Getm_originalSize (Vector* _vector)
{
	return _vector -> m_originalSize;
} 

size_t Getm_size (Vector* _vector)
{
	return _vector -> m_size;
}
 
size_t Getm_nItems (Vector* _vector)
{
	return _vector -> m_nItems;
} 

size_t Getm_blockSize (Vector* _vector)
{
	return _vector -> m_blockSize;
} 

void* getn(Vector*_vector,  int i)
{
	return _vector -> m_items[i];
}











 


