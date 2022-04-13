#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
char str [] = "abcdefghijklmnoo";
char* p;
int i = 1;
p = (char*)&i;
 if(*p  == 1)
 {
 	printf("\nLE!\n");
 }
 else
 {
 	 printf("\nBE!\n");
 }



}
