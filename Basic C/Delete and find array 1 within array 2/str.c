
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "str.h"

int del_s1_from_s2 (char _str1[], char _str2[])
{
int size1;
int size2;
int index1;
int index2;
int index_writer = 0;
int flag =0;
int j;
int i;
 
 
	if(_str1 == NULL || _str2 == NULL)
	{
		return ERR;
	}
	
	size1 = strlen(_str1);
	size2 = strlen(_str2);
	
	for(index1 = 0; index1 < size1 ; index1++)
	{
    		for(index2 = 0; index2 < size2 ; index2++)
			{
    			if (_str1[index1] == _str2[index2])
    			{
    				flag = 1;
    				break;
    			}
    		}
    		if (flag == 0)
    		{
    			_str1[index_writer] = _str1[index1];
    			index_writer++;
    		}
    		else
    		{
    			flag = 0;	
    		}
    				
        }
    
    	for(i = index_writer; i < index1 ; i++)
    	{
    		_str1[i] = '\0';
    	}
    
    	/*return 1;*/
    
    	for(j = 0; j < index_writer + 1; j++)
    	{
    		printf("%c", _str1[j]);
    	}
    	
}


int find_str1_in_str2(char _str1[], char _str2[])
{
int size1;
int size2;
int index;
int comp;
	
	if(_str1 == NULL || _str2 == NULL || _str1 > _str2)
	{
		return ERR;
	}
	
	size1 = strlen(_str1);
	size2 = strlen(_str2);
	
	for(index = 0; index < (size2 - size1 + 1); index++)
	{
    	comp = strncmp(_str1, &_str2[index],size1);
    	if (comp == 0)
    	{
    		return index;
    	} 
    }
  
return -2;
}















