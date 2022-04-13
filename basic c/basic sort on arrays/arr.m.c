#include <stdio.h>
#include "arr.h"
#include <math.h>

int main(void)
{

int arr [] = {1,2,3,7,8,4,2,5,2,8,4};
int arr1 [] = {6,8,4,6,8,4,5,4,6,5,4};
int x;
int arr3 [] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};

sort(arr,(sizeof(arr)/sizeof(arr[0])));
Sort_by_even_and_odd (arr1, sizeof(arr1)/sizeof(arr1[0]));
x = binar_search (arr3, (sizeof(arr3)/sizeof(arr3[0])),11);
printf("%d",x);

}
