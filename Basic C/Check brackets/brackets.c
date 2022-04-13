#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "enum.h"
#include "stack.h"


int CheckBrackets(char _brackets[])
{
int size;
int i;
Stack *ptr;
int item;
int type; 

	size = strlen(_brackets);
	ptr = StackCreate(size, 0);
	
	for(i = 0; i < size; i++)
	{
		if(_brackets[i] == ')')
		{
			type = 1;
		}
		if(_brackets[i] == '}')
		{
			type = 2;
		}
		if(_brackets[i] == ']')
		{
			type = 3;
		}
		
				if (_brackets[i] == '(' || _brackets[i] == '{' || _brackets[i] == '[')
				{
					StackPush (ptr, _brackets[i]);
				}
			
				if(_brackets[i] == ')' || _brackets[i] == '}' || _brackets[i] == ']')
				{
					if(StackIsEmpty (ptr) == STACK_EMPTY)
					{
						return UNBALANC;
					}
					else
					{
						StackPop(ptr, &item);
						
						if(type == 1)
						{
							if(item != '(')
							{
								return UNBALANC;
							}
						}
							
						if(type == 2)
						{
							if(item != '{')
							{
								return UNBALANC;
							}
						} 
						
						if(type == 3)
						{
							if(item != '[')
							{
								return UNBALANC;
							}
					    }   
				   }
			   }
	}
	
	if(StackIsEmpty (ptr) == STACK_NOT_EMPTY)
	{
		return UNBALANC;
	} 
	
		return BALANC;				
}


int main()
{

int x;
char y [] = "hffgh{hjg{[gdh[(gdfgh(gjfdg))]fdgh]}ggdfhg}hjgh";
x = CheckBrackets(y);
if (x == 9)
{
	printf("UNBALANC!\n");
}
if(x == 10)
{
	printf("BALANC!\n");	
}
}


