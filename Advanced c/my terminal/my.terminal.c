#include <stdio.h> 
#include <string.h>
#define GREEN "\x1b[32m"
#define BLUE "\x1B[34m"
#define NORMAL "\x1B[0m"
#define BOLD "\x1b[1m"
#define MAX 200

void myTeminal(void)
{
const char delimiters[3] = " \n";
char* words[MAX];
char str[MAX];
int status;
int i;

	printf("\n----------- Yakov terminal 20.16.3 ------------\n");

	while(1)
	{	
		i = 1;
		printf(GREEN BOLD"\nuser@user");
		printf(NORMAL ":");
		printf(BLUE BOLD "~/Home/Programs/YakovTerminal");
		printf(NORMAL "$ ");
		fgets(str,MAX, stdin) ;
		
		words[0] = strtok(str, delimiters);
		while (words[i - 1] != NULL)
		{		
			words[i] = strtok(NULL, delimiters);
			i++;	
		}
		
		if(strcmp(words[0], "exit") == 0) {break;}
				
		if(fork() != 0)
		{			
			wait(NULL);
		}
		else
		{
			execvp(words[0], words);		
            		printf("Invalid command!\n");
            		return; 		
		}			
	}
}


int main()
{
myTeminal();


}



