#include <stdio.h>
/*#include<bits>*/
#define BITS_IN_INT sizeof(int) * 8


int isPositive(int _num)
{
   _num &= 1 << BITS_IN_INT -1;
   
return !_num;
}


int EqualNumber(int _a, int _b)
{
int sub;
int isPos;

	sub = _a - _b;
	isPos = isPositive(sub);
	
return isPos*_a + (!isPos)*_b;
}

int main()
{
printf("\nisPositive: %d\n", isPositive(-30));
printf("\nEqualNumber: %d\n", EqualNumber(634, 875));

}

