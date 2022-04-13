#ifndef __BINARTREE_H__
#define __BINARTREE_H__
#include "enum.h"

typedef struct Node Node;
typedef struct Tree Tree;

typedef enum{
PRE_ORDER,
IN_ORDER,
POST_ORDER
}TreeTraverse;

/*Description:
The function creates memory allocation for the tree structure.

Output parameters:
Tree*: pointer to the tree structure.*/
Tree* TreeCreate(void);

/*Description:
The function insert a new node to the tree (no duplicates).

Input parameters:
_tree:pointer to the tree structure.
_data: The value (integer) of the node.

Output parameters:
ERR_NOT_INITIALIZED: if _tree is NULL.
ERR_OK: If the node enters the tree successfully.
ERR_ALLOCATION_FAILED: If the memory allocation to the new node fails.
ERR_DUPLICATE: If the value we want to insert already exists in the tree.*/
ADTErr TreeInsert(Tree* _tree, int _data);

/*Description:
The function checks if a value exists or does not exist in the tree.

Input parameters:
_tree:pointer to the tree structure.
_data: The value we want to check.

Output parameters:
ERR_NO_ELEMENTS: if _tree or _tree -> m_root is NULL.
ERR_ELEMENT_EXIST: if _data exist in the tree.
ERR_ELEMENT_DONT_EXIST:if _data dont exist in the tree.*/
int TreeIsDataFound (Tree* _tree, int _data);

/*Description:
The function prints the values of all nodes in the tree (in three different methods).

Input parameters:
_tree:pointer to the tree structure.
_traverseMode: Print method - PRE_ORDER, IN_ORDER, POST_ORDER.*/
void TreePrint(Tree* _tree, TreeTraverse _traverseMode);

/*Description:
The function destroys all the nodes in the tree and then destroys the structure of the tree.

Input parameters:
_tree:pointer to the tree structure.*/
void TreeDesttroy(Tree* _tree);


#endif /*#ifndef__BINARTREE_H__*/
