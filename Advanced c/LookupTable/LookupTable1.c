#define NUM_OF_BITS 8
#define SIZE 256

int IsOn ( unsigned char _byte , int _n)
{
	if ( _n >  NUM_OF_BITS-1 || _n < 0)
	{
		return -1 ;
	}
	 if ( (_byte & ( 1 << _n) ) > 0)
	{
		return 1 ;
	}
return 0 ;
}

int CountBitOn ( unsigned char _x )
{
int i ;
int  counter = 0 ;

	for ( i = 0 ; i <  NUM_OF_BITS  ; i++)
	{
		if ( IsOn ( _x, i ) )
		{
			counter++;
		}
	}
	
return counter ;
}


void BuildTable ( int * _BC )
{
int index ;

	for ( index = 0 ; index < SIZE ; index++)
	{
		_BC [index] = CountBitOn ( index ) ;
	}
} 

int GetBitOnChar ( unsigned char _x ) 
{
static int BC[SIZE] ;
static int flag ;

	if ( !flag )
	{
		BuildTable ( BC ) ;
		flag =1 ;
	}
	
return BC [_x] ;
}

int GetBitOnInt ( unsigned int _x ) 
{
static int BC[SIZE] ;
static int flag ;
int index , sum = 0 ;

	if ( !flag )
	{
		BuildTable ( BC ) ;
		flag =1 ;
	}
	for ( index = 0 ; index < sizeof ( int ) ; index ++)
	{
		sum +=BC [_x & 0xFF ] ;
		_x >>= 8  ;
	}
	
return sum ;
}






