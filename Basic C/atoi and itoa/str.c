#include<stdio.h>
#include<string.h>
#include<math.h>
#include "str.h"

int my_atoi(char *_str)
{

int num = 0;
int negative = 0;
int digit;
int i = 0;
int plus = 0;
int counter = 0;
int i2;
int size;

	if(_str == NULL)
	{
		return ERR;
	}
	
	while(_str[i] == ' ')
	{			
		i++;		
	}
	
	if(_str[i]=='-')
	{
		negative = 1;
	}
	
	if(negative == 1 || _str[i]=='+')
	{
		i++;
	}
	
	while(_str[i] == ' ')
	{			
		i++;		
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

char my_itoa(int _num)
{

int digit;
int i = 0;
char num_str [40];
int j = 0;
int count;
int count2;
int i2=0;

		if(_num < 0)
		{
			i++;
			num_str[0] = '-';
			_num = (_num*(-1));
		}
		
		count = _num;
		while(count > 0)
		{ 
			count2 = count % 10;
			count = (count - count2)/10;
			i++;
		}
	
		i2 = i;
	
		while(_num > 0)
		{ 
			digit = _num % 10;
			_num = (_num - digit)/10;
			num_str[i - 1] = (digit + '0');
			i--;
		}
	
   		 for(j = 0 ; j < i2; j++)
   		 {
			printf("%c",num_str[j]);
		 }

}




