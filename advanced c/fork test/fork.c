#include <stdio.h>

int g_var = 0;

int main()
{
int l_var = 0;
int n;
int i;
	sleep(5);

	n = fork();

	if(n > 0)
	{
	/********parent*******/
		for(i = 0; i < 30; i++)
		{
			g_var++;
			l_var++;
			printf("parent: %d, %d\n",g_var, l_var);		
		}
		sleep(40);
		wait();		
	}
	else
	{
	/*******child*********/
		for(i = 0; i < 50; i++)
		{
			g_var++;
			l_var++;
			printf("child: %d, %d\n",g_var, l_var);		
		}
	}
}


