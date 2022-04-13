#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bubble.h"

/**************Swap***********/

void Swap(int *arr1, int *arr2)
{
int hold;
       hold = *arr1;
       *arr1 = *arr2;
       *arr2 = hold;
}

/**************bubble***********/

int bubble(int _arr[], int _arrSize, int(*SortCondition)(int, int))
{
int i;
int j;
	if(_arr[] == NULL)
	{
		return 0;
	}
	        
       	for (i = 0; i < _arrSize ; i++)
        {
        	for(j = 0; j < _arrSize - i; j++)
        	{
       			if(SortCondition(_arr[j], _arr[j + 1]) == 1)
       			{
       				Swap(&_arr[j], &_arr[j + 1]);
       			}
       		}
        }
return 1;
} 

