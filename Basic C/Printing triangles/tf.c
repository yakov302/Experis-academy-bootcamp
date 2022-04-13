
#include <stdio.h>
#include "tf.h"


int check_err (char _sign, int _line)
{                                     
	if(_sign < MIN_SIGN || _sign > MAX_SIGN)
	{
		return ERR_SIGN;
	}
	if(_line < MIN_LINE || _line > MAX_LINE)
	{
		return ERR_LINE;
	}
	
return OK;
}
 
void print_sign (char _sign, int _size, int _index)
{                      
		while (_index <= _size)
		{
			putchar(_sign);
			_index++ ;
		}
}
	
void print_sign_spac (char _sign , int _index)
{                         
		while (_index >= 0)
		{
			putchar(_sign);
			putchar(' ');
			_index-- ;
	 	}
}
	
		
int triag1 (char _sign, int _line) 
{                              
int index;                                                      
int result;

	if((result = check_err(_sign, _line)) != OK)
	{
		 return result;
 	}

	for(index=0; index < _line ;index++)                     
	{
		print_sign(_sign, index,0);
		printf("\n");
	}
	
return OK;
}


int triag2 (char _sign, int _line)                              
{
int index;                                                     
int result;

	if((result = check_err(_sign, _line)) != OK)
	{
		 return result;
 	}
 	
	for(index=0; index < _line ;index++)                   
	{
		print_sign(_sign, _line-index-1,0);
		printf("\n");
	}
	
return OK;
}


int triag3 (char _sign, int _line)                              
{
int result;

	if((result = check_err(_sign, _line)) != OK)
	{
		 return result;
 	}

	triag1(_sign, _line);                                    
	triag2(_sign, _line-1);
	
return OK;
}



int triag4 (char _sign, int _line)                                 
{
int index;                                                         
int result;

	if((result = check_err(_sign, _line)) != OK)
	{
		 return result;
 	}
 
	for(index=0; index < _line ;index++)                        
	{	  
	    print_sign (' ',  _line - index - 1 ,0);
	    print_sign_spac (_sign, index);
        printf("\n");

	}
	
return OK;
}



int triag5 (char _sign, int _line)                              
{
int index, index2, index3;                                     
int result;
	if((result = check_err(_sign, _line)) != OK)
	{
		 return result;
 	}

	for(index=0; index < _line ;index++)                  
	{
		  print_sign (' ', index , 0);
       	  print_sign_spac (_sign, _line - index - 1);      	
      	  printf("\n");
	}
	
return OK;
}



int triag6 (char _sign, int _line)                            
{
int index, index2, index3; 
int result;

	if((result = check_err(_sign, _line)) != OK)
	{
		 return result;
 	}
 


	for(index=0; index < _line - 1 ;index++) 
	{
		print_sign (' ',  _line - index - 1 ,0);
	   	print_sign_spac (_sign, index);
       	printf("\n");
	}

	triag5 (_sign, _line);

return OK;
}





















