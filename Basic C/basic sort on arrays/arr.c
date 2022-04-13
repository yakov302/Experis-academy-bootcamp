#include <stdio.h>
#include <math.h>
#include "arr.h"

int size_check (_size)
{
	if (_size < 1)
	{
		return SIZE_ERR;
	}
	else
	{
		return OK;
	}
}


int sort(int _arr[],int _size)
{
int index;
int index2;
int check = 0;
int  hold;
int check_size;

	check_size = size_check (_size);
	if (check_size == 0)
	{
		return SIZE_ERR;
	}

    while (check == 0)
    {
         for (index = 0; index < _size; index++)
        {
               if(_arr[index] > _arr[index + 1])
                {
                    hold = _arr[index];
                    _arr[index] = _arr[index + 1];
                    _arr[index + 1] = hold;
                    check += 1;
                }
        } 
        
      	if (check != 0)
      	{
      		check = 0;
      	}
      	else
      	{
      		check = 1;
      	}
    }
    
  return OK;
     
}



int Sort_by_even_and_odd (int _arr[],int _size)
{
int index;
int index2;
int check = 0;
int  hold;
int check_size;

	check_size = size_check (_size);
	if (check_size == 0)
	{
		return SIZE_ERR;
	}

    while (check == 0)
    {
         for (index = 0; index < _size; index++)
        {
               if(_arr[index] % 2 != 0 && _arr[index + 1] % 2 == 0)
                {
                    hold = _arr[index];
                    _arr[index] = _arr[index + 1];
                    _arr[index + 1] = hold;
                    check += 1;
                }
        }

      	if (check != 0)
      	{
      		check = 0;
      	}
      	else
      	{
      		check = 1;
      	}
    }
    
   return OK;

}




int binar_search(int _arr[], int _size,int _search_number)
{
int start = 0;
int end = _size - 1;
int middle;
int match = 0;
int check_size;

	check_size = size_check (_size);
	if (check_size == 0)
	{
		return SIZE_ERR;
	}

   while(start <= end)
	{
       if (_arr[middle] == _search_number)
       {
           return middle;       
       }
       else if (_arr[middle] != _search_number)
       {
       	   middle = (end + start)/2;
           if (_arr[middle] < _search_number)
           {
               start = middle + 1 ;
           }
           else if (_arr[middle] > _search_number)
           {
               end = middle - 1;
           }
       }       
	}        
}
























/*
int search(int _arr[], int _size, int _search_number)
{
int start = 0;
int end = _size-1;
int Match = 0;
int result;
int n;


    while(Match == 0 && start < end)
    {
       if(_search_number != _arr[n])
          {		 
              if((end-start) % 2 == 0)
              {
         	  n = ((((end-start)/2)) + start);
         	  }
         	  else 
         	  {
         	  n = ((((end + 1 -start)/2)) + start);
         	  }
              if (_search_number > _arr[n])
                  {
                     start = (end-start)/2;
                  }
                  else if (_search_number < _arr[n])
                  {
                    end = (end-start)/2;
                  }
          }
          else
          {
            result = n;
            Match = 1;
          }
    }

    return result;
}




int find_last_even(int _arr[],int _size)
{
int index ;
int last_even;

    for(index = 0; index < _size; index++)
    {
       if(_arr[index] % 2 == 0)
       {
         last_even =  index;
       }
    }
return last_even;
}

int find_first_odd(int _arr[],int _size)
{
int index;
int first_odd;

    for(index = 0; index < _size; index++)
    {
       if(_arr[index]%2 != 0)
       {
         first_odd =  index;
         index = _size;
       }
    }
return first_odd;
}

int Sort_by_even_and_odd (int _arr[], int _size)
{
int last_even = 1;
int first_odd = 0;
int index;
int hold;

    while(last_even > first_odd)
    {
        last_even = find_last_even( _arr, _size);
        first_odd = find_first_odd( _arr, _size);
        hold = _arr[last_even];
        _arr[last_even] = _arr[first_odd];
        _arr[first_odd] =  hold;

    }

}
*/
