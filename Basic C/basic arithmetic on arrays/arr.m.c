#include <stdio.h>
#include "arr.h"

int main()
{
int _arr4 [MAX_ARR_SIZE] = {1,2,3,4,5,6,-5.7,8,9,9};
int _arr2 [MAX_ARR_SIZE] = {1,8,3,6,5,6,7,8,9,9};
int _arr3 [MAX_ARR_SIZE] = {0,0,1,0,0,1,1,0,0,0};

int _arr [MAX_ARR_SIZE] = {1,2,3,4,5,6,-5.7,8,9,9};
float size = ave_arr(_arr,sizeof(_arr)/sizeof(_arr[0]));
printf("%.2f \n",size);


float size4 = ave_arr2(_arr4,(sizeof(_arr4)/sizeof(_arr4[0]);
printf("%.2f \n",size);


int size2 = occur(_arr2,sizeof(_arr2)/sizeof(_arr2[0]));
printf("%d \n",size2);


sort (_arr3, sizeof(_arr3)/sizeof(_arr3[0]));
}

