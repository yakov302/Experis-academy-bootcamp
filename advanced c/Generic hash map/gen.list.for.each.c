#include <stdio.h>
#include <stdlib.h>


/***********************structParameters**********************/

typedef struct Parameters
{
	ListItr m_begin;
	ListItr m_end;
	void* m_context;
	PredicateFunction m_function;
	CheckResult m_check;
}Parameters;

/***********************Functionsignatures**********************/

static ListItr InternalForEach(Parameters* _p);
static int ChackForFind(int _i);
static int  ChackForCount(int _i);
static int  ChackForEach(int _i);

/***********************ListItrFindFirst**********************/

ListItr ListItrFindFirst(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
Parameters *p;
ListItr returnNode = NULL;

	if( _begin == NULL || _end == NULL || _predicate == NULL || _context == NULL)
	{
		return NULL;
	}

	if((p = (Parameters*) malloc(sizeof(Parameters))) == NULL)
	{
		return NULL;
	}
	
	p -> m_begin = _begin;
	p ->  m_end = _end;
	p -> m_context = _context;
	p -> m_function = _predicate;
	p -> m_check = &ChackForFind;
	
	returnNode = InternalForEach(p);	
	free(p);
	
return returnNode;
}

/*****ChackForFind****/

static int ChackForFind(int _i)
{
	if(_i == 1)
	{
		return 0;
	}
return 1;
}

/***********************ListItrCountIf**********************/

size_t ListItrCountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
Parameters *p;
size_t count;

	if(_begin == NULL || _end == NULL || _predicate == NULL || _context == NULL)
	{
		return 0;
	}

	if((p = (Parameters*) malloc(sizeof(Parameters))) == NULL)
	{
		return 0;
	}
	
	p -> m_begin = _begin;
	p ->  m_end = _end;
	p -> m_context = _context;
	p -> m_function = _predicate;
	p -> m_check = &ChackForCount;	
	
	InternalForEach(p);
	count = *(int*) p -> m_context;
	free(p);
	
return count;
}

/*****ChackForCount****/

static int ChackForCount(int _i)
{
	if(_i == 0)
	{
		return 1;
	}
return _i;
}

/***********************ListItrForEach**********************/

ListItr ListItrForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{
Parameters *p;
ListItr returnNode = NULL;

	if( _begin == NULL || _end == NULL || _action == NULL)
	{
		return NULL;
	}

	if((p = (Parameters*) malloc(sizeof(Parameters))) == NULL)
	{
		return NULL;
	}
	
	p -> m_begin = _begin;
	p ->  m_end = _end;
	p -> m_context = _context;
	p -> m_function = _action;
	p -> m_check = &ChackForEach;
	
	returnNode = InternalForEach(p);	
	free(p);
	
return returnNode;
}

/*****ChackForEach****/

static int ChackForEach(int _i)
{

return _i;
}

/***********************InternalForEach**********************/

static ListItr InternalForEach(Parameters* _p)
{
int result;
Node *node = NULL;

	if(_p == NULL){return NULL;}

	node = _p -> m_begin;	
 
	while(node != _p -> m_end) 
	{
		result = _p -> m_function(ListItrGet(node), _p -> m_context);
		if(_p -> m_check (result) == 0)
		{
			break;
		}

		node = node -> m_next;		 
	} 

return node;
}



