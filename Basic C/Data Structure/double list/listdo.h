#ifndef __LISTDO_H__
#define __LISTDO_H__
#include "enum.h"

typedef struct Node Node;

typedef struct List List;

/*Description:
The function make allocation to a new double-sided list that contains a head node and a tail node that point to each other from the inside and to NULL outside.

Output parameters: 
NULL: If the allocation failed.
list: Pointer to the head node of the list.*/
List* ListCreate(void);

/*Description:
The function free all the nodes in the list and then free the list.

Input parameters:
* _list: Pointer to the head node of the list.

Output parameters: 
NULL: if * _list is NULL.*/
void ListDestroy(List* _list);

/*Description:
The function insert a new node at the top of the list (after the head node)

Input parameters:
* _list: Pointer to the head node of the list.
_data: int number that will be inside the node

Output parameters: 
ERR_NOT_INITIALIZED: if * _list is NULL or if the memory allocation to the node fails.
ERR_OK: If the new node enters the list successfully.*/
ADTErr ListPushHead(List* _list, int _data);

/*Description:
The function insert a new node at the end of the list (before tail node)

Input parameters:
* _list: Pointer to the head node of the list.
_data: int number that will be inside the node

Output parameters: 
ERR_NOT_INITIALIZED: if * _list is NULL or if the memory allocation to the node fails.
ERR_OK: If the new node enters the list successfully.*/
ADTErr ListPushTail(List* _list, int _data);

/*Description:
The function deletes the first node in the list and passes its data to the variable *_data.

Input parameters:
* _list: Pointer to the head node of the list.
*_data: variable that will receive the data of the deleted node.

Output parameters: 
ERR_NOT_INITIALIZED: if * _list is NULL or if *_data is NULL.
ERR_UNDERFLOW: If there are no nodes in the list.
ERR_OK: If the node is successfully deleted and its data is stored in *_data variable.*/
ADTErr ListPopHead(List *_list, int *_data);

/*Description:
The function deletes the lest node in the list and passes its data to the variable *_data.

Input parameters:
* _list: Pointer to the head node of the list.
*_data: variable that will receive the data of the deleted node.

Output parameters: 
ERR_NOT_INITIALIZED: if * _list is NULL or if *_data is NULL.
ERR_UNDERFLOW: If there are no nodes in the list.
ERR_OK: If the node is successfully deleted and its data is stored in *_data variable.*/
ADTErr ListPopTail(List *_list, int *_data);

/*Description:
The function counts how many nodes there are in the list.

Input parameters:
* _list: Pointer to the head node of the list.

Output parameters: 
count: The number of nodes is in the list.*/
size_t ListCountItems(List *_list);

/*Description:
The function checks if the list is empty.

Input parameters:
* _list: Pointer to the head node of the list.

Output parameters:
ERR_NOT_INITIALIZED: if * _list is NULL. 
ERR_NO_ELEMENTS: If the list is empty.
ERR_THERE_ARE_ELEMENTS:If the list is not empty */
int ListIsEmpty(List* _list);

/*Description:
The function prints the data of all nodes in the list.

Input parameters:
* _list: Pointer to the head node of the list.*/
void ListPrint(List* _list);

void PopNode(Node *_node);
void PushNode(Node *_node, Node *_next);

#endif /*#ifndef__LISTDO_H__*/



