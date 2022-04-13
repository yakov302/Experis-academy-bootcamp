#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ARR_SIZE 50000
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
register int ii;
register int jj;
clock_t StartBubble;
clock_t EndBubble;
clock_t TotalBubble;
clock_t r_StartBubble;
clock_t r_EndBubble;
clock_t r_TotalBubble;
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
        
      r_StartBubble = clock();	
        
       	for (ii = 0; ii < ARR_SIZE ; ii++)
        {
        	for(jj = 0; jj < ARR_SIZE - ii; jj++)
        	{
       			if(arr[jj] > arr[jj + 1])
       			{
       				Swap(&arr[jj], &arr[jj + 1]);
       			}
       		}
        }
        
     r_EndBubble = clock();
      	
        
        
        
        r_TotalBubble = (r_EndBubble - r_StartBubble)/100000;
        TotalBubble = (EndBubble - StartBubble)/100000;
        PercentageOfImprovement = (1 - ((float) r_TotalBubble / TotalBubble));
        
        printf("StartBubble: %ld\n", StartBubble);
        printf("EndBubble: %ld\n", EndBubble);
        printf("TotalBubble: %ld\n", TotalBubble);
         printf("\nr_StartBubble: %ld\n", r_StartBubble);
        printf("r_EndBubble: %ld\n", r_EndBubble);
        printf("r_TotalBubble: %ld\n", r_TotalBubble);
        printf("\nPercentageOfImprovement: %0.2f\n",PercentageOfImprovement);
}

