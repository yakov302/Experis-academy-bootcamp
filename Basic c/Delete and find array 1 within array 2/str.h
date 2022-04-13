#include <stdio.h>
#include <string.h>
#include <math.h>
#define ERR -1

/*Description: The function accepts String 1 and Strind 2 and deletes any character in sting 1 that appears in String 2.
Input variables:
_str1: String 1.
_str2: String 2.
Output variables:
-1: If one of the strings is NULL.
1: If all the characters in String 1 that exist in String 2 have been deleted.*/
int del_s1_from_s2(char* _str1, char* str_2);

/*Description: The function is searches string in string 2 and if it finds returns the position.
Input variables:
_str1: String 1.
_str2: String 2.
Output variables:
-1: If one of the strings is NULL.
-2: If string 1 is not found in string 2.
index: The location of String 1 within String 2.*/
int find_str1_in_str2(char* str1, char* str2);
