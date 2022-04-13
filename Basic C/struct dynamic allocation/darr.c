#include <stdio.h>
#include <stdlib.h>
#include "darr.h"

darr *create (size_t size, int block_size)
{
	darr *ptr;
	
	if (size == 0 || block_size < 0)
	{
		return NULL;
	}
		
	/*Allocation memory to structure*/
	if((ptr = ((darr*)malloc(sizeof(darr)))) == NULL)
	{
		return NULL;
	}
	/*Allocation memory to array*/
	if (( ptr -> d_array = ((int*) malloc(size * sizeof(int)))) == NULL)
	{
		free(ptr);
		return NULL;
	}
	/*Entering values to the structure parameters*/
	ptr -> d_array_size = size;
	ptr -> d_array_block_size = block_size;
	ptr -> num_of_elements =0;
	
	return ptr;
}


enum error insert (darr *ptr, int data)
{
int *temp_d_array;

	if(ptr == NULL)
	{
		return NULL_ERR;
	}

	if((ptr -> num_of_elements) < (ptr -> d_array_size) )
	{
		ptr -> d_array[ptr -> num_of_elements] = data;
		ptr -> num_of_elements++;
	}

	else
	{
		if(ptr -> d_array_block_size == 0)
		{
			return OVER_FLOW_ERR;
		}
		
		temp_d_array = (int*)realloc(ptr -> d_array, (ptr -> d_array_size + ptr -> d_array_block_size) * sizeof(int));
		if(temp_d_array == NULL)
		{
			return NULL_ERR;
		}
		
		ptr -> d_array = temp_d_array;
		ptr -> d_array_size = (ptr -> d_array_size + ptr -> d_array_block_size);
		ptr -> d_array[ptr -> num_of_elements] = data;
		ptr -> num_of_elements++;
	}
	return OK;
}
 
 
enum error delete(darr *ptr, int *data)
{
	if(ptr == NULL || data == NULL)
	{
		return NULL_ERR;
	}
	if (ptr -> num_of_elements == 0)
	{
		return UNDER_FLOW_ERR;
	}
	else
	{
		*data =  ptr -> d_array [ptr -> num_of_elements - 1];
		ptr -> num_of_elements--;
		return OK;
	}
}


int destroy (darr *ptr)
{
	if(ptr == NULL)
	{
		return NULL_ERR;
	}
	/*Release allocation of the array and the structure */
	free (ptr -> d_array);
	free(ptr);
}















