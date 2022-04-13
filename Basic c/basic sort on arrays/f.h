#include <stdio.h>
#include<string.h>
#define NULL_ERR 0
#define OK 1
/*Statement of structure*/
struct student
{
char name[20];
int age;
long id;
};

/*Description: The function receives an array of variables from structure type and sorts it by age parameter in each structure.
Input parameters:
_arr[]: array of structure frome struct student type.
_size: array size.
Output parameters:
NULL_ERR: If the array is equal to NULL.
OK: If the function sorted the array successfully.*/
int Sort_by_age (struct student _arr[],int _size);

/*Description: The function receives an array of variables from structure type and sorts it by name parameter in each structure.
Input parameters:
_arr[]: array of structure frome struct student type.
_size: array size.
Output parameters:
NULL_ERR: If the array is equal to NULL.
OK: If the function sorted the array successfully.*/
int Sort_by_name (struct student _arr[],int _size);
