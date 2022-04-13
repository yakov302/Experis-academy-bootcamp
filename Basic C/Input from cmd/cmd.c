#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int my_atoi(char *_str)
{

int num = 0;
int negative = 0;
int digit;
int i = 0;
int plus = 0;
int counter = 0;

	if(strlen(_str) < 1)
	{
		return 0;
	}
	
	if(_str[0]=='-')
	{
		negative = 1;
	}
	
	if(negative == 1 || _str[0]=='+')
	{
		i = 1;
	}

	while(_str[i]>='0' && _str[i]<= '9')
	{ 
				
		digit = _str[i]-'0';
		num = (num*10) + digit;
		i++;
	}
	

	 if (negative == 1)
 	{
  		return (-1*num);
    }
    
return num;

}


int main (int argc, char* argv[])
{

int x;
int y;
	if(argc < 3)
	{
		printf("Too few parameters");
		return;
	}
	
	x = my_atoi(argv[1]);
	y = my_atoi(argv[2]);

	printf("sum: %d\n", x+y);
	printf("multiplication: %d\n", x*y);

}
