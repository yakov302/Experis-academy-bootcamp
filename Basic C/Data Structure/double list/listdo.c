#include <stdio.h>
#include <stdlib.h>
#include "listdo.h"
#include "enum.h"
#define MAGIC_NUMBER 942199

/***********************structNode**********************/

struct Node
{
int m_data;
struct Node *m_next;
struct Node *m_prev;
};

/***********************structList**********************/

struct List
{
Node m_head;
Node m_tail;
int m_magicNumber; 
};

/***********************ListCreate**********************/

List* ListCreate(void)
{

List* list;

	if ((list = (List*) malloc (sizeof(List))) == NULL) 
	{
        	return NULL;
   	}
   	
   	list-> m_head.m_next = &list-> m_tail;
  	list-> m_head.m_prev = NULL;
  	list-> m_tail.m_next = NULL;
	list-> m_tail.m_prev = &list-> m_head;
	
  	return list;
}

/***********************ListDestroy**********************/

void ListDestroy(List* _list)
{
Node* temp;

	if(_list == NULL || _list-> m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	
	_list-> m_magicNumber = 0;
	temp = _list-> m_head.m_next;
   	while (temp != &_list-> m_tail)
    	{
      	 	free(temp);
      	 	temp = temp -> m_next;   		
    	}
	free(_list);
	return;
}

/***********************PushNode**********************/

void PushNode(Node *_node, Node *_next)
{
	_node -> m_prev = _next -> m_prev;
	_node -> m_next = _next;
	_next -> m_prev -> m_next = _node;
	_next -> m_prev = _node;
}

/***********************ListPushHead**********************/

ADTErr ListPushHead(List* _list, int _data)
{
Node *node = NULL;

	if(_list == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	if((node = (Node*) malloc(sizeof(Node))) == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	node -> m_data = _data;
	PushNode(node,_list -> m_head.m_next);
	
return ERR_OK;
}

/***********************ListPushTail**********************/

ADTErr ListPushTail(List* _list, int _data)
{
Node* node = NULL;

	if(_list == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	if((node = (Node*) malloc(sizeof(Node))) == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	node -> m_data = _data;
	PushNode(node, &_list -> m_tail);

return ERR_OK;
}

/***********************PopNode**********************/

void PopNode(Node *_node)
{
	_node -> m_next -> m_prev = _node -> m_prev;
	_node -> m_prev -> m_next = _node -> m_next;
	free(_node);
}

/***********************ListPopHead**********************/

ADTErr ListPopHead(List *_list, int *_data)
{
	if (_list == NULL || _data == NULL) 
	{
        return ERR_NOT_INITIALIZED;
   	}
   		
	if(_list -> m_head.m_next == &_list -> m_tail)
	{
		return ERR_UNDERFLOW;
	}
	
	*_data = _list -> m_head.m_next -> m_data;
	PopNode (_list -> m_head.m_next);
   
   return ERR_OK;
}

/***********************ListPopTail**********************/

ADTErr ListPopTail(List *_list, int *_data)
{

	if (_list == NULL || _data == NULL) 
	{
        return ERR_NOT_INITIALIZED;
   	}
   	
	if(_list ->m_head.m_next == &_list -> m_tail)
	{
		return ERR_UNDERFLOW;
	}
	
	*_data = _list-> m_tail.m_prev -> m_data;
	PopNode(_list -> m_tail.m_prev);
	
return ERR_OK;
}

/***********************ListCountItems**********************/

size_t ListCountItems(List *_list)
{
int count;
Node *node;
count = 0;

	if (_list == NULL) 
	{
        return ERR_NOT_INITIALIZED;
   	} 
	
	node =_list -> m_head.m_next;

	while(node != &_list-> m_tail) 
	{
		count++;	
		node = node -> m_next; 
	} 
	return count;
}

/***********************ListIsEmpty**********************/

int ListIsEmpty(List* _list)
{
	if (_list == NULL) 
	{
        return ERR_NOT_INITIALIZED;
   	} 
   	
	if(_list -> m_head.m_next == &_list -> m_tail && _list -> m_tail.m_prev == &_list -> m_head)
	{
		return ERR_NO_ELEMENTS;
	}

return ERR_THERE_ARE_ELEMENTS;
}

/***********************ListPrint**********************/

void ListPrint(List* _list)
{
int i;
Node *node;
i = 1;

	if (_list == NULL) 
	{
        return;
   	} 
	
	node =_list -> m_head.m_next;

	while(node != &_list-> m_tail) 
	{
		printf("\n"); 
		printf("Node number %d \n", i); 
		printf("Data: %d\n", node -> m_data);
		printf("\n"); 
		i++; 
		node = node -> m_next; 
	} 
}

/***********************TestFunction**********************/


Node* GetmHeadMPrev(List *_list)
{
	return _list-> m_head.m_prev;
}

int GetData(List* _list, int index)
{
int i;
Node *node;

	node = _list -> m_head.m_next;

	for(i = 0; i < index + 1; i++)
	{ 	
		if(i == index)
		{
			return node -> m_data;
		}
		node = node -> m_next;			
	}
}











