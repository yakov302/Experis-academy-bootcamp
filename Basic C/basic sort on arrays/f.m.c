#include <stdio.h>
#include<string.h>
#include "f.h"

int main()
{

struct student yakov;

yakov.age = 30;
yakov.id = 154789654;
strcpy(yakov.name,"yakov hananel zaidenberg");

printf("%d\n",yakov.age);
printf("%ld\n",yakov.id);
printf("%s\n",yakov.name);

printf("\n");
 struct student arr [5] = {{"kobi", 30, 548796354}, {"david", 25, 6545654}, {"yosi",47,5465465},{"danit", 27, 4},{"matan", 56, 49685458}};


Sort_by_age(arr, strlen(arr));

printf("\n");

Sort_by_name (arr,strlen(arr));

}

