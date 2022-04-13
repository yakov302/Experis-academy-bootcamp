#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SYMMETRICAL 1
#define NOT_SYMMETRICAL 0



double AverageArr(int _arr[], int _size)
{
double average;

	if(_size == 1)
	{
		return _arr[0];
	}
	
	average = AverageArr(_arr, _size - 1);
	average = average * (_size - 1);
	return (double)((average + _arr[_size - 1])/_size);
}

FlipArr(int _arr[], int _size)
{
int hold;

	if(_size == 0)
	{
		return;
	}

	hold = _arr[_size];
	_arr[_size ] = _arr[_size-1];
	_arr[_size-1] = hold;
	return FlipArr(_arr, _size - 1);
	
}

int CheckPal(char _str[], int _size, int _start)
{

	if((_size - _start) == 1)
	{
		return SYMMETRICAL;
	}
	
	if(_str[_size - 1] != _str[_start])
	{
		return NOT_SYMMETRICAL;
	}
	else
	{
		return CheckPal(_str, _size - 1, _start + 1);
	}
}


int main()
{

int arr [] = {5,5,5,5};
int x = (sizeof(arr)/sizeof(arr[0]));
FlipArr(arr, x);
printf("%f\n", AverageArr(arr, x));

char str[] = "abcdeffgfedcba";
int y = strlen(str);
printf("%d\n",CheckPal(str, y, 0));



}
