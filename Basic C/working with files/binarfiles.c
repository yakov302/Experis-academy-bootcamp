#include <stdio.h>
#include <stdlib.h>

typedef struct Person
{
	int m_id;                   
	char m_name[50];
	int m_age;  
}Person;

Person test [] = 
{
{111, "yakov", 30},
{222, "david", 28},
{333, "dana", 52},
{444, "mosh", 70},
{555, "rami", 18}
};

int main()
{

Person test2[5];
FILE *ptr;
Person test3;


if((ptr = fopen("PersonTest", "w")) == NULL)
{
	printf("cant open");
}

fwrite(test, sizeof(Person), 5, ptr);


fclose(ptr);



if((ptr = fopen("PersonTest", "r")) == NULL)
{
	printf("cant open");
}

fread(test2, sizeof(Person), 5, ptr);

printf("%d %s %d\n",  test2[3].m_id, test2[3].m_name , test2[3].m_age);

fclose(ptr);



if((ptr = fopen("PersonTest", "r")) == NULL)
{
	printf("cant open");
}

fseek(ptr, sizeof(Person)*4, SEEK_SET); 

fread(&test3, sizeof(Person), 1, ptr);

printf("%d %s %d\n",  test3.m_id, test3.m_name , test3.m_age);

fclose(ptr);


}






