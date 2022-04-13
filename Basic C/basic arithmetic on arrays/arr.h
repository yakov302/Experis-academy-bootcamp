#include <stdio.h>

#define MAX_ARR_SIZE 10  /*The maximum size the array can have*/
#define MIN_ARR_SIZE 2   /*The minimum size the array can have*/
#define ERR_ARR_SIZE 0   /*Error message in case the array size does not meet the settings*/
#define ERR_PAR_TYPE 0   /*Error message in case one of the elements in the array does not meet the settings*/
#define OK 1             /*Obtained when the array size meets the settings*/

/*
ave_arr function
Description:
The function takes an array of integers and returns their average.
Input parameters:
_arr[]:Array of maximum size of MAX_ARR_SIZE and contains integers.
_size: Array size.
Output:
ERR_ARR_SIZE: In case the size of the array does not meet the definitions.
average: Average of all values in the array
*/
float ave_arr(int _arr[],int _size);

/*
occur function
Description:
The function receives an array of numbers and returns the number that appears most often.
Input parameters:
_arr[]:Array of maximum size of MAX_ARR_SIZE and contains numbers.
_size: Array size.
Output:
ERR_ARR_SIZE: In case the size of the array does not meet the definitions.
_arr[maxindex]: The number that appears most often in the array.
*/
int occur (int _arr[],int _size);

/*
sort function
Description:
The function accepts an array of only 0 or 1 and returns the same array so that all the zeros are printed first and only then will the 1 be printed.
Input parameters:
_arr[]:Array of maximum size of MAX_ARR_SIZE and contains only 0 or 1.
_size: Array size.
Output:
ERR_ARR_SIZE: In case the size of the array does not meet the definitions.
ERR_PAR_TYPE: In case one of the members is different from 0 or 1.
result[index2]: Arranged array, zeros first and then 1.
*/
int sort (int _arr[],int _size);

float ave_arr2(int _arr[],int _size);

