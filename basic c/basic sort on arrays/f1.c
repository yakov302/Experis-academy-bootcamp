#include <stdio.h>
#include<string.h>
#include "f.h"

int Sort_by_age (struct student _arr[],int _size)
{
int index;
int check = 0;
int  hold;
int j;
	
	if (_arr == NULL)
	{
		return NULL_ERR;
	}
	
	
    while (check == 0)
    {
         for (index = 0; index < _size; index++)
        {
               if(_arr[index].age > _arr[index + 1].age)
                {
                    hold = _arr[index].age;
                    _arr[index].age = _arr[index + 1].age;
                    _arr[index + 1].age = hold;
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
    
  /* return OK;*/
 
  for(j = 0; j <= _size; j++)
  {
  	printf("%d\n", _arr[j].age);
  }

}


int Sort_by_name (struct student _arr[],int _size)
{

int index;
int check = 0;
struct student hold;
int j;
	
	if (_arr == NULL)
	{
		return NULL_ERR;
	}
	

    while (check == 0)
    {
         for (index = 0; index < _size; index++)
        {
               if(strcmp(_arr[index].name, _arr[index + 1].name) > 0)
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
    
  /* return OK;*/
  
  for(j = 0; j <= _size; j++)
  {
  	printf("%s\n", _arr[j].name);
  }

}




























