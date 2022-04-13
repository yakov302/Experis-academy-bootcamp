#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "enum.h"
#define MAGIC_NUMBER 8123475

struct Queue
{
	int *m_que;               /*Pointer to the array*/
	size_t m_size;            /*Array size*/
	size_t m_head;            /*Index of removal*/
	size_t m_tail;            /*Index of insert*/
	size_t m_nItems;          /*Number of members in the array*/
	int m_magicNumber;        /*Flag for double destroy prevention*/	
};

/**************************QueueCreate***************************/

Queue *QueueCreate(size_t _size)
{
	Queue *ptr;
	
	if (_size == 0)
	{
		return NULL;
	}
	
	if((ptr = ((Queue*)malloc(sizeof(Queue)))) == NULL)
	{
		return NULL;
	}

	if (( ptr -> m_que = ((int*) malloc(_size * sizeof(int)))) == NULL)
	{
		free(ptr);
		return NULL;
	}

	ptr -> m_size = _size;
	ptr -> m_head = 0;
	ptr -> m_tail = 0;
	ptr -> m_nItems = 0;
	ptr -> m_magicNumber = MAGIC_NUMBER;
	
	return ptr;
}

/**************************QueueDestroy***************************/

void QueueDestroy(Queue *_queue)
{
		if(_queue == NULL || _queue -> m_magicNumber != MAGIC_NUMBER)
		{
			return;
		}
	
	_queue -> m_magicNumber = 0;
	free (_queue -> m_que);
	free(_queue);

}

/**************************QueueInsert***************************/

ADTErr QueueInsert(Queue *_queue, int _item)
{
	if(_queue == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if((_queue -> m_nItems) == (_queue -> m_size))
	{	
		return ERR_OVERFLOW;
	}
	
		_queue -> m_que[_queue -> m_tail] = _item;
		_queue -> m_tail = (_queue -> m_tail + 1)%(_queue -> m_size);
		_queue -> m_nItems++;
		return ERR_OK;
}

/**************************QueueRemove***************************/

ADTErr QueueRemove(Queue *_queue, int *_item)
{
		if(_queue == NULL || _item == NULL)
		{
			return ERR_NOT_INITIALIZED;
		}
		if (_queue -> m_nItems == 0)
		{
			return ERR_UNDERFLOW;
		}
		
		*_item = _queue -> m_que [_queue -> m_head];
		_queue -> m_head = (_queue -> m_head + 1)%(_queue -> m_size);
		_queue -> m_nItems--;
		return ERR_OK;
}

/**************************QueueIsEmpty***************************/

int QueueIsEmpty(Queue *_queue)
{
	 if (_queue == NULL)
 	{
 	 	return ERR_NO_ELEMENTS;
 	}
 	  
 	if (_queue -> m_nItems == 0)
 	{
  		return ERR_NO_ELEMENTS;
 	}
 	
return THERE_ARE_ELEMENTS;
}

/**************************QueuePrint***************************/

void QueuePrint(Queue *_queue)
{
int index = _queue -> m_head;
int size = _queue -> m_size;
int n = _queue -> m_nItems;
int i;

	if(_queue == NULL)
	{
		return;
	}

	for(i = 0 ; i < n ; i++)
	{
		printf("%d \n",  _queue -> m_que[index]);
		index = (index+1)%size;
		
	}
}


/**************************tests functions***************************/


size_t GrtSize(Queue *_queue)
{
	return _queue -> m_size;
}
size_t GetHead(Queue *_queue)
{
	return _queue -> m_head;
}
size_t GetTail(Queue *_queue)
{
	return _queue -> m_tail;
}
int GetnItems(Queue *_queue)
{
	return _queue -> m_nItems;
}

int Getx (Queue *_queue, int i)
{
	return _queue -> m_que[i];
}
















