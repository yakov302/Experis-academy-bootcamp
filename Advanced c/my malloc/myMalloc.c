#include <stdio.h>
#include <stdlib.h>
#include "myMalloc.h"
#define LONG_SIZE 8
#define THREE_LONG 24
#define TRUE 1

/*********************FunctionSignatures********************/

static size_t CalculateMallocSize(size_t _requiredBlockSize);

/***********************MyMallocInit************************/

void MyMallocInit(void* _memory, size_t _memorySize)
{
long* start = (long*) _memory;
char* startChar = (char*) _memory;

	if(_memory == NULL || _memorySize < 32)
	{
		return;
	}
	
 	*start = _memorySize;
 	*(start + 1) = _memorySize - THREE_LONG;
 	start = (long*)(startChar + (_memorySize - LONG_SIZE));
 	*start = 0;
}

/**************************MyMalloc*************************/

void* MyMalloc(void* _memory, size_t _requiredBlockSize)
{
long* MetaData = (long*) _memory;
size_t mallocSize;
MetaData++;
	
	while(*MetaData != 0)
	{
		mallocSize = CalculateMallocSize( _requiredBlockSize);

		if(*MetaData > 0 &&  mallocSize <= *MetaData)
		{				
			*(MetaData + 1 + (mallocSize/LONG_SIZE)) = *MetaData - mallocSize - LONG_SIZE;
			*MetaData = mallocSize*(-1);	
			MetaData++;
			return MetaData;						
		}
		
		if(*MetaData > 0)
		{
			MetaData = MetaData + 1 + *MetaData/LONG_SIZE;
		}
		else
		{
			MetaData = MetaData + 1 + ((*MetaData)*(-1))/LONG_SIZE;
		}			
	}

return NULL;
}

static size_t CalculateMallocSize(size_t _requiredBlockSize)
{
size_t mallocSize =  _requiredBlockSize;

	while(TRUE)
	{
		if(mallocSize%8 == 0)
		{
			return mallocSize;
		}
		mallocSize++;
	}
}

/**************************MyFree*************************/

void MyFree(void* _myBlock)
{
long* MetaData = (long*) _myBlock;
long* NextMetaData;
MetaData--;
	
	if(_myBlock == NULL)
	{
		return;
	}	
	
	if(*MetaData >= 0)
	{
		printf("free(): double free detected\nAborted (core dumped)\n:-)\n");
		return;
	}
	
	NextMetaData = MetaData + 1 + (((*MetaData)*(-1))/LONG_SIZE);
	
	if(*NextMetaData > 0)
	{
		*MetaData = (*MetaData)*(-1) + *NextMetaData + LONG_SIZE;	
		*NextMetaData = 0;
	}
	else
	{
		*MetaData = (*MetaData)*(-1);
	}
}











