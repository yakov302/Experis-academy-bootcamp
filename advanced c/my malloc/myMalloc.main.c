#include <stdio.h>
#include <stdlib.h>
#include "myMalloc.h"

int main()
{
void* mallocPtr;
long* MetaData;
void* MyMalloc1;
void* MyMalloc2;
void* MyMalloc3;

	if((mallocPtr = (void*) malloc(1000)) == NULL)
	{
		printf("malloc fail!");
	}
		
	MyMallocInit(mallocPtr, 1000);
	MetaData = mallocPtr;
	
	printf("\n-------MyMallocInit: 1000---------\n");
	printf("MetaData1: %ld \nMetaData2: %ld \n", *MetaData, *(MetaData + 1));
	printf("MetaData3: %ld \n",  *(MetaData + 15));
	printf("MetaData4: %ld \n",  *(MetaData + 19));
	printf("MetaData5: %ld \n",  *(MetaData + 45));
			
	MyMalloc1 = MyMalloc(mallocPtr, 100);
	MyMalloc2 = MyMalloc(mallocPtr, 24);
	MyMalloc3 = MyMalloc(mallocPtr, 200);	
	if(MyMalloc(mallocPtr, 2000) == NULL)
	{
		printf("\n-------MyMalloc: 2000---------\n");
		printf("NULL\n");
	}
	
	printf("\n-------MyMalloc: 100, 24, 200---------\n");
	printf("MetaData1: %ld \nMetaData2: %ld \n", *MetaData, *(MetaData + 1));
	printf("MetaData3: %ld \n",  *(MetaData + 15));
	printf("MetaData4: %ld \n",  *(MetaData + 19));
	printf("MetaData5: %ld \n",  *(MetaData + 45));
	
	printf("\n-------MyFree: 24---------\n");
	MyFree(MyMalloc2);
	printf("MetaData1: %ld \nMetaData2: %ld \n", *MetaData, *(MetaData + 1));
	printf("MetaData3: %ld \n",  *(MetaData + 15));
	printf("MetaData4: %ld \n",  *(MetaData + 19));
	printf("MetaData5: %ld \n",  *(MetaData + 45));
	
	printf("\n-------MyFree: 200---------\n");
	MyFree(MyMalloc3);
	printf("MetaData1: %ld \nMetaData2: %ld \n", *MetaData, *(MetaData + 1));
	printf("MetaData3: %ld \n",  *(MetaData + 15));
	printf("MetaData4: %ld \n",  *(MetaData + 19));
	printf("MetaData5: %ld \n",  *(MetaData + 45));
	
	printf("\n-------DoubleFree: 200---------\n");
	MyFree(MyMalloc3);


}

