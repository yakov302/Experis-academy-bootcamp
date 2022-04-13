#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.map.h"
#include "gen.list.h"
#define WORD_SIZE 80
#define HASH_MAP_SIZE 2000
#define UPPER_TO_LOWER 'a' - 'A'

/*************************FunctionSignatures****************************/

char* fixWord(char* word);
void ItemDestroy(void* _item);
size_t HashForWord(void* _word);
static void printKey(void* _word);
static void printValue(void* _value);
int EqualityWords(void* _firstWord, void* _secondWord);

/**********************CountWordsAppearsInFile*************************/

void CountWordsAppearsInFile(char _fileName[])
{
char fixword[WORD_SIZE], word[WORD_SIZE];
void* nomOfAppearns;
HashMap* hashMap;
char* wordKey;
int* valueKey;
void* pValue;
void* pKey;
FILE* file;
int len;
	
	if(_fileName == NULL)
	{
		printf("File name = NULL");
		return;
	}

	if ((file = fopen(_fileName, "r")) == NULL)
	{
		printf("File not opened!");
		return;
	}
	
	if((hashMap = HashMapCreate(HASH_MAP_SIZE, HashForWord, EqualityWords)) == NULL)
	{
		printf("HashMapCreate fail");
		return;		
	}
	
	fscanf(file, "%s", word);
	
	while(!feof(file))
	{	
		strcpy(fixword, fixWord(word));
		
		if(HashMapFind(hashMap, fixword, &nomOfAppearns) == MAP_KEY_NOT_FOUND_ERROR)
		{
			len = strlen(fixword);
			if((wordKey = (char*) malloc(len + 1)) == NULL){return;}
			if((valueKey = (int*) malloc(sizeof(int))) == NULL){return;}
			strcpy(wordKey, fixword);
			*valueKey = 1;
			HashMapInsert(hashMap, wordKey, valueKey);
		}
		else
		{
			(*(int*)nomOfAppearns)++;
		}
		
		fscanf(file, "%s", word);
	 }

	printf("-------------------------------------\n");
	HashMapPrint(hashMap, printKey, printValue );
	
	fclose(file);
	HashMapDestroy(&hashMap, ItemDestroy, ItemDestroy);		
}

/**********************fixWord*************************/

char* fixWord(char* word)
{
int j;

	if(word[0] <= 'Z' && word[0] >= 'A')
	{
		word[0] = word[0] + UPPER_TO_LOWER;
	}

	 for(j = 0; j < strlen(word); j++)
	 {
	        if( word[j] == '.' || word[j] == ',' || word[j] == ':' || word[j] == '\n' || word[j] == ';' || word[j] == ' ')
	        {
	        	word[j] = '\0';
	        }
	 }
	 
return word;
}

/**********************ItemDestroy*************************/

void ItemDestroy(void* _item)
{
	free(_item);
}

/**********************HashForWord*************************/

size_t HashForWord(void* _word)
{
int len;
int count = 0;
int i;

	if(_word == NULL){return 0;}
	
	len = strlen(_word);
	
	for(i = 0; i < len; i++)
	{
		count = count + (*((char*)_word + i) - '0');
	}
		
return count;
}

/**********************EqualityWords*************************/

int EqualityWords(void* _firstWord, void* _secondWord)
{
int j;
	if(_firstWord == NULL || _secondWord == NULL)
	{
		return 0;
	}
	
	if(strcmp(_firstWord, _secondWord) == 0)
	{
		return 1;
	}
	
return 0;
}

/**********************printKey*************************/

static void printKey(void* _word)
{
	if(_word == NULL){return;}
	printf("%-17s |    ", ((char*)_word));
}

/**********************printValue*************************/

static void printValue(void* _value)
{
	if(_value == NULL){return;}
	printf("%-2d times      |\n", (*(int*)_value));
	printf("-------------------------------------\n");
}



int main()
{
CountWordsAppearsInFile("blabla");

}
