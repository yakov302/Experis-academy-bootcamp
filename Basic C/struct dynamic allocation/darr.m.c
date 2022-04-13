
#include <stdio.h>
#include <stdlib.h>
#include "darr.h"


int main()
{

int data;
darr *ptr;
int i;

ptr = create (10, 10);
printf("Elements of structure after creat 10x10: \n");
printf("d_array_size: %d\n", ptr -> d_array_size);
printf("d_array_block_size: %d\n", ptr -> d_array_block_size);
printf("num_of_elements: %d\n", ptr -> num_of_elements);

printf("\n\n"); 

for (i = 0; i < 5; i++)
{
insert (ptr, 5);
}

printf("Print 5 organs inserted into the array:\n");
for (i = 0; i < 5; i++)
{
printf("d_array[%d]: %d\n", i, ptr -> d_array[i]); 
}

printf("\n\n");

printf("Elements of structure after insret 5x5:\n");
printf("d_array_size: %d\n", ptr -> d_array_size);
printf("d_array_block_size: %d\n", ptr -> d_array_block_size);
printf("num_of_elements: %d\n", ptr -> num_of_elements);

printf("\n\n");
 


printf("insret mor 5x1000 + realloc\n");
for (i = 5; i < 1000; i++)
{
insert (ptr, 5);
}
 printf("Elements of structure after insret mor 5x5 + realloc:\n");
printf("d_array_size: %d\n", ptr -> d_array_size);
printf("d_array_block_size: %d\n", ptr -> d_array_block_size);
printf("num_of_elements: %d\n", ptr -> num_of_elements);


printf("\n\n");
for (i = 5; i < 700; i++)
{
delete(ptr,&data);
}

 printf("Elements of structure after delete 700 time:\n");
printf("d_array_size: %d\n", ptr -> d_array_size);
printf("d_array_block_size: %d\n", ptr -> d_array_block_size);
printf("num_of_elements: %d\n", ptr -> num_of_elements);
 printf("data value:\n");
printf("%d\n", data);

printf("\n\n");

destroy (ptr);
 printf("Elements of structure after destroy \n");
printf("d_array_size: %d\n", ptr -> d_array_size);
printf("d_array_block_size: %d\n", ptr -> d_array_block_size);
printf("num_of_elements: %d\n", ptr -> num_of_elements);



}
















