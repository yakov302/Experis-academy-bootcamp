#include <stdio.h>
#include <stdlib.h>
#include "gen.binartree.h"

/*************************structNode****************************/

struct Node
{
void* m_data;
Node* m_left;
Node* m_right;
Node* m_father;
};

/*************************structBSTree****************************/

struct BSTree
{
Node m_root;
LessComparator m_compareFunction;
};

/**********************FunctionSignatures*************************/

static void DesttroyNodes(Node* _root, void (*_destroyer)(void*));
static BSTreeItr Insert(Node* _root , void* _item, LessComparator _compare);
static Node* NewNode(Node* _father , void* _item);
static BSTreeItr FindBegin(Node* _root);
static void* OneChild(BSTreeItr _it);
static void* Leaf(BSTreeItr _it);
static void* TwoChild(BSTreeItr _it);

/*************************BSTreeCreate****************************/

BSTree* BSTreeCreate(LessComparator _less)
{
BSTree* tree;

	if((tree = ((BSTree*)malloc(sizeof(BSTree)))) == NULL)
	{
        	return NULL;
   	}
  	
   	tree -> m_root.m_right = NULL;
   	tree -> m_root.m_left = NULL;
	tree -> m_root.m_father = &tree -> m_root;
	tree -> m_compareFunction = _less;
   	
return tree; 
}

/*************************BSTreeDestroy****************************/

void BSTreeDestroy(BSTree** _tree, void (*_destroyer)(void*))
{	
	if(_tree == NULL || *_tree == NULL)
	{
		return;
	}
	
	DesttroyNodes(((BSTree*)*_tree) -> m_root.m_left, _destroyer);
		
	free(*_tree);
	*_tree = NULL;	
}


static void DesttroyNodes(Node* _root, void (*_destroyer)(void*))
{
	if(_root == NULL)
	{
		return;
	}
				
	DesttroyNodes(_root -> m_left, _destroyer);		
	DesttroyNodes(_root -> m_right, _destroyer);
	
	if( _destroyer != NULL)
	{
		_destroyer(_root ->  m_data);
	}
	free (_root);	
}

/*************************BSTreeInsert****************************/

BSTreeItr BSTreeInsert(BSTree* _tree, void* _item)
{
Node* returnNode;

	if(_tree == NULL)
	{
		return NULL; 
	}
	
	if(_tree -> m_root.m_left == NULL)
	{
		_tree -> m_root.m_left = NewNode(&_tree -> m_root , _item);	
		if (_tree -> m_root.m_left != NULL)
		{
			return _tree -> m_root.m_left;
		}
		return BSTreeItrEnd(_tree);
	}

	returnNode = Insert(_tree -> m_root.m_left,  _item, _tree -> m_compareFunction);	
	if(returnNode == NULL)
	{
		return BSTreeItrEnd(_tree);
	}
return returnNode;
}

static BSTreeItr Insert(Node* _root , void* _item, LessComparator _compare)
{
BSTreeItr returnNode;

	if(_compare(_root -> m_data, _item) == 0)
	{
		return NULL; 
	}
		
	if(_compare(_root -> m_data,  _item) > 0)
	{
		if(_root -> m_left == NULL)
		{
			_root -> m_left = NewNode(_root , _item);
			if ( _root ->  m_left != NULL)
			{
				return _root -> m_left;
			}
			return NULL; 
		}
		returnNode = Insert(_root -> m_left ,  _item, _compare);
	}
	
	if(_compare(_root -> m_data, _item) < 1)
	{
		if(_root -> m_right == NULL)
		{
			_root ->  m_right = NewNode(_root , _item);
			if ( _root ->  m_right != NULL)
			{
				return _root ->  m_right;
			}
			return NULL; 
		} 
		returnNode = Insert(_root -> m_right,  _item, _compare);
	}
return returnNode;
}

static Node* NewNode(Node* _father , void* _item)
{
Node* node;
	
	if ((node = (Node*) malloc (sizeof(Node))) == NULL)
	{
        	return NULL;
   	}
   	
   	node -> m_data = _item;
   	node -> m_left = NULL;
   	node -> m_right = NULL;
   	node -> m_father =  _father;
   	
return node;  	
}

/*************************BSTreeItrBegin****************************/

BSTreeItr BSTreeItrBegin(const BSTree* _tree)
{
Node* returnNode;

	if(_tree == NULL)
	{
		return NULL;
	}
		
	returnNode = FindBegin(_tree -> m_root.m_left);
	 
	if(returnNode == NULL)
	{
		return (Node*) &_tree -> m_root; 
	}
	
return returnNode;
}

static BSTreeItr FindBegin(Node* _root)
{
	if(_root == NULL)
	{
		return NULL;
	}
	
	if(_root -> m_left == NULL)
	{
		return _root;
	}
		
	FindBegin(_root -> m_left);
}

/*************************BSTreeItrGet****************************/

void* BSTreeItrGet(BSTreeItr _it)
{
	if(_it == NULL)
	{
		return NULL;
	}

return ((Node*) _it) -> m_data;	
}

/*************************BSTreeItrEnd****************************/

BSTreeItr BSTreeItrEnd(const BSTree* _tree)
{
	if(_tree == NULL)
	{
		return NULL;
	}

return (Node*) &_tree -> m_root;
}

/*************************BSTreeItrEquals****************************/

int BSTreeItrEquals(BSTreeItr _a, BSTreeItr _b)
{
	if(_a == NULL || _b == NULL)
	{
		return 0;
	}
	
	if(_a == _b)
	{
		return 1;
	}
	
return 0;
}

/*************************BSTreeItrNext****************************/

BSTreeItr BSTreeItrNext(BSTreeItr _it)
{
Node* node;
Node* father;

	if(_it == NULL)
	{
		return NULL;
	}
	
	if(((Node*)_it) -> m_right != NULL)
	{
		node = ((Node*)_it) -> m_right;
		while(node -> m_left != NULL)
		{
			node = node -> m_left;	
		}
		return node;
	}
	
	father = ((Node*)_it) -> m_father;
	node = _it;
	
	while(father -> m_left != node)
	{
		node = father;
		father = father -> m_father;	
	}

return father;
}

/*************************BSTreeItrPrev****************************/

BSTreeItr BSTreeItrPrev(BSTreeItr _it)
{
Node* node;
Node* father;

	if(_it == NULL)
	{
		return NULL;
	}
	
	if(((Node*)_it) ->  m_left != NULL)
	{
		node = ((Node*)_it) ->  m_left;
		while(node -> m_right != NULL)
		{
			node = node -> m_right;	
		}
		return node;
	}
	
	father = ((Node*)_it) -> m_father;
	node = _it;
	
	while(father -> m_right != node)
	{
		if(father == father -> m_father)
		{
			return  _it;
		}
		node = father;
		father = father -> m_father;	
	}

return father;
}

/*************************BSTreeItrRemove****************************/

void* BSTreeItrRemove(BSTreeItr _it)
{

	if(_it == NULL)
	{
		return NULL;
	}
	
	if(((Node*)_it) -> m_left == NULL && ((Node*)_it) -> m_right == NULL)
	{
		return Leaf(_it);
	}
	
	if(((Node*)_it) -> m_left == NULL && ((Node*)_it) -> m_right != NULL
	|| ((Node*)_it) -> m_left != NULL && ((Node*)_it) -> m_right == NULL)
	{
		 return OneChild(_it);	
	}
	
return TwoChild(_it);
}

static void* Leaf(BSTreeItr _it)
{
Node* father;
void* data;
	
	data = ((Node*)_it) -> m_data;
	
	father = ((Node*)_it) -> m_father;
			
	if(father -> m_left == _it)
	{
		father -> m_left = NULL;
	}
	else
	{
		father -> m_right = NULL;
	}
	
	free(_it);
		
return data;	
}

static void* OneChild(BSTreeItr _it)
{
Node* father;
void* data;

	data = ((Node*)_it) -> m_data;

	father = ((Node*)_it) -> m_father;

	if(((Node*)_it) -> m_right != NULL)
	{			
		if(father -> m_left == _it)
		{
			father -> m_left = ((Node*)_it) -> m_right;
		}
		else
		{
			father -> m_right = ((Node*)_it) -> m_right;
		}
	}
	
	if(((Node*)_it) -> m_left != NULL)
	{		
		if(father -> m_left == _it)
		{
			father -> m_left = ((Node*)_it) -> m_left;
		}
		else
		{
			father -> m_right = ((Node*)_it) -> m_left;
		}
	}
	
free(_it);	
return data;
}

static void* TwoChild(BSTreeItr _it)
{
Node* node;
void* dataTemp;

	node = BSTreeItrPrev(_it);
	dataTemp = ((Node*)_it) -> m_data;
	((Node*)_it) -> m_data = node ->  m_data;
	node -> m_data = dataTemp;
	
	if(node -> m_left == NULL && node -> m_right == NULL)
	{
		return Leaf(node);	
	}
return OneChild(node);
}

/*************************TestFunction****************************/

struct Person
{
int m_id;
char m_name[128];
int m_age;
}; 

void PrintInOrder(Node* _root);

void TreePrint(BSTree* _tree)
{
	if(_tree == NULL)
	{
		printf("Null tree");
	}
	

		PrintInOrder(_tree -> m_root.m_left);

}



void PrintInOrder(Node* _root)
{
	if(_root == NULL)
	{
		return;
	}
		
	if(_root -> m_left != NULL)
	{
		PrintInOrder(_root -> m_left);
		
	}
	
	printf("id: %d\n",((struct Person*)  _root -> m_data) -> m_id);
	printf("name: %s\n",((struct Person*)  _root -> m_data) -> m_name);
	printf("age: %d\n\n",((struct Person*)  _root -> m_data) -> m_age);

	if(_root -> m_right != NULL)
	{
		PrintInOrder(_root -> m_right);
	}	
	return;
}





