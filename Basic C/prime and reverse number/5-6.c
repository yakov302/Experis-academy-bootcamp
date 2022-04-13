#include <stdio.h>
#define INVALID_PARAMTER -1

int prime_number (int _num)
{

int index;
int prime = 0;

	if (_num < 1)
	{
		return INVALID_PARAMTER;
	}

	for (index = 2; index < _num; index++)
	{
		if(_num % index == 0)
		{
			prime = 1;
		}
 	}
 	
 	if (prime == 1)
 	{
 		return 0;
 	}
 	else
 	{
 		return 1;
 	}
 	
 }
 
 int reverse_number (int _num)
{
int backup;
int remainder;
int reverse = 0;

	backup = _num;

	while(backup > 0)
	{
  		remainder = backup % 10;
  		backup = backup/10;
 		reverse = reverse * 10 + remainder;
	}

return reverse;
	
}	

int main(void)
{

int num;
int num2;
num = prime_number(212);
printf("%d\n",num);
num2 = reverse_number(987654);
printf("%d\n",num2);

}

