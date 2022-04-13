#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct byte
{
unsigned char right:4;
unsigned char left:4;
};



int IsBeatOnPrint(unsigned int _bit, int _n)
{
int check;
check  = _bit & (1 << _n);

	if(check == 0)
	{
		printf("0");
		return 0;
	}
	else
	{
		printf("1");
		return 1;
	}
}

int IsBeatOn(unsigned int _bit, int _n)
{
int check;
check  = _bit & (1 << _n);

	if(check == 0)
	{
		
		return 0;
	}
	else
	{
		
		return 1;
	}
}

int HowManyBitsOn(unsigned int _bit)
{
int count = 0;
int i;

	for (i = 7; i > -1 ; i--)
	{
		if(IsBeatOn(_bit, i) == 1)
		{
			count++;
		}
	}

	printf("\n%d Bit are ON!\n",count );
	return count;
}

int InverseBits(unsigned char _bit)
{
int i;
	printf("x = ");
	for (i = 7; i > -1 ; i--)
	{
		IsBeatOnPrint(_bit, i);	
	}
	
	printf("\nx inverted = ");
	for (i = 7; i > -1 ; i--)
	{
		if(IsBeatOn(_bit, i) == 0)
		{
			_bit|=(1<<i);		
		}
		else
		{
			_bit&=~(1<<i);	
		}

		IsBeatOnPrint(_bit, i);		
	}
	printf("\n");
}

int SpinBits(unsigned char _bit, int _n)
{
int i;
unsigned char rotateBit;

	printf("x = ");
	for (i = 7; i > -1 ; i--)
	{
		IsBeatOnPrint(_bit, i);	
	}
	
	printf("\nx rotated by %d = ", _n);
	for (i = 0; i < _n ; i++)
	{
		if(IsBeatOn(_bit, 7) == 0)
		{
			rotateBit = _bit >> 1;
			rotateBit&=~(1<<7);
			_bit = rotateBit;			
		}
		else
		{
			rotateBit = _bit >> 1;
			rotateBit|=(1<<7);
			_bit = rotateBit;		
		}		
	}
	
	for (i = 7; i > -1 ; i--)
	{
		IsBeatOnPrint(rotateBit, i);	
	}
	printf("\n");
}

int Experislanguage(char _str[])
{
int i;
int j;
int k = 0;
int len = strlen(_str);
struct byte* b;


	for(i = 0; i < len; i++)
	{
		if(_str[i] > 'o' || _str[i] < 'a')
		{
			printf("invalid characters");
			return;
		}	
	}

	for (i =  0 ; i < len -1  ; i = i + 2)
	{
		b = &_str[k];
		b -> left  = _str[i] - 'a' + 1;
		b -> right = _str[i + 1] - 'a' + 1;
		k++;
	}
	_str[k] = '\0';
	

	for (i = 0; i < len/2 ; i++)
	{
		for (j = 7; j > -1 ; j--)
		{
			IsBeatOnPrint(_str[i] , j);
		}
		printf(" ");
	}
	printf("\n");	
}


int main()
{
char str [] = "abcdefghijklmnoo";
printf("HowManyBitsOn function:");
HowManyBitsOn(240);
printf("\nInverseBits function:\n");
InverseBits(240);
printf("\nSpinBits function:\n");
SpinBits(167,3);
printf("\nExperislanguage function:\n");
Experislanguage(str);

}
