#include <stdio.h>
#include "arr.h"

int check_arr_size(_size)
{
	if(_size > MAX_ARR_SIZE || _size < MIN_ARR_SIZE)
	{
		return ERR_ARR_SIZE;
	}
		return OK;
}



float ave_arr(int _arr[],int _size)
{
int index;
float sum = 0;
float average;
int check_arr = 0;
int check_par = 0;

   check_arr = check_arr_size(_size);
   if (check_arr == 0)
   {
   		return ERR_ARR_SIZE;
   }
   
   for(index = 0; index < _size; index++)
   {
   		sum = sum + _arr[index];
   }

   average = sum/_size;
   
return average;
}



int occur (int _arr[],int _size)
{
int index;
int index2;
int countarr[MAX_ARR_SIZE] = {0,0,0,0,0,0,0,0,0,0};
int max;
int maxindex;
int check_arr = 0;

   check_arr = check_arr_size(_size);
   if (check_arr == 0)
   {
   		return ERR_ARR_SIZE;
   }

    for(index = 0; index < _size; index++)
    {
        index2 = index + 1;
        while(index2 < _size)
        {
            if(_arr[index] == _arr[index2])
            {
                countarr[index]++;
            }
            index2++;
        }
    }

    max = countarr[0];
    for (index = 0; index < _size; index++)
    {
      	if(countarr[index] > max)
      	{
          	max = countarr[index];
         	maxindex = index;
      	}
    }

return _arr[maxindex];
}

float ave_arr2(int _arr[],int _size)
{
int index;
float sum = 0;
float average;
int check_arr = 0;
int check_par = 0;
int *p;
p = _arr;

   check_arr = check_arr_size((_size));
   if (check_arr == 0)
   {
   		return ERR_ARR_SIZE;
   }
   
   for(index = 0; index < _size; index++)
   {
   		sum = sum + *( p + index );
   }

   average = sum/_size;
   
return average;
}


int sort (int _arr[],int _size)
{
int index;
int index2;
int sum = 0;
int result[MAX_ARR_SIZE];
int check_arr = 0;
int check_parmeter = 0;

   check_arr = check_arr_size(_size);
   if (check_arr == 0)
   {
   		return ERR_ARR_SIZE;
   }
 
   for(index = 0; index < _size; index++)
    {
       if (_arr[index] != 0 && _arr[index] != 1)
       {
       		check_parmeter = 1;
       }
    }
    
    if( check_parmeter == 1)
    {
    	return ERR_PAR_TYPE;
    }
   

    for(index = 0; index < _size; index++)
    {
        sum = sum + _arr[index];
    }

    for (index = 0; index < (_size - sum); index++)
    {
        result[index] = 0;
    }

    for (index = (_size - sum); index < _size ; index++)
    {
        result[index] = 1;
    }

    for (index2 = 0; index2 < _size; index2++)
    {
            printf("%d",result[index2]);
    }
	     	printf("\n");
}

