#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "enum.h"
#define MAGIC_NUMBER 942199

/***********************ListInsertHead**********************/

Person* ListInsertHead(Person *_head ,Person *_p)
{
	if(_p == NULL)
	{
		return _head;
	}
		_p -> m_next = _head;
     	
return _p;
}

/***********************ListRemoveHead**********************/

Person* ListRemoveHead(Person *_head, Person **_item)
{
	if(_item == NULL)
	{
		return _head;
	}
	if(_head == NULL)
	{
		*_item = NULL;
		return _head;
	}
	
	*_item = _head;
	return _head -> m_next;
}

/*********************ListInsertByKey*********************/

Person* ListInsertByKey(Person *_head, int _key, Person *_p)
{

Person *ptr;
Person *previous;
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
		if(ptr ->  m_id == _key)
		{
			return _head;		
		}
		
		if(ptr ->  m_id < _key)
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

/*********************ListRemoveByKey*********************/

Person* ListRemoveByKey(Person *_head, int _key, Person **_p)
{
Person *ptr;
Person *previous;
ptr = _head;
previous = NULL;
	
	if(_p == NULL)
	{
		return _head;
	}
	if(_head == NULL)
	{
		*_p = NULL;
		return _head;
	}
	
	while(ptr != NULL) 
	{
		if(ptr ->  m_id  < _key)
		{
			return _head;
		}
		if(ptr ->  m_id  == _key)
		{	
			if(previous == NULL)
			{
				*_p = ptr;
				return ptr -> m_next;
			}
			*_p = ptr;
			previous -> m_next = ptr -> m_next;
			return _head;		
		}
		previous = ptr;
		ptr = ptr -> m_next;
	}
}



/***********************PrintList**********************/

Person* PrintList(Person *_head)
{
int i;
Person *ptr;
ptr = _head;
i = 1;

	while(ptr != NULL) 
	{
		printf("Node number %d: \n", i);
		printf("Id: %d \n", ptr -> m_id);
		printf("Name: %s \n", ptr -> m_name);
		printf("Age: %d \n", ptr -> m_age);
		printf("Next node: %p\n",(void*) ptr -> m_next);
		printf("\n\n");
		ptr = ptr -> m_next; 
		i++;	
	}
}

/***********************ListInsertByKeyRec**********************/

Person* ListInsertByKeyRec(Person *_head, int _key, Person *_p)
{
	if(_p == NULL)
	{
		return _head;
	}
	
	if(_head == NULL || _key < _head -> m_id){
		_p -> m_next = _head;
		return _p;
	}
	
	if(_key == _head -> m_id)
	{
		return _head;
	}
	
	_head -> m_next = ListInsertByKeyRec(_head -> m_next, _key, _p);
	return _head;
}


/***********************ListRemoveByKeyRec**********************/

Person* ListRemoveByKeyRec(Person* _head, int _key, Person**_p)
{
	if(_head == NULL || _p == NULL || _key < _head -> m_id)
	{
		return _head;
	}
	
	if(_key == _head -> m_id)
	{
		*_p = _head;
		return _head -> m_next;
	}
	
	_head -> m_next = ListRemoveByKeyRec(_head -> m_next, _key, _p);
	return _head;
}

/***********************PointerToLastNodeRec**********************/

Person* PointerToLastNodeRec (Person* _head )
{
	if (_head == NULL || _head -> m_next == NULL)
	{
		return _head;
	}

	 return PointerToLastNodeRec(_head -> m_next);
}

/***********************GetYoungAgeRec**********************/

int GetYoungAgeRec(Person *_head)
{
int min;

	if (_head == NULL)
	{
		return -1;
	}
	if (_head -> m_next == NULL)
	{
		return _head -> m_age;
	}
	
	min = GetYoungAgeRec(_head -> m_next);
	
	if( _head -> m_age < min)
	{
		return _head -> m_age;
	}

	 return min;
}

























