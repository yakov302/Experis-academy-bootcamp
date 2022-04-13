#include <stdio.h>
#include <stdlib.h>
#include "hash.set.h"
#define EMPTY_AND_CLEAN 0
#define EMPTY_AND_NOT_CLEAN 1
#define NOT_EMPTY 2
#define EQUAL_ELEMENTS 1
#define NOT_EQUAL_ELEMENTS 0
#define ELEMENT_FOUND 1
#define ELEMENT_NOT_FOUND 0

/*************************structHash****************************/

struct Hash
{
void** m_data;
char* m_state;                  
HashFunction m_HashFunction;
EqualityFunction m_EqualityFunction;
size_t m_hashSize;
size_t m_capacity;
size_t m_numOfItem;
size_t m_maxOfRehashOperations;
size_t m_countOfInsertions;
size_t m_allRehashOperations;
};

/**********************FunctionSignatures*************************/

static size_t CalculateCapacity(size_t _size);
static HashSetResult InsertByRehash(Hash* _hash, void* _data, size_t _index);
static size_t Rehash(size_t _index, size_t _capacity);
static HashSetResult RemoveByRehash(Hash* _hash, void* _key, void** _data, size_t _index);
static int FoundByRehash(const Hash* _hash, void* _key, size_t _index);

/*************************HashCreate*****************************/

Hash* HashCreate(size_t _size, HashFunction _HashFunction, EqualityFunction _EqualityFunction)
{
Hash* hash;
size_t capacity;

	if(_HashFunction == NULL || _EqualityFunction == NULL || _size == 0)
	{
		return NULL;
	}
	
	if((hash = ((Hash*)malloc(sizeof(Hash)))) == NULL)
	{
        	return NULL;
   	}
   	
   	capacity = CalculateCapacity(_size);
   	
   	if ((hash -> m_data = ((void**) malloc(capacity * sizeof(void*)))) == NULL)
	{
		free(hash);
		return NULL;
	}
	
	if((hash -> m_state = ((char*)calloc(capacity , sizeof(char)))) == NULL)
	{
		free(hash -> m_data);
		free(hash);
        	return NULL;
   	}
   		
	hash -> m_HashFunction = _HashFunction;
	hash -> m_EqualityFunction = _EqualityFunction;
	hash -> m_hashSize = _size;
	hash -> m_capacity = capacity;
	hash -> m_numOfItem = 0;
	hash -> m_maxOfRehashOperations = 0;
	hash -> m_countOfInsertions = 0;
	hash -> m_allRehashOperations = 0;

return hash;
}

static size_t CalculateCapacity(size_t _size)
{
size_t capacity;
int index;
int prime;
int flag;

	capacity = _size * 1.3;
	prime = capacity;
	while(1)
	{
		flag = 0;
		
		for (index = 2; index < prime; index++)
		{
			if(prime % index == 0)
			{
				flag = 1;
				index = prime;
			}
 		}
 		
 		if(flag == 0){break;}
 		
 		prime++;
	}
		
return prime;
}

/*************************HashDestroy*****************************/

void HashDestroy(Hash** _hash, keyDestroy _keyDestroy)
{
int i;
int countr = 0;

	if(_hash == NULL || *_hash == NULL)
	{
		return;
	}
	
	if(_keyDestroy != NULL)
	{
		for(i = 0; i < (*_hash) -> m_capacity; i++)
		{
			if((*_hash) -> m_state[i] == NOT_EMPTY)
			{
				_keyDestroy((*_hash) -> m_data[i]);
				countr++;
			}
			if(countr >= (*_hash) -> m_numOfItem) {break;}
		}
	}
	
	free((*_hash) -> m_state);
	free((*_hash) -> m_data);
	free(*_hash);
	*_hash = NULL;
}

/*************************HashInsert*****************************/

HashSetResult HashInsert(Hash* _hash, void* _data)
{
size_t index;

	if(_hash == NULL || _data == NULL)
	{
		return SET_UNINITIALIZED;	
	}
	
	if(_hash -> m_numOfItem >= _hash -> m_hashSize)
	{
		return SET_OVERFLOW;
	}
	
	index = _hash -> m_HashFunction(_data)%_hash -> m_capacity;
	
	if( _hash -> m_state[index] == EMPTY_AND_CLEAN)
	{
		 _hash -> m_data[index] = _data;
		 _hash -> m_state[index] = NOT_EMPTY;
		 _hash ->  m_numOfItem++;
		 _hash ->  m_countOfInsertions++;
		 return SET_SUCCESS;		 
	}
	
	if(HashIsFound(_hash, _data) == ELEMENT_FOUND)
	{
		return SET_KEY_DUPLICATE;
	} 
	
return InsertByRehash(_hash, _data, index);	
}


static HashSetResult InsertByRehash(Hash* _hash, void* _data, size_t _index)
{
size_t numOfRehash = 0;
size_t index = _index;
size_t RehashIndex;
int countr = 0;

	
	while(countr < _hash -> m_capacity - 1)
	{
		RehashIndex =  Rehash(index, _hash -> m_capacity);
		numOfRehash++;
		if( _hash -> m_state[RehashIndex] != NOT_EMPTY)
		{
			_hash -> m_data[RehashIndex] = _data;
			_hash -> m_state[RehashIndex] = NOT_EMPTY;
			_hash ->  m_numOfItem++;
			_hash ->  m_countOfInsertions++;
			_hash -> m_allRehashOperations += numOfRehash;
			if(_hash -> m_maxOfRehashOperations < numOfRehash)
			{_hash -> m_maxOfRehashOperations = numOfRehash;}
			 return SET_SUCCESS;
		}
		
		index = RehashIndex;
		countr++;
	}
	
return SET_OVERFLOW;	
}

static size_t Rehash(size_t _index, size_t _capacity)
{
	return (_index + 1)%_capacity;
}


/*************************HashRemove*****************************/

HashSetResult HashRemove(Hash* _hash, void* _key, void** _data)
{
size_t index;

	if(_hash == NULL || _data == NULL || *_data == NULL || _key == NULL)
	{
		return SET_UNINITIALIZED;	
	}
	
	index = _hash -> m_HashFunction(_key)%_hash -> m_capacity;

	if(_hash -> m_EqualityFunction(_key,  _hash -> m_data[index]) == EQUAL_ELEMENTS)
	{
		*_data = _hash -> m_data[index];
		_hash -> m_data[index] = NULL;
		_hash -> m_state[index] = EMPTY_AND_NOT_CLEAN;
		_hash ->  m_numOfItem--;
		 return SET_SUCCESS;
	}

return RemoveByRehash(_hash, _key, _data, index);	
}

static HashSetResult RemoveByRehash(Hash* _hash, void* _key, void** _data, size_t _index)
{
size_t index = _index;
size_t RehashIndex;
int countr;

	
	while(_hash -> m_state[index] != EMPTY_AND_CLEAN)
	{
		RehashIndex =  Rehash(index, _hash -> m_capacity);
		if(_hash -> m_state[RehashIndex] == NOT_EMPTY)
		{
			if(_hash -> m_EqualityFunction(_key,  _hash -> m_data[RehashIndex]) == EQUAL_ELEMENTS)
			{
				*_data = _hash -> m_data[RehashIndex];
				_hash -> m_data[RehashIndex] = NULL;
				_hash -> m_state[RehashIndex] = EMPTY_AND_NOT_CLEAN;
				_hash ->  m_numOfItem--;
				 return SET_SUCCESS;
			}
		}
		
		countr++;
		if(countr > _hash -> m_maxOfRehashOperations){break;}
		index = RehashIndex;
	}
	
return SET_KEY_NOT_FOUND;
}

/*************************HashIsFound*****************************/

int HashIsFound(const Hash* _hash, void* _key)
{
size_t index;

	if(_hash == NULL || _key == NULL)
	{
		return ELEMENT_NOT_FOUND;	
	}
	
	index = _hash -> m_HashFunction(_key)%_hash -> m_capacity;

	if(_hash -> m_EqualityFunction(_key,  _hash -> m_data[index]) == EQUAL_ELEMENTS)
	{
		 return ELEMENT_FOUND;
	}

return FoundByRehash(_hash, _key, index);	
}

static int FoundByRehash(const Hash* _hash, void* _key, size_t _index)
{
size_t index = _index;
size_t RehashIndex;
int countr;
	
	while(_hash -> m_state[index] != EMPTY_AND_CLEAN)
	{
		RehashIndex =  Rehash(index, _hash -> m_capacity);
		if(_hash -> m_state[RehashIndex] == NOT_EMPTY)
		{
			if(_hash -> m_EqualityFunction(_key,  _hash -> m_data[RehashIndex]) == EQUAL_ELEMENTS)
			{
				 return ELEMENT_FOUND;
			}
		}
		
		countr++;
		if(countr > _hash -> m_maxOfRehashOperations){break;}
		index = RehashIndex;
	}
	
return ELEMENT_NOT_FOUND;
}

/*************************HashNumOfItem*****************************/

size_t HashNumOfItem(const Hash* _hash)
{
	if(_hash == NULL)
	{
		return 0;
	}

return _hash -> m_numOfItem;
}

/*************************HashCapacity*****************************/

size_t HashCapacity(const Hash* _hash)
{
	if(_hash == NULL)
	{
		return 0;
	}
	
return _hash -> m_hashSize;
}

/*************************HashAverageRehashes*****************************/

double HashAverageRehashes(const Hash* _hash)
{
	if(_hash == NULL)
	{
		return 0;
	}

return _hash -> m_allRehashOperations / _hash ->  m_countOfInsertions;
}

/*************************HashMaxEeHash*****************************/

size_t HashMaxEeHash(const Hash* _hash)
{
	if(_hash == NULL)
	{
		return 0;
	}
	
return _hash -> m_maxOfRehashOperations;
}

/*************************HashPrint*****************************/

void HashPrint(const Hash* _hash, PrintKey _PrintKey)
{
size_t countr = 0;
size_t index = 0;

	while(countr < _hash -> m_numOfItem)
	{
		if(_hash -> m_state[index] == NOT_EMPTY)
		{
			_PrintKey(_hash -> m_data[index]);
			countr++;
		}
		
		index++;
	}
}











