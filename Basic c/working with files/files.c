#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_SIZE 80
#define WORD_SIZE 80


typedef struct word
{
	char m_word[WORD_SIZE];                  
	int m_count;
	struct word *m_next;
}w;


typedef struct arr
{
w** arr;
}arr;


arr *CreateArr(void)
{
int i;
arr *ptr;
	
	if((ptr = ((arr*)malloc(sizeof(arr)))) == NULL)
	{
		return NULL;
	}
	
	if (( ptr -> arr = ((w**) malloc(26 * sizeof(w*)))) == NULL)
	{
		free(ptr);
		return NULL;
	}
	
	for(i = 0; i < 27; i++)
	{
		ptr -> arr[i] = NULL;
	}
	
	return ptr;
}



w *CreateWord (char _word[])
{
	w *ptr;
	
	if (_word == NULL)
	{
		return NULL;
	}
	
	if((ptr = ((w*)malloc(sizeof(w)))) == NULL)
	{
		return NULL;
	}
	
	strcpy((ptr -> m_word), _word);
	ptr -> m_count = 1;
	ptr -> m_next = NULL;
	
	return ptr;
}



w* WordInsert(w *_head, char _word[], w*_p)
{

w *ptr;
w *previous;
ptr = _head;
previous = NULL;


	if(_head == NULL)
	{
		return _p;
	}
	if(_p == NULL)
	{
		return _head;
	}
	
	while(ptr != NULL) 
	{

		if(strcmp(ptr -> m_word ,  _word) == 0)
		{
			ptr -> m_count++;
			free(_p);
			return _head;		
		}
		
		if(strcmp(ptr -> m_word ,  _word) < 0)
		{
			if(previous == NULL)
			{
				_p -> m_next = ptr;
				return _p;
			}
			_p -> m_next = ptr;
			previous -> m_next = _p;
			return _head;		
		}
		previous = ptr;
		ptr = ptr -> m_next;
	}
	
_p -> m_next = NULL;
previous -> m_next = _p;
return _head;
}




w* PrintList(w *_head)
{
int i;
w *ptr;
ptr = _head;
i = 1;

		
	while(ptr != NULL) 
	{
		printf("%-17s |    ", ptr -> m_word);		
		printf("%d times      |\n", ptr -> m_count);
		printf("-------------------------------------\n");
		ptr = ptr -> m_next; 
	}
}




WoedCount(char _fileName[])
{
FILE *ptr;
char word[WORD_SIZE];
int index;
arr* arrPtr;
w* worfPtr;
w* lest;
int i;
w* insert;
int j;

	if ((ptr = fopen(_fileName, "r")) == NULL)
	{
		printf("cant open");
		return;
	}
	
	arrPtr = CreateArr();
	
	while(!feof(ptr))
	{
		fscanf(ptr, "%s", word);
		
		if(word[0] <= 'Z' && word[0] >= 'A')
		{
			word[0] = word[0] + 32;
		}
		if(word[0] <= 'z' && word[0] >= 'a')
		{
			index = word[0] - 'a';
	        }
	       for(j = 0; j < strlen(word); j++)
	        {
	        	if( word[j] == '.' || word[j] == ',' || word[j] == ':' || word[j] == '\n' || word[j] == ';' || word[j] == ' ')
	        	{
	        		word[j] = '\0';
	        	}
	        }
	    	worfPtr = CreateWord(word);
		insert = WordInsert(arrPtr -> arr [index], word, worfPtr);
		arrPtr -> arr [index] = insert;
	 }
	 lest = arrPtr -> arr [index];
	 while( lest -> m_next != NULL) 
	{
		lest = lest -> m_next;
	}
	lest ->m_count--;

	
	


		fclose(ptr);
		
		printf("-------------------------------------\n");
		for(i = 0; i < 27; i++)
		{
			PrintList(arrPtr -> arr [i]);
		}		
}





charactersCount(char _fileName[])
{
FILE *ptr;
int charCount[ARR_SIZE];
char charNow;
int i;

	if ((ptr = fopen("blabla", "r")) == NULL)
	{
		printf("cant open");
		return;
	}
	
	for(i =0; i < ARR_SIZE; i++)
	{
		charCount[i] = 0;
	}
	

	while(!feof(ptr))
	{	
	    charNow = fgetc(ptr);
		if((charNow - '0') < 44 && (charNow - '0') > 16 || (charNow - '0') < 76 && (charNow - '0') > 48)
		{
			charCount[charNow - '0']++;
		}	
	}
		
	for(i = 17; i < 43; i++)
	{
		printf("%c: ", i + '0');
		printf("%d\n", charCount[i]);
	}
	
	for(i =49; i <75; i++)
	{
		printf("%c: ", i + '0');
		printf("%d\n", charCount[i]);
	}
	
	fclose(ptr);
}





int main()
{
charactersCount("blabla");
printf("\n");
WoedCount("blabla");

}


