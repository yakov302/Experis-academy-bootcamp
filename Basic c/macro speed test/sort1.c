#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ARR_SIZE 20000
#define SWAP(x, y)\
{\
int hold;\
hold = x;\
x = y;\
y = hold;\
}

int arr[ARR_SIZE];

void Swap(int *arr1, int *arr2)
{
int hold;
       hold = *arr1;
       *arr1 = *arr2;
       *arr2 = hold;
}

int main()
{
int i;
int j;
clock_t StartBubble;
clock_t EndBubble;
clock_t TotalBubble;
clock_t StartMacro;
clock_t EndMacro; 
clock_t TotalMacro;
float PercentageOfImprovement;
 

		for (i = 0; i < ARR_SIZE ; i++)
        {
       		arr[i + 1]	= rand()%ARR_SIZE;
        }
        
      StartBubble = clock();	
        
       	for (i = 0; i < ARR_SIZE ; i++)
        {
        	for(j = 0; j < ARR_SIZE - i; j++)
        	{
       			if(arr[j] > arr[j + 1])
       			{
       				Swap(&arr[j], &arr[j + 1]);
       			}
       		}
        }
        
     EndBubble = clock();
      	
        
        for (i = 0; i < ARR_SIZE ; i++)
        {
       		arr[i + 1]	= rand()%ARR_SIZE;
        }
        
     
        
       StartMacro = clock();
        
        for (i = 0; i < ARR_SIZE ; i++)
        {
        	for(j = 0; j < ARR_SIZE - i; j++)
        	{
       			if(arr[j] > arr[j + 1])
       			{
       				SWAP(arr[j], arr[j + 1]);
       			}
       		}
        }
        
        EndMacro = clock();  
        
        TotalMacro = (EndMacro - StartMacro)/100000;
        TotalBubble = (EndBubble - StartBubble)/100000;
        PercentageOfImprovement = (1 - ((float) TotalMacro / TotalBubble));
        
        printf("StartBubble: %ld\n", StartBubble);
        printf("EndBubble: %ld\n", EndBubble);
        printf("TotalBubble: %ld\n", TotalBubble);
         printf("\nStartMacro: %ld\n", StartMacro);
        printf("EndMacro: %ld\n", EndMacro);
        printf("TotalMacro: %ld\n", TotalMacro);
        printf("\nPercentageOfImprovement: %0.2f\n",PercentageOfImprovement);
}

