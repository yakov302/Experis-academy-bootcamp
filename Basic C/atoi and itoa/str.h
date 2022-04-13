#include<stdio.h>
#include<string.h>
#include<math.h>
#define ERR 0

/*Description:function that receives a string and returns a number.
input variable:
_str:string variable that contains digits.
output variable: 
"123" --> 123
"-123" --> -123
"123 55" --> 123
"+123" --> 123
"123abc" --> 123
"abc123" --> 0*/
int my_atoi(char *_str);

/*Description: function that accepts a positive or negative number and returns it as a string.
input variable:
_num: Positive or negative number.
output variable: 
num_str: String with all digits (minus sign in case of negative number).*/
char my_itoa(int _num);
