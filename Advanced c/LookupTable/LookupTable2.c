#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_SIZE (sizeof(int)*8) - 1
#define CHAR_SIZE 8 - 1
#define TABLE_SIZE 256
#define BITS_IN_BYTE 8
#define EIGHT_BITS_ON 0xFF

/***********************IsBeatOn**********************/

int IsBeatOnPrint(unsigned int _bit, int _n)
{
int check;
check  = _bit & (1 << _n);

	if(check == 0)
	{printf("0");}
	else
	{printf("1");}
}

int IsBeatOn(unsigned int _bit, int _n)
{
int check;
check  = _bit & (1 << _n);

	if(check == 0)
	{return 0;}
	else
	{return 1;}
}

/***********************ReverseIntBit**********************/

unsigned int ReverseIntBit(unsigned int _num)
{
unsigned int reverse;
int start;
int end;

	reverse = _num;

	for(start = 0, end = INT_SIZE; end > start; start++, end--)
	{
		if(IsBeatOn(reverse, start) != IsBeatOn(reverse, end))
		{
			reverse^=(1<<start);
			reverse^=(1<<end);		
		}	
	}
	
return reverse;	
}

/***********************ReverseCharBit**********************/

unsigned char ReverseCharBit(unsigned char _num)
{
unsigned char reverse;
int start;
int end;
	
	reverse = _num;
	
	for(start = 0, end = CHAR_SIZE; end > start; start++, end--)
	{
		if(IsBeatOn(reverse, start) != IsBeatOn(reverse, end))
		{
			reverse^=(1<<start);
			reverse^=(1<<end);		
		}	
	}

return reverse;
}

/***********************BuildTableOfReverseChar**********************/

void BuildTableOfReverseChar(unsigned char* _reverseCharTable)
{
int i;
	for(i = 0; i < TABLE_SIZE; i++)
	{
		_reverseCharTable[i] = ReverseCharBit(i);
	}
}

/***********************ReverseCharBitByLUT**********************/

unsigned char ReverseCharBitByLUT(unsigned char _num)
{
static unsigned char reverseCharTable [TABLE_SIZE];
static int flag = 0;

	if(flag == 0)
	{
		BuildTableOfReverseChar(reverseCharTable);
		flag = 1;
	}

return reverseCharTable [_num];
}

/***********************ReverseIntBitByLUT**********************/

unsigned int ReverseIntBitByLUT(unsigned int _num)
{
static unsigned char reverseTable [TABLE_SIZE];
unsigned int reverse = 0;
unsigned int temp = 0;
static int flag = 0;
int i;
	
	if(flag == 0)
	{
		BuildTableOfReverseChar(reverseTable);
		flag = 1;
	}

	for(i = 0; i < sizeof(int) - 1; i++)
	{
		temp = 	reverseTable[_num & EIGHT_BITS_ON];
		reverse = reverse | temp;
		reverse <<= BITS_IN_BYTE;
		_num >>= BITS_IN_BYTE;
	}
	temp = 	reverseTable[_num & EIGHT_BITS_ON];
	reverse = reverse | temp;
	
return reverse;
}

/***********************SwapIntAdjacentBits**********************/

unsigned int SwapIntAdjacentBits(unsigned int _num)
{
unsigned int result;
int index;

	result = _num;

	for(index = 0; index < INT_SIZE; index += 2)
	{
		if(IsBeatOn(result, index) != IsBeatOn(result, index + 1))
		{
			result^=(1<<index);
			result^=(1<<(index + 1));		
		}	
	}
	
return result;	
}

/***********************SwapCharAdjacentBits**********************/

unsigned char SwapCharAdjacentBits(unsigned char _num)
{
unsigned int result;
int index;

	result = _num;

	for(index = 0; index < CHAR_SIZE; index += 2)
	{
		if(IsBeatOn(result, index) != IsBeatOn(result, index + 1))
		{
			result^=(1<<index);
			result^=(1<<(index + 1));		
		}	
	}
	
return result;	
}

/***********************BuildSwapCharBitsTable**********************/

void BuildSwapCharBitsTable(unsigned char* _swapAdjacentBitsTable)
{
int i;
	for(i = 0; i < TABLE_SIZE; i++)
	{
		_swapAdjacentBitsTable[i] = SwapCharAdjacentBits(i);
	}
}

/***********************SwapCharAdjacentBitsByLUT**********************/

unsigned char SwapCharAdjacentBitsByLUT(unsigned char _num)
{
static unsigned char swapAdjacentBitsTable [TABLE_SIZE];
static int flag = 0;

	if(flag == 0)
	{
		BuildSwapCharBitsTable(swapAdjacentBitsTable);
		flag = 1;
	}

return swapAdjacentBitsTable [_num];
}

/***********************SwapIntAdjacentBitsByLUT**********************/

unsigned int SwapIntAdjacentBitsByLUT(unsigned int _num)
{
static unsigned char swapAdjacentBitsTable [TABLE_SIZE];
unsigned int swapBits = 0;
unsigned int temp = 0;
static int flag = 0;
int i;
	
	if(flag == 0)
	{
		BuildSwapCharBitsTable(swapAdjacentBitsTable); 
		flag = 1;
	}
	
	swapBits = swapAdjacentBitsTable[_num & EIGHT_BITS_ON];

	for(i = 0; i < sizeof(int) - 1; i++)
	{
		_num >>= BITS_IN_BYTE;
		temp = 	swapAdjacentBitsTable[_num & EIGHT_BITS_ON];
		temp <<= BITS_IN_BYTE * (i+1);
		swapBits = swapBits | temp;
	}

return swapBits;
}

/***********************InWhichIndexBit3IsOnForInt**********************/

int InWhichIndexBit3IsOnForInt(unsigned int _num)
{
unsigned int result;
int count = 0;
int index;

	result = _num;

	for(index = 0; index < INT_SIZE; index++)
	{
		if(IsBeatOn(result, index) == 1)
		{
			count++;
			if(count == 3)
			{return index;}		
		}	
	}
	
return -1;	
}

/***********************HowManyBitsOnInChar**********************/

int HowManyBitsOnInChar(unsigned char _num)
{
int count = 0;
int i;

	for (i = 0; i < BITS_IN_BYTE ; i++)
	{
		if(IsBeatOn(_num, i) == 1)
		{
			count++;
		}
	}

return count;
}

/***********************BuildTableForHowManyBitsOnInChar**********************/

void BuildTableForHowManyBitsOnInChar(unsigned char* _howManyBitsOnTable)
{
int i;
	for(i = 0; i < TABLE_SIZE; i++)
	{
		_howManyBitsOnTable[i] = HowManyBitsOnInChar(i);
	}
}

/***********************HowManyBitsOnInCharByLUT**********************/

int HowManyBitsOnInCharByLUT(unsigned char _num)
{
static unsigned char howManyBitsOnTable [TABLE_SIZE];
static int flag = 0;

	if(flag == 0)
	{
		BuildTableForHowManyBitsOnInChar(howManyBitsOnTable);
		flag = 1;
	}

return howManyBitsOnTable [_num];
}

/***********************InWhichIndexBit1IsOnForChar**********************/

int InWhichIndexBit1IsOnForChar(unsigned char _num)
{
unsigned int result;
int count = 0;
int index;

	result = _num;

	for(index = 0; index < CHAR_SIZE; index++)
	{
		if(IsBeatOn(result, index) == 1)
		{
			count++;
			if(count == 1)
			{return index;}		
		}	
	}
	
return -1;	
}

/***********************BuildIndexOfBit1onTable**********************/

void BuildIndexOfBit1onTable(unsigned char* _whichIndexBit1IsOnTable)
{
int i;
	for(i = 0; i < TABLE_SIZE; i++)
	{
		_whichIndexBit1IsOnTable[i] = InWhichIndexBit1IsOnForChar(i);
	}
}

/***********************InWhichIndexBit2IsOnForChar**********************/

int InWhichIndexBit2IsOnForChar(unsigned char _num)
{
unsigned int result;
int count = 0;
int index;

	result = _num;

	for(index = 0; index < CHAR_SIZE; index++)
	{
		if(IsBeatOn(result, index) == 1)
		{
			count++;
			if(count == 2)
			{return index;}		
		}	
	}
	
return -1;	
}

/***********************BuildIndexOfBit2onTable**********************/

void BuildIndexOfBit2onTable(unsigned char* _whichIndexBit2IsOnTable)
{
int i;
	for(i = 0; i < TABLE_SIZE; i++)
	{
		_whichIndexBit2IsOnTable[i] = InWhichIndexBit2IsOnForChar(i);
	}
}

/***********************InWhichIndexBit3IsOnForChar**********************/

int InWhichIndexBit3IsOnForChar(unsigned char _num)
{
unsigned int result;
int count = 0;
int index;

	result = _num;

	for(index = 0; index < CHAR_SIZE; index++)
	{
		if(IsBeatOn(result, index) == 1)
		{
			count++;
			if(count == 3)
			{return index;}		
		}	
	}
	
return -1;	
}

/***********************BuildIndexOfBit3onTable**********************/

void BuildIndexOfBit3onTable(unsigned char* _whichIndexBit3IsOnTable)
{
int i;
	for(i = 0; i < TABLE_SIZE; i++)
	{
		_whichIndexBit3IsOnTable[i] = InWhichIndexBit3IsOnForChar(i);
	}
}

/***********************InWhichIndexBit3IsOnForIntByLUT**********************/

int InWhichIndexBit3IsOnForIntByLUT(unsigned int _num)
{
static unsigned char whichIndexBit1IsOnTable [TABLE_SIZE];
static unsigned char whichIndexBit2IsOnTable [TABLE_SIZE];
static unsigned char whichIndexBit3IsOnTable [TABLE_SIZE];
static unsigned char HowManyBitsOnInChar [TABLE_SIZE];
unsigned int temp = 0;
static int flag = 0;
int numOfBitOn = 0;
int count = 0;
int i;

	
	if(flag == 0)
	{
		BuildIndexOfBit1onTable(whichIndexBit1IsOnTable); 
		BuildIndexOfBit2onTable(whichIndexBit2IsOnTable); 
		BuildIndexOfBit3onTable(whichIndexBit3IsOnTable);
		BuildTableForHowManyBitsOnInChar(HowManyBitsOnInChar); 
		flag = 1;
	}
	
	for(i = 0; i < sizeof(int); i++)
	{
		temp = _num & EIGHT_BITS_ON;
		numOfBitOn = HowManyBitsOnInChar[temp];
		count += numOfBitOn;
		
		if(count >= 3  && count - numOfBitOn == 0)
		{
			return i*BITS_IN_BYTE + whichIndexBit3IsOnTable[temp];
		}
		
		if(count >= 3  && count - numOfBitOn == 1)
		{
			return i*BITS_IN_BYTE + whichIndexBit2IsOnTable[temp];
		}
		
		if(count >= 3  && count - numOfBitOn == 2)
		{
			return i*BITS_IN_BYTE + whichIndexBit1IsOnTable[temp];
		}
				
		_num >>= BITS_IN_BYTE;	
	}
	
return -1;		
}


int main()
{
ReverseIntBit(18275);
ReverseCharBit(18);
ReverseCharBitByLUT(5);
ReverseIntBitByLUT(96849);
SwapIntAdjacentBits(9849815);
SwapCharAdjacentBits(132);
SwapCharAdjacentBitsByLUT(183);
SwapIntAdjacentBitsByLUT(684523);
printf("\n%d\n", InWhichIndexBit3IsOnForInt(16886));
printf("\n%d\n", InWhichIndexBit3IsOnForChar(184));
printf("\n%d\n", HowManyBitsOnInChar(187));
printf("\n%d\n", HowManyBitsOnInCharByLUT(187));
printf("\n%d\n", InWhichIndexBit3IsOnForIntByLUT(16886));

}
