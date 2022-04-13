#include <stdio.h>
#include <string.h>
#include <math.h>
#include "str.h"

int main()
{
int x;
char str1 [] = "yakovhananelzaidenberg";
char str2 [] = "hananel";
del_s1_from_s2(str1, str2);

printf("\n");

x = find_str1_in_str2(str1, str2);
printf("%d", x);
}
