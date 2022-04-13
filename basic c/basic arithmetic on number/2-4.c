#include <stdio.h>
#define INVALID_PARAMTER 0

int fact (int _num)
{
    if(_num <= 0)
    {
        return INVALID_PARAMTER;
    }

    int index =0;
    int result;
    result = _num;


    while (index < _num - 1)
    {
      result = result * (_num - index - 1);
      index++;
    }

   return result;
}


int pal (int _num)
{
int backup;
int rem;
int rev = 0;

	backup = _num;

	while(backup > 0)
	{
  		rem = backup % 10;
  		backup = backup/10;
 		 rev = rev * 10 + rem;
	}

	if (_num == rev)
	{
  		 return 1;
	}
	else
	{
  		return 0;
	}
}



int order (int _num)
{
int backup;
int mod;
int mod2;

	backup = _num;

	while(backup > 1)
	{
        mod = backup%10;
        backup = (backup - mod)/10;
        mod2 = backup%10;
        if(mod <= mod2)
        {
            return 0;
        }
	}

	return 1;
}


int main(void)
{
int num;
int num_user;
printf("Enter the number for which you want to receive the assembly calculation: \n");
scanf("%d",&num);
num_user = fact(num);
printf("%d\n",num_user);

int num2;
int num_user2;
printf("Enter a number to check if it is PALINDROME: \n");
scanf("%d",&num2);
 num_user2 = pal(num2);
 printf("%d\n",num_user2);
 
int num3;
int num_user3;
printf("Enter the number you want to check: \n");
scanf("%d",&num3);
num_user3 = order (num3);
printf("%d\n",num_user3);
}

