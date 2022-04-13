#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bubble.h"

/**************Swap***********/

void static GenSwap(void *_data1, void *_data2, size_t _elementSize)
{
void* hold = (void*) malloc(_elementSize);
	
	memcpy(hold, _data1, _elementSize);
	memcpy( _data1, _data2, _elementSize);
	memcpy( _data2, hold, _elementSize);
free(hold);
}

/**************bubble***********/

int GenBubble(void* _data, size_t _numOfElement, size_t _elementSize, int(*SortCondition)(void*, void*))
{
int i;
int j;
int flag;

	if(_data == NULL)
	{
		return 0;
	}
	        
       	for (i = 0; i < _numOfElement - 1; i++)
        {
        	flag == 0;
        	for(j = 0; j < _numOfElement - 1 - i; j++)
        	{
       			if(SortCondition(((char*) _data + (j*_elementSize)) , ((char*) _data + ((j + 1)* _elementSize))) == 1)
       			{
       				GenSwap((char*)_data + (j*_elementSize), (char*) _data + ((j + 1)* _elementSize), _elementSize);
       				flag == 1;
       			}
       		}
       		if(flag == 0){break;}
        }
return 1;
} 

