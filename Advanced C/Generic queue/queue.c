#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**************************struct Queue***************************/

struct Queue
{
	void **m_que;               /*Pointer to the array*/
	size_t m_size;            /*Array size*/
	size_t m_head;            /*Index of removal*/
	size_t m_tail;            /*Index of insert*/
	size_t m_nItems;          /*Number of members in the array*/
};

/**************************QueueCreate***************************/

Queue *QueueCreate(size_t _size)
{
Queue *queue;
	
	if (_size == 0)
	{
		return NULL;
	}
	
	if((queue = ((Queue*)malloc(sizeof(Queue)))) == NULL)
	{
		return NULL;
	}

	if (( queue -> m_que = ((void**) malloc(_size * sizeof(void*)))) == NULL)
	{
		free(queue);
		return NULL;
	}

	queue -> m_size = _size;
	queue -> m_head = 0;
	queue -> m_tail = 0;
	queue -> m_nItems = 0;
	
return queue;
}

/**************************QueueDestroy***************************/

void QueueDestroy(Queue**_queue, DestroyItem ItemDestroy)
{
size_t j;
size_t i;

	if(_queue == NULL || *_queue == NULL)
	{
		return;
	}

	j = (*_queue) -> m_head;

	if(ItemDestroy != NULL)
	{		
		for(i = 0; i < (*_queue)-> m_nItems ; i++)
		{			
			ItemDestroy((*_queue) -> m_que[j]);
			j = (j+1)%((*_queue) -> m_size);
		}
	}
	

	free ((*_queue) -> m_que);
	free((*_queue));
	*_queue = NULL;
}

/**************************QueueInsert***************************/

QueueResult QueueInsert(Queue *_queue, void* _item)
{
	if(_queue == NULL || _item == NULL)
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	
	if((_queue -> m_nItems) == (_queue -> m_size))
	{	
		return QUEUE_OVERFLOW_ERROR;
	}
	
	_queue -> m_que[_queue -> m_tail] = _item;
	_queue -> m_tail = (_queue -> m_tail + 1)%(_queue -> m_size);
	_queue -> m_nItems++;
		
return QUEUE_SUCCESS;
}

/**************************QueueRemove***************************/

QueueResult QueueRemove(Queue *_queue, void**_item)
{
	if(_queue == NULL || _item == NULL)
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	
	if (_queue -> m_nItems == 0)
	{
		return QUEUE_UNDERFLOW_ERROR;
	}
		
	*_item = _queue -> m_que [_queue -> m_head];
	_queue -> m_head = (_queue -> m_head + 1)%(_queue -> m_size);
	_queue -> m_nItems--;
	
return QUEUE_SUCCESS;
}

/**************************QueueIsEmpty***************************/

int QueueIsEmpty(Queue *_queue)
{
	 if (_queue == NULL)
 	{
 	 	return QUEUE_DATA_UNINITIALIZED_ERROR;
 	}
 	  
 	if (_queue -> m_nItems == 0)
 	{
  		return QUEUE_DATA_UNINITIALIZED_ERROR;
 	}
 	
return QUEUE_THERE_ARE_DATA;
}

/**************************QueueForEach***************************/

size_t QueueForEach(Queue *_queue, ActionFunction Action , void* _context)
{
size_t j; 
size_t i;

	if(_queue == NULL || Action == NULL)
	{
		return;
	}
	
	j = (_queue -> m_head) -1;

	for(i = 0; i < _queue -> m_nItems ; i++)
	{
		j = (j+1)%(_queue -> m_size);
		if(Action(_queue -> m_que[j], _context) == 0)
		{
			break;
		}		
	}
return i;
}


/**************************tests functions***************************/


/*size_t GrtSize(Queue *_queue)
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
}*/
















