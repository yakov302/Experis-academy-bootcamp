#include <stdio.h>
#include <stdlib.h>
#include "binartree.h"
#include "enum.h"

/**************TreeInsert test****************/

TreeInsertNullChack(void)
{
Tree* ptr;
ptr = TreeCreate();
 	if(TreeInsert(NULL, 50) == ERR_NOT_INITIALIZED)
 	{
 		printf("TreeInsert - NULL chack       - PASS!\n");
 	}
 	else
 	{
 		 printf("TreeInsert - NULL chack       - PASS!\n");
 	}
TreeDesttroy(ptr);
}

TreeInsertIsWork(void)
{
Tree* ptr;
ptr = TreeCreate();
TreeInsert(ptr, 16);
TreeInsert(ptr, 18);

 	if(TreeIsDataFound(ptr, 16) == ERR_ELEMENT_EXIST && TreeIsDataFound(ptr, 18) == ERR_ELEMENT_EXIST)
 	{
 		printf("TreeInsert - Is insert work   - PASS!\n");
 	}
 	else
 	{
 		 printf("TreeInsert - Is insert work    - PASS!\n");
 	}
 TreeDesttroy(ptr);
}


TreeDuplicatWork(void)
{
Tree* ptr;
ptr = TreeCreate();
TreeInsert(ptr, 35);
TreeInsert(ptr, 25);
TreeInsert(ptr, 16);

 	if(TreeInsert(ptr, 16) == ERR_DUPLICATE)
 	{
 		printf("TreeInsert - Is Duplicat work - PASS!\n");
 	}
 	else
 	{
 		 printf("TreeInsert - Is Duplicat work - PASS!\n");
 	}
 TreeDesttroy(ptr);
}

/**************TreeIsDataFound test****************/

TreeIsFoundNullChack(void)
{
Tree* ptr;
ptr = TreeCreate();
 	if(TreeIsDataFound(NULL, 50) == ERR_NO_ELEMENTS)
 	{
 		printf("TreeIsFound - NULL chack     - PASS!\n");
 	}
 	else
 	{
 		 printf("TreeIsFound - NULL chack     - PASS!\n");
 	}
TreeDesttroy(ptr);
}

TreeIsFoundWork(void)
{
Tree* ptr;
ptr = TreeCreate();
TreeInsert(ptr, 30);
TreeInsert(ptr, 18);

 	if(TreeIsDataFound(ptr, 18) == ERR_ELEMENT_EXIST && TreeIsDataFound(ptr, 80) == ERR_ELEMENT_DONT_EXIST)
 	{
 		printf("TreeIsFound - Is  chack work - PASS!\n");
 	}
 	else
 	{
 		 printf("TreeIsFound -Is  chack work - PASS!\n");
 	}
TreeDesttroy(ptr);
}


/**************TreeDesttroy test****************/

TreeIsDoubleWork(void)
{
Tree* ptr;
ptr = TreeCreate();
TreeInsert(ptr, 30);
TreeInsert(ptr, 18);
TreeDesttroy(ptr);
TreeDesttroy(ptr);

 		printf("TreeDesttroy - Is  Double work - PASS!\n");

}


int main()
{
int i;
Tree* ptr;

printf("\n-------------TreeInsert test---------------\n");
TreeInsertNullChack();
TreeInsertIsWork();
TreeDuplicatWork();

printf("\n-----------TreeIsDataFound test------------\n");
TreeIsFoundNullChack();
TreeIsFoundWork();

printf("\n------------TreeDesttroy test--------------\n");
TreeIsDoubleWork();

printf("\n--------------TreePrint test---------------\n");

ptr = TreeCreate();
/*TreeInsert(ptr, 30);
TreeInsert(ptr, 18);
TreeInsert(ptr, 16);
TreeInsert(ptr,20);
TreeInsert(ptr,19);
TreeInsert(ptr,25);
TreeInsert(ptr,40);
TreeInsert(ptr,50);
TreeInsert(ptr,45);*/
for(i = 0; i< 10000; i++)
{
TreeInsert(ptr,rand()%20000);
}

printf("\nIn order print:\n");
TreePrint(ptr, IN_ORDER);

/*printf("\nPre order print:\n");
TreePrint(ptr, PRE_ORDER);



printf("\nPodt order print:\n");
TreePrint(ptr, POST_ORDER);*/

TreeDesttroy(ptr);

}
