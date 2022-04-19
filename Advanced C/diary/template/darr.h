#include <stdio.h>
#include <stdlib.h>

/*return messages*/
enum error {UNDER_FLOW_ERR = -2, 
			OVER_FLOW_ERR = -1, 
			NULL_ERR =0, 
			OK =1};

/*dynamic memory allocation structure declaration*/
struct DynamisArray
{
	int *d_array;
	int d_array_size;
	int d_array_block_size;
	int num_of_elements;
};

/*new name to the structure type*/
typedef struct DynamisArray darr;


/*create function description:
1. Creates a memory allocation for a structure that contains objects that managing the memory allocation.
2. creates memory allocation for array of int.
3.insert values to the structure elements of the structure:
d_array_size: Array size, comes as input - first parameter in the function.
d_array_block_size: size of the array increases (if necessary) comes as input - the second parameter in the function.
num_of_elements: gets the value 0.

input parameters:
size: Array size.
block_size:Size of the array increases (if necessary).

output parameter:
NULL: if the array size is equal to 0, or if the array increases size is less than 0, or if the memory allocations failed.
ptr: pointer to the structure if the allocations were made successfully.*/
darr *create (size_t size, int block_size);


/*insert function description:
1. checks if the size of elements is smaller than the size allocated to the array, and if is smaller, insert "data" to the array and increases the number of elements by 1;
2. if number of elements equal to the array size allocation, the function:
re-allocates the size and saves it in a temporary pointer "temp_d_array".
if the allocation is performed successfully:
the new pointer is inserted into the original pointer "d_array".
the new size is inserted into the size variable "d_array_size".
"data" insert to the array.
number of elements increases the by 1.

input parameters:
*ptr: pointer to the structure.
data: the value that needs to enter the array.

output parameter:
NULL_ERR: if the *ptr pointer is equal to NUUL or if the re-allocation failed (return NULL).
OVER_FLOW_ERR: if re-allocation is needed and the size of array increasesis equal to 0.
OK: if the value of "data" variable enters the array*/
enum error insert (darr *ptr, int data);


/*delete function description:
insert the last member in the array into pointer "data" and decrease the number of elements by 1. 

input parameters:
*ptr: pointer to the structure.
*data: pointer to "data" variable, the last element of the array will be inserted into it.

output parameter:
NULL_ERR: if the *ptr pointer is equal to NUUL.
UNDER_FLOW_ERR: If the number of elements is 0.
OK: If the last element in the array insert to "data" and the number of elements decreases by 1*/
enum error delete(darr *ptr, int *data);


/*destroy function description:
Release allocation of the array and the structure.

input parameters:
*ptr: pointer to the structure.

output parameter:
NULL_ERR: if the *ptr pointer is equal to NUUL.*/

int destroy (darr *ptr);



















