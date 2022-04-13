#include <stdio.h>
#include <math.h>
#define SIZE_ERR 0
#define OK 1


/*sort function
Description:The function receives an unsorted array and sort it in ascending order - from the smallest to the largest.
Input variable:
_arr[]: Unsorted array.
_size: Array size.
Output variable:
SIZE_ERR: Size error if the array is smaller than 1.
OK: If the length of the array is ok and the sorting is done.*/
int sort(int _arr[],int _size);

/*sort function
Description:The function receives an array of even and odd numbers and sorts it so that first the even numbers appear and only then the odd numbers. The sorting maintains the internal order of the even and the odd.
Input variable:
_arr[]: Unsorted array.
_size: Array size.
Output variable:
SIZE_ERR: Size error if the array is smaller than 1.
OK: If the length of the array is ok and the sorting is done.*/
int Sort_by_even_and_odd (int _arr[],int _size);

/*sort function
Description:The function receives a sorted array of numbers in ascending order - from the smallest to the largest and searches for a particular value within the array through binary search.
Input variable:
_arr[]: Unsorted array.
_size: Array size.
_search_number: the value that the function looks for in the array.
Output variable:
SIZE_ERR: Size error if the array is smaller than 1.
middle: The index in the array of the value (_search_number) we were looking for.*/
int binar_search(int _arr[], int _size,int _search_number);
