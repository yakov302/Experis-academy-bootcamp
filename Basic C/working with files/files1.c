
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
typedef struct Person
{
	int m_id;                   /*Primary Key*/
	char m_name[128];
	int m_age;
	struct Person *m_next;    /*Pointer to next primary Key*/
}Person;

FILE *ptr;
Person Person1;
Person Person2;

Person1.m_id = 1111;
Person1.m_age = 1;
Person1.m_next = NULL;
strcpy(Person1.m_name,"yosi"); 




if((ptr = fopen("test.c","w")) == NULL)
{
	printf("cant open");
}

fprintf(ptr,"%d\n", 1111);
fprintf(ptr,"%d\n", 1);
fprintf(ptr,"%s\n", "yosi");



fclose(ptr);

if((ptr = fopen("test.c","r")) == NULL)
{
	printf("cant open");
}

fscanf(ptr, "%d", &Person2.m_id);
fscanf(ptr, "%d", &Person2.m_age);

fscanf(ptr, "%s", Person2.m_name);


printf("%d\n", Person2.m_id); 
printf("%d\n", Person2.m_age); 
 
printf("%s\n", Person2.m_name); 



fclose(ptr);



}

