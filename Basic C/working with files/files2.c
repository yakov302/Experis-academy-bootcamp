#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myWc(char _fileName[])
{

FILE* ptr;
int characters = 0;
int words = 0;
int lines = 0;
char trash[300];

	if((ptr = fopen(_fileName, "r")) == NULL)
	{
		printf("file dont exsist");
		return;
	}
	
	fseek(ptr,0, SEEK_END);
	characters = ftell(ptr);
	
	fseek(ptr,0, SEEK_SET);
	fscanf(ptr, "%s", trash);
	while(!feof(ptr))
	{
		fscanf(ptr, "%s", trash);
		words++;
	}
	
	fseek(ptr,0, SEEK_SET);
	fgets(trash,200, ptr);
	while(!feof(ptr))
	{
		fgets(trash,200, ptr);
		lines++;
	}	
	
	fclose(ptr);
	printf(" %d ", lines);
	printf("%d ", words);
	printf("%d ", characters);
	printf("%s\n", _fileName);
}


void myTail(char _fileName[], int rowNum)
{
FILE* ptr;
char trash[300];
int characters;
int i;
int linesCount  = 0;

	if((ptr = fopen(_fileName, "r")) == NULL)
	{
		printf("file dont exsist");
		return;
	}
		
	fseek(ptr,0, SEEK_END);
	characters = ftell(ptr);
	
	for(i = characters; i > 0; i--)
	{
		if(fgetc(ptr) == '\n')
		{
			linesCount++;
		}
		if(linesCount == rowNum)
		{
			break;
		}
		fseek(ptr,-2, SEEK_CUR);	
	}	
	
	fgets(trash,200, ptr);
	while(!feof(ptr))
	{
		printf("%s", trash);
		fgets(trash,200, ptr);	
	}
		
	fclose(ptr);
}

void wordAppearance(char _fileName[], char word[])
{
char trash[300];
int wordsCount = 0;

FILE *ptr;

	if((ptr = fopen(_fileName, "r")) == NULL)
	{
		printf("file dont exsist");
		return;
	}
	
	fscanf(ptr, "%s", trash);
	
	while(!feof(ptr))
	{
		if(strcmp(word, trash) == 0)
		{
			wordsCount++;
		}
		fscanf(ptr, "%s", trash);	
	}
	
	fclose(ptr);
	
	printf("In file -%s- the word -%s- appeared %d times\n",_fileName,word, wordsCount);
}

void linesCompar(char _fileName1[], char _fileName2[])
{
FILE *ptr1;
FILE *ptr2;
char trash1[600];
char trash2[600];
int i = 1;

	if((ptr1 = fopen(_fileName1, "r")) == NULL)
	{
		printf("file dont exsist");
		return;
	}
	if((ptr2 = fopen(_fileName2, "r")) == NULL)
	{
		printf("file dont exsist");
		return;
	}
	
	fgets(trash1,200, ptr1);
	fgets(trash2,200, ptr2);
	while(!feof(ptr1) && !feof(ptr2))
	{
		if(strcmp(trash1, trash2) != 0)
		{	printf("Difference number %d:\n", i);
			printf("file %s: %s",_fileName1, trash1);
			printf("file %s:%s\n",_fileName2, trash2);
			i++;
		}	
		fgets(trash1,200, ptr1);
		fgets(trash2,200, ptr2);
		
	}	
		
	fclose(ptr1);
	fclose(ptr2);
}


int main()
{
printf("myWc function:\n");
myWc("blabla3");
printf("\nmyTail function:\n");
myTail("blabla",5);
printf("\nwordAppearance function:\n");
wordAppearance("blabla","meefdfting");
printf("\nlinesCompar function:\n");
linesCompar("blabla", "blabla2");

}

