#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "enum.h"

int main()
{
 
Vector *ptr;
Vector *ptr2;
size_t originalSize;
size_t size;
size_t nItems;
size_t blockSize;
size_t originalSize2;
size_t size2;
size_t nItems2;
size_t blockSize2;
int i;
int item;
size_t x;
int y;

/**********************VectorCreate tests************************/

printf("\n");
printf("-----VectorCreate test-------\n");
printf("\n");


ptr = VectorCreate (6, 2);
if(ptr != NULL)
{
	printf("VectorCreate test 1 : Pass!\n");
	VectorDestroy(ptr);
}
else
{
	printf("VectorCreate test 1 : Fails!\n");
	VectorDestroy (ptr);
}


ptr = VectorCreate (0, 2);
if(ptr != NULL)
{
	printf("VectorCreate test 2 : Pass!\n");
	VectorDestroy (ptr);
}
else
{
	printf("VectorCreate test 2 : Fails!\n");
	VectorDestroy (ptr);
}


ptr = VectorCreate (6, 0);
if(ptr != NULL)
{
	printf("VectorCreate test 3 : Pass!\n");
	VectorDestroy (ptr);
}
else
{
	printf("VectorCreate test 3 : Fails!\n");
	VectorDestroy (ptr);
}


ptr = VectorCreate (0, 0);
if(ptr == NULL)
{
	printf("VectorCreate test 4 : Pass!\n");
	VectorDestroy (ptr);
}
else
{
	printf("VectorCreate test 4 : Fails!\n");
	VectorDestroy (ptr);
}

ptr = VectorCreate (-1, 0);
if(ptr == NULL)
{
	printf("VectorCreate test 5 : Pass!\n");
	VectorDestroy (ptr);
}
else
{
	printf("VectorCreate test 5 : Fails!\n");
	VectorDestroy (ptr);
}

ptr = VectorCreate (10, 10);
originalSize = Getm_originalSize (ptr);
size = Getm_size (ptr);
nItems = Getm_nItems (ptr);
blockSize = Getm_blockSize (ptr);
if(originalSize == 10 && size == 10 && nItems == 0 && blockSize == 10)
{
	printf("VectorCreate test 6 : Pass!\n");
	VectorDestroy (ptr);
}
else
{
	printf("VectorCreate test 6 : Fails!\n");
	VectorDestroy (ptr);
}

printf("\n\n");

/***********************VectorDestroy test*************************/

printf("-----VectorDestroy test-------\n");
printf("\n");

ptr = VectorCreate (10, 10);
VectorDestroy (ptr);
ptr2 = malloc(10);
VectorDestroy (ptr2);
if(ptr == ptr2)
{
	printf("VectorDestroy test 1 : Pass!\n");
}
else
{
	printf("VectorDestroy test 1 : Fails!\n");
}

ptr = VectorCreate (10, 10);
originalSize = Getm_originalSize (ptr);
size = Getm_size (ptr);
nItems = Getm_nItems (ptr);
blockSize = Getm_blockSize (ptr);

VectorDestroy (ptr);
originalSize2 = Getm_originalSize (ptr);
size2 = Getm_size (ptr);
nItems2 = Getm_nItems (ptr);
blockSize2 = Getm_blockSize (ptr);
if(originalSize != originalSize2 || size != size2 || nItems != nItems2 || blockSize != blockSize2 )
{
	printf("VectorDestroy test 2 : Pass!\n");
}
else
{
	printf("VectorDestroy test 2 : Fails!\n");
}

ptr = VectorCreate (10, 10);
VectorDestroy (ptr);
originalSize = Getm_originalSize (ptr);
size = Getm_size (ptr);
nItems = Getm_nItems (ptr);
blockSize = Getm_blockSize (ptr);
VectorDestroy (ptr);
originalSize2 = Getm_originalSize (ptr);
size2 = Getm_size (ptr);
nItems2 = Getm_nItems (ptr);
blockSize2 = Getm_blockSize (ptr);
if(originalSize == originalSize2 && size == size2 && nItems == nItems2 && blockSize == blockSize2 )
{
	printf("VectorDestroy test 3 : Pass!\n");
}
else
{
	printf("VectorDestroy test 3 : Fails!\n");
}

printf("\n\n");

/*************************VectorAdd test***************************/

printf("-----VectorAdd test-------\n");
printf("\n");

if(VectorAdd (NULL, 5) == ERR_NOT_INITIALIZED)
{
	printf("VectorAdd test 1 : Pass!\n");
}
else
{
	printf("VectorAdd test 1 : Fails!\n");
}


ptr = VectorCreate (5, 0);
for(i = 0; i < 3; i++)
{
	VectorAdd (ptr, 5);
}
if(Getm_nItems (ptr) == 3 &&  getn(ptr, 2) == 5)
{
	printf("VectorAdd test 2 : Pass!\n");
}
else
{
	printf("VectorAdd test 2 : Fails!\n");
}
VectorDestroy (ptr);


ptr = VectorCreate (5, 0);
for(i = 0; i < 5; i++)
{
	VectorAdd (ptr, 5);
}
if(VectorAdd (ptr, 5) == ERR_OVERFLOW)
{
	printf("VectorAdd test 3 : Pass!\n");
}
else
{
	printf("VectorAdd test 3 : Fails!\n");
}
VectorDestroy (ptr);


ptr = VectorCreate (5, 1);
for(i = 0; i < 10; i++)
{
	VectorAdd (ptr, 5);
}
if(Getm_nItems(ptr) == 10 &&  getn(ptr, 9) == 5 && Getm_size (ptr) == 10)
{
	printf("VectorAdd test 4 : Pass!\n");
}
else
{
	printf("VectorAdd test 4 : Fails!\n");
}
VectorDestroy (ptr);

printf("\n\n");

/***********************VectorDelete test***********************/

printf("-----VectorDelete test-------\n");
printf("\n");

if(VectorDelete(NULL, &item) == ERR_NOT_INITIALIZED)
{
	printf("VectorDelete test 1 : Pass!\n");
}
else
{
	printf("VectorDelete test 1 : Fails!\n");
}

ptr = VectorCreate (5, 1);
if(VectorDelete(ptr, NULL) == ERR_NOT_INITIALIZED)
{
	printf("VectorDelete test 2 : Pass!\n");
}
else
{
	printf("VectorDelete test 2 : Fails!\n");
}
VectorDestroy (ptr);

ptr = VectorCreate (5, 1);
if(VectorDelete(ptr, &item) == ERR_UNDERFLOW)
{
	printf("VectorDelete test 3 : Pass!\n");
}
else
{
	printf("VectorDelete test 3 : Fails!\n");
}
VectorDestroy (ptr);


ptr = VectorCreate (5, 1);
for(i = 0; i < 5; i++)
{
	VectorAdd (ptr, i);
}
for(i = 0; i < 3; i++)
{
	VectorDelete(ptr, &item);
}
if(item == 2 && Getm_nItems (ptr) == 2 && VectorDelete(ptr, &item) == ERR_OK)
{
	printf("VectorDelete test 4 : Pass!\n");
}
else
{
	printf("VectorDelete test 4 : Fails!\n");
}
VectorDestroy (ptr);


ptr = VectorCreate (10, 2);
for(i = 0; i < 30; i++)
{
	VectorAdd (ptr, i);
}
for(i = 0; i < 28 ;i++)
{
	VectorDelete(ptr, &item);
}
if(Getm_size (ptr) == Getm_originalSize(ptr) && item == 2 && Getm_nItems (ptr) == 2 &&  getn(ptr, 2) == item && VectorDelete(ptr, &item) == ERR_OK)
{
	printf("VectorDelete test 5 : Pass!\n");
}
else
{
	printf("VectorDelete test 5 : Fails!\n");
}

VectorDestroy (ptr);
printf("\n\n");

/*********************VectorItemsNum test*********************/

printf("-----VectorItemsNum test-------\n");
printf("\n");

if(VectorItemsNum (NULL, &x) == ERR_NOT_INITIALIZED)
{
	printf("VectorItemsNum test 1 : Pass!\n");
}
else
{
	printf("VectorItemsNum test 1 : Fails!\n");
}

ptr = VectorCreate (10, 2);
if(VectorItemsNum (ptr, NULL) == ERR_NOT_INITIALIZED)
{
	printf("VectorItemsNum test 2 : Pass!\n");
}
else
{
	printf("VectorItemsNum test 2 : Fails!\n");
}
VectorDestroy (ptr);


ptr = VectorCreate (10, 2);
for(i = 0; i < 5; i++)
{
	VectorAdd (ptr, i);
}
VectorItemsNum (ptr, &x);
if(x == 5)
{
	printf("VectorItemsNum test 3 : Pass!\n");
}
else
{
	printf("VectorItemsNum test 3 : Fails!\n");
}
VectorDestroy (ptr);

ptr = VectorCreate (10, 2);
for(i = 0; i < 20; i++)
{
	VectorAdd (ptr, i);
}
for(i = 0; i < 15; i++)
{
	VectorDelete(ptr, &item);
}
VectorItemsNum (ptr, &x);
if(x == 5)
{
	printf("VectorItemsNum test 4 : Pass!\n");
}
else
{
	printf("VectorItemsNum test 4 : Fails!\n");
}
VectorDestroy (ptr);
printf("\n\n");

/********************VectorGet test************************/

printf("-----VectorGet test-------\n");
printf("\n");

ptr = VectorCreate (10, 2);
if(VectorGet(NULL,  2,&item) == ERR_NOT_INITIALIZED)
{
	printf("VectorGet test 1 : Pass!\n");
}
else
{
	printf("VectorGet test 1 : Fails!\n");
}
VectorDestroy (ptr);

ptr = VectorCreate (10, 2);
if(VectorGet(ptr,  2, NULL) == ERR_NOT_INITIALIZED)
{
	printf("VectorGet test 2 : Pass!\n");
}
else
{
	printf("VectorGet test 2 : Fails!\n");
}
VectorDestroy (ptr);

ptr = VectorCreate (10, 2);
for(i = 0; i < 5; i++)
{
	VectorAdd (ptr, i);
}
if(VectorGet(ptr,  8, &item) == ERR_WRONG_INDEX)
{
	printf("VectorGet test 3 : Pass!\n");
}
else
{
	printf("VectorGet test 3 : Fails!\n");
}
VectorDestroy (ptr);


ptr = VectorCreate (10, 2);
for(i = 0; i < 5; i++)
{
	VectorAdd (ptr, i);
}
VectorGet(ptr,  3, &item);

if(item == 3)
{
	printf("VectorGet test 4 : Pass!\n");
}
else
{
	printf("VectorGet test 4 : Fails!\n");
}
VectorDestroy (ptr);
printf("\n\n");

/*********************VectorSet test***********************/

printf("-----VectorSet test-------\n");
printf("\n");

ptr = VectorCreate (10, 2);
if(VectorSet(NULL, 2, 50) == ERR_NOT_INITIALIZED)
{
	printf("VectorSet test 1 : Pass!\n");
}
else
{
	printf("VectorSet test 1 : Fails!\n");
}
VectorDestroy (ptr);


ptr = VectorCreate (10, 2);
if(VectorSet(ptr, 3, 50) == ERR_WRONG_INDEX)
{
	printf("VectorSet test 2 : Pass!\n");
}
else
{
	printf("VectorSet test 2 : Fails!\n");
}
VectorDestroy (ptr);

ptr = VectorCreate (10, 2);
for(i = 0; i < 10; i++)
{
	VectorAdd (ptr, i);
}
VectorSet(ptr, 5, 50);
if(getn(ptr,  5) == 50)
{
	printf("VectorSet test 3 : Pass!\n");
}
else
{
	printf("VectorSet test 3 : Fails!\n");
}
VectorDestroy (ptr);

}


