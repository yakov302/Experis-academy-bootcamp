#include <stdio.h>
#include "tf.h"


main ()
{

char _sign;
int _line;

printf("Enter the mark you want to print: \n");
scanf("%c",&_sign);

printf("Enter the number of lines you want to print: \n");
scanf("%d",&_line);

printf("\n\n");
triag1 (_sign, _line);

printf("\n\n");
triag2 (_sign, _line);

printf("\n\n");
triag3 (_sign, _line);

printf("\n\n");
triag4 (_sign, _line);

printf("\n\n");
triag5 (_sign, _line);

printf("\n\n");
triag6 (_sign, _line);

}

