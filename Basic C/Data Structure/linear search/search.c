#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortingAlgorithms.h"
#include "enum.h"
#define ARR_SIZE 80000

linearSearch(int _arr[], int _size, int _num)
{
int i;
	for (i = 0; i < _size; i++)
	{
		if(_arr[i] == _num)
		{
			return 1;
		}
	}
return 0;
}

linearSearchImproved(int _arr[], int _size, int _num)
{
int i;
int temp;
	
	if(_num == _arr[_size - 1])
	{
		return 1;
	}
	
	temp = _arr[_size - 1];
	_arr[_size - 1] = _num;
	
	for (i = 0; ; i++)
	{
		if(_arr[i] == _num)
		{
			if(i != _size - 1)
			{
				_arr[_size - 1] = temp;
				return 1;
			}
			_arr[_size - 1] = temp;
			return 0;
		}
	}
	
_arr[_size - 1] = temp;
return 0;
}

main()
{
clock_t linearStart;
clock_t linearEnd;
clock_t linearTotal;
clock_t linearImprovedStart;
clock_t linearImprovedEnd;
clock_t linearImprovedTotal;
int baseArr[ARR_SIZE];
int i;

	for (i = 0; i < ARR_SIZE; i++)
	{
		baseArr[i] = rand()%ARR_SIZE;
	}
	

linearStart = clock();
	
for(i = 0; i < 20000; i++)
{
linearSearch(baseArr, 80000, 234567);
}

linearEnd = clock();
linearTotal = linearEnd - linearStart;



linearImprovedStart = clock();

for(i = 0; i < 20000; i++)
{
linearSearchImproved(baseArr, 80000, 234567);
}

linearImprovedEnd = clock();
linearImprovedTotal = linearImprovedEnd - linearImprovedStart;



printf("linearTotal:         %f\n", (double)linearTotal/1000000);
printf("linearImprovedTotal: %f\n", (double)linearImprovedTotal/1000000);

}
