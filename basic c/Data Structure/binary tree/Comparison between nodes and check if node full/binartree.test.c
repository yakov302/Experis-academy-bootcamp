#include <stdio.h>
#include <stdlib.h>
#include "binartree.h"
#include "enum.h"


int main()
{
Tree* ptr;
Tree* ptr2;
int x;
ptr = TreeCreate();
ptr2 = TreeCreate();
TreeInsert(ptr, 5);
TreeInsert(ptr, 3);
TreeInsert(ptr, 1);
TreeInsert(ptr,4);
TreeInsert(ptr,8);
TreeInsert(ptr,7);
TreeInsert(ptr,16);
TreeInsert(ptr,10);
TreeInsert(ptr,20);
TreeInsert(ptr,6);

TreeInsert(ptr2, 5);
TreeInsert(ptr2, 3);
TreeInsert(ptr2, 1);
TreeInsert(ptr2,4);
TreeInsert(ptr2,8);
TreeInsert(ptr2,7);
TreeInsert(ptr2,16);
TreeInsert(ptr2,10);
TreeInsert(ptr2,20);
TreeInsert(ptr2,6);

/*x = IsTreeFull(ptr);
printf("%d\n", x);*/
x = IsSimilar(ptr,ptr2);
printf("%d", x);

TreeDesttroy(ptr);

}
