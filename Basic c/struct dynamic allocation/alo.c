#include <stdio.h> 
#include <stdlib.h> 

int main()
{
int *p;
int i;

	if ((p = (int*)malloc(100*sizeof(i))) == NULL)
	{
		printf("no memory");
	
	}

	for (i = 0; i < 100; i++)
	{
		*(p+i)=i;
	}
	
	for (i = 0; i < 100; i++)
	{
		printf("%d ",*(p+i));
	}
	
	 free(p);
	
	for (i = 0; i < 100; i++)
	{
		printf("%d ",*(p+i));
	}
}	 
