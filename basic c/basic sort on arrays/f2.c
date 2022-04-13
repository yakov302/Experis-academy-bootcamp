#include <stdio.h> 
#include <string.h>
#define INPUT_ERROR 0
/*

char reverse_string (char str[])
{

char hold;
int index=0;
int size = strlen(str);
int index2 = size -1;
int i;

	if (str == NULL)
	{
		return INPUT_ERROR;
	}
	

    while(index < index2)
    {
        hold = *(str+index);
        *(str+ index) = *(str+index2);
        *(str+index2) = hold;
        index++;
        index2--;
    }

    return str;

}

int pal (char str[])
{

int index=0;
int size = strlen(str);
int index2 = size -1;
int i = 0;

	if (str == NULL)
	{
		return INPUT_ERROR;
	}
	
	
    while(index < index2)
    {
		if(str[index] != str[index2])
		{
			return 0;
		}
        index++;
        index2--;
    }
    
    return 1;
}
*/


char reverse_words (char str[])
{
char hold;
int index=0;
int size = strlen(str);
int index2 = size -1;
int i;
int spac_index1 = 0 ;
int spac_index2 = 1 ;

	if (str == NULL)
	{
		return INPUT_ERROR;
	}
	

    while(index < index2)
    {
        hold = *(str+index);
        *(str+ index) = *(str+index2);
        *(str+index2) = hold;
        index++;
        index2--;
    }

	while(spac_index1 != spac_index2)
	{
   
   		for(i = spac_index1; i < size - 1; i++)
  		 {
   			if(str[i] == ' ')
   			{
   				spac_index2 = i;
   				 break;
   			}
   		 }
   
      	for (i = spac_index1+1 ; i < spac_index2 - 1; i++)
   		{
   	 	 	hold = *(str + spac_index1);
      	 	*(str+ spac_index1) = *(str+spac_index2);
      		*(str+spac_index2) = hold;
      		 index++;
     	     index2--;
  		 }
   		spac_index1 = spac_index2;
	}

	
 return str;
}


int main()
{
/*
int x;
int z;
*/
char y [] = "yakov hananel zaidenberg";
/*
reverse_string (y);
printf("%s",y);
printf("\n");
x = pal(y);
printf("%d",x);
z = reverse_string(y);
printf("\n");
printf("%s",z);
*/
int t;
reverse_words(y);
printf("%s",y);

}	 
