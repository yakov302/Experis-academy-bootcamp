#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"
#define AEE_SIZE 50

/**************Search conditions functions***********/

int SmallToBig(int _arr1, int _arr2)
{
	if(_arr1 > _arr2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BigToSmall(int _arr1, int _arr2)
{
	if(_arr1 < _arr2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ByEvenFirst(int _arr1, int _arr2)
{
	if(_arr1%2 != 0 && _arr2%2 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ByOddFirst(int _arr1, int _arr2)
{
	if(_arr1%2 == 0 && _arr2%2 != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
int i;
int arr [AEE_SIZE];

	for (i = 0; i < AEE_SIZE ; i++)
	{
		arr[i] = rand()%1000;
	}

	bubble(arr, AEE_SIZE - 1, SmallToBig);

	for (i = 0; i < AEE_SIZE ; i++)
	{
	printf("%d\n", arr[i]);
	}
}















