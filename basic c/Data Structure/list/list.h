#ifndef __LIST_H__
#define __LIST_H__

typedef struct Person
{
	int m_id;                   /*Primary Key*/
	char m_name[128];
	int m_age;
	struct Person *m_next;    /*Pointer to next primary Key*/
}Person;


/*Description:
The function inserts a new node to the first member in the list (head).

Input parameters:
*_head: Pointer to the current head - the current first node on the list.
*_p: Pointer to the node we want to make the new head - put it in the first place on the list.

Output parameters: 
*_head or *_p: The new head - a pointer to the new first member on the list.*/
Person* ListInsertHead(Person *_head ,Person *_p);

/*Description:
The function deletes the first node in the list and make the second node the new head.

Input parameters:
*_head: Pointer to the current head - the current first node on the list.
**_item: Variable that will by receive the pointer to the current header - the node that will be deleted.

Output parameters: 
_head -> m_next: The new head - a pointer to the new first member on the list.*/
Person* ListRemoveHead(Person *_head, Person **_item);

/*Description:
The function inserts a new node by key - the list is sorted from the small key to the large key.

Input parameters:
*_head: Pointer to the current head - the current first node on the list.
*_p: Pointer to the node we want to insert the list.

Output parameters: 
*_head or *_p: The head - a pointer to the first member on the list.*/
Person* ListInsertByKey(Person *_head, int _key, Person *_p);

/*Description:
The function delete node by key.

Input parameters:
*_head: Pointer to the head - the first node on the list.
**_item: Variable that will by receive the pointer to the node that will be delet.

Output parameters: 
*_head: Pointer to the head - the first node on the list.*/
Person* ListRemoveByKey(Person *_head, int _key, Person **_p);

/*Description:
Function that prints all the nodes in the list.

Input parameters:
*_head: Pointer to the head - the first node on the list.*/
Person* PrintList(Person *_head);

/*Description:
The function inserts a new node by key through recursion - the list is sorted from the small key to the large key.

Input parameters:
*_head: Pointer to the current head - the current first node on the list.
*_p: Pointer to the node we want to insert the list.

Output parameters: 
*_head or *_p: The head - a pointer to the first member on the list.*/
Person* ListInsertByKeyRec(Person *_head, int _key, Person *_p);

/*Description:
The function delete node by key through recursion.

Input parameters:
*_head: Pointer to the head - the first node on the list.
**_item: Variable that will by receive the pointer to the node that will be delet.

Output parameters: 
*_head: Pointer to the head - the first node on the list.*/
Person* ListRemoveByKeyRec(Person *_head, int _key, Person **p);


#endif /*#ifndef__LIST_H__*/
