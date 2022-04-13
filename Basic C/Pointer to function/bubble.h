#ifndef __SWAP_H__
#define __SWAP_H__

/*Description:
The function performs bubble dort when the sort conditions are obtained using a pointer to an external function.

Input variables;
_arr[]: Array of integers.
_arrSize:Array size.
int(*SortCondition)(int, int): 	Pointer to an external function that checks if the sorting conditions are met.

Output parameters:
0: if _arr[] is NULL.
1: If the sort done successfully*/
int bubble(int _arr[], int _arrSize, int(*SortCondition)(int, int));
















#endif /*#ifndef__SWAP_H__*/
