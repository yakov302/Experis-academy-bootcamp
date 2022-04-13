#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "enum.h"
#include "stack.h"



int main()
{
Stack *ptr;
int item;
int x;
char y [] = "hffgh{hjg{[gdh[(gdfgh(gjfdg))]fdgh]}ggdfhg}hjgh";
x = CheckBrackets(y);
printf("%d\n", x);
}
