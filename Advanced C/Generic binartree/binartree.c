#include <stdio.h>
#include <stdlib.h>
#include "binartree.h"
#include "enum.h"
#define MAGIC_NUMBER 942199

/*************************Auxiliary functions****************************/

ADTErr Insert(Node* _root , int _data);
Node* NewNode(Node* _father , int _data);
ADTErr Search(Node* _root , int _data);
void PrintPreOrder(Node* _root);
void PrintInOrder(Node* _root);
void PrintPostOrder(Node* _root);
void DesttroyNodes(Node* _root);

/*************************StructNode****************************/

struct Node
{
int m_data;
Node* m_left;
Node* m_right;
Node* m_father;
};

/*************************StructTree****************************/

struct Tree
{
Node* m_root;
int m_magicNumber; 
};

/*************************TreeCreate****************************/

Tree* TreeCreate(void)
{

Tree* ptr;

	if((ptr = ((Tree*)malloc(sizeof(Tree)))) == NULL)
	{
        	return NULL;
   	}

   	
   	ptr -> m_root = NULL;
   	ptr -> m_magicNumber = MAGIC_NUMBER;
   	
   	return ptr;  	
}

/*************************TreeInsert****************************/

ADTErr TreeInsert(Tree* _tree, int _data)
{
	if(_tree == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	if(_tree -> m_root == NULL)
	{
		_tree -> m_root = NewNode(NULL , _data);	
		if (_tree -> m_root != NULL)
		{
			return ERR_OK;
		}
		return ERR_ALLOCATION_FAILED;
	}

	return Insert(_tree -> m_root,  _data);	
}


ADTErr Insert(Node* _root , int _data)
{
ADTErr status;
	if(_root -> m_data == _data)
	{
		return ERR_DUPLICATE;
	}
		
	if(_root -> m_data > _data)
	{
		if(_root -> m_left == NULL)
		{
			_root -> m_left = NewNode(_root , _data);
			if ( _root ->  m_left != NULL)
			{
			return ERR_OK;
			}
			return ERR_ALLOCATION_FAILED;
		}
		status = Insert(_root -> m_left ,  _data);
	}
	
	if(_root -> m_data < _data)
	{
		if(_root -> m_right == NULL)
		{
			_root ->  m_right = NewNode(_root , _data);
			if ( _root ->  m_right != NULL)
			{
			return ERR_OK;
			}
			return ERR_ALLOCATION_FAILED;
		} 
		status = Insert(_root -> m_right,  _data);
	}
return status;
}


Node* NewNode(Node* _father , int _data)
{
Node* node;
	
	if ((node = (Node*) malloc (sizeof(Node))) == NULL)
	{
        	return NULL;
   	}
   	
   	node -> m_data = _data;
   	node -> m_left = NULL;
   	node -> m_right = NULL;
   	node -> m_father =  _father;
   	
   	return node;  	
}

/*************************TreeIsDataFound****************************/

int TreeIsDataFound (Tree* _tree, int _data)
{

	if(_tree == NULL || _tree -> m_root == NULL)
	{
		return ERR_NO_ELEMENTS;
	}
		
	return Search(_tree -> m_root,  _data);		
}


ADTErr Search(Node* _root , int _data)
{ 
ADTErr status;

	if(_root -> m_data == _data)
	{	
		 return ERR_ELEMENT_EXIST;		
	}
		
	if(_root -> m_data > _data)
	{
		if(_root -> m_left == NULL)
		{	
			return ERR_ELEMENT_DONT_EXIST;		
		}
		status = Search(_root -> m_left ,  _data);
	}
	
	if(_root -> m_data < _data)
	{
		if(_root -> m_right == NULL)
		{
			return  ERR_ELEMENT_DONT_EXIST;		
		} 
		status = Search(_root -> m_right,  _data);
	}
return status;
}

/*************************TreePrint****************************/

void TreePrint(Tree* _tree, TreeTraverse _traverseMode)
{
	if(_tree == NULL)
	{
		printf("Null tree");
	}
	
	if(_traverseMode == PRE_ORDER)
	{
		PrintPreOrder(_tree -> m_root);
	}
	if(_traverseMode == IN_ORDER)
	{
		PrintInOrder(_tree -> m_root);
	}
	if(_traverseMode == POST_ORDER)
	{
		PrintPostOrder(_tree -> m_root);
	}

}

void PrintPreOrder(Node* _root)
{
	if(_root == NULL)
	{
		return;
	}
	
	printf("%d\n", _root -> m_data);
	
	if(_root -> m_left != NULL)
	{
		PrintPreOrder(_root -> m_left);
	}
	
	if(_root -> m_right != NULL)
	{
		PrintPreOrder(_root -> m_right);
	}
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
	
	printf("%d\n", _root -> m_data);
	
	if(_root -> m_right != NULL)
	{
		PrintInOrder(_root -> m_right);
	}	
	return;
}

void PrintPostOrder(Node* _root)
{
	if(_root == NULL)
	{
		return;
	}	
		
	if(_root -> m_left != NULL)
	{
		PrintPostOrder(_root -> m_left);	
	}
	
	PrintPostOrder(_root -> m_right);
	printf("%d\n", _root -> m_data);	
}

/*************************TreeDesttroy****************************/

void TreeDesttroy(Tree* _tree)
{

	if(_tree == NULL || _tree -> m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	
	_tree -> m_magicNumber = 0;
	DesttroyNodes(_tree -> m_root);
	free(_tree);	
}

void DesttroyNodes(Node* _root)
{

	if(_root == NULL)
	{
		return;
	}
		
	if(_root -> m_left != NULL)
	{
		DesttroyNodes(_root -> m_left);	
	}
	
	DesttroyNodes(_root -> m_right);
	free (_root);	
}








