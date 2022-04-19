#ifndef LINKED_LIST_HXX
#define LINKED_LIST_HXX

#include <cstddef>
#include <cassert>
#include <cstdio>
#include <cstring>

#include "single_list.hpp"
#include "hash_set.hpp"


template <typename T>
static void fillHashFromList(Hash *a_hashMap, LinkedList<T> const &a_list);
template <typename T>
static void getIntersection(Hash *a_hashMap, LinkedList<T> const &a_list, LinkedList<T> &a_result);
template <typename T>
static size_t HashFormula(void *a_data);
template <typename T>
static int IsEqual(void *a_firstData, void *a_secondData);
template <typename T>
static void ItemDestroy(void *a_item);

template <typename T>
class Node
{
public:
    Node();
    Node(T a_data, Node *a_next);

    T& getData();
    Node* getNext();

    void setData(T a_data);
    void setNext(Node *a_next);

private:
    void axioms() const;

private:
    T m_data;
    Node *m_next;
};

template <typename T>
Node<T>::Node() : m_data(0), m_next(0){}

template <typename T>
Node<T>::Node(T a_data, Node *a_next)
    : m_data(a_data), m_next(a_next)
{
    axioms();
}

template <typename T>
T& Node<T>::getData()
{
    return m_data;
}

template <typename T>
void Node<T>::setData(T a_data)
{
    m_data = a_data;
    axioms();
}

template <typename T>
Node<T>* Node<T>::getNext()
{
    return m_next;
}

template <typename T>
void Node<T>::setNext(Node* a_next)
{
    m_next = a_next;
    axioms();
}

template <typename T>
void Node<T>::axioms() const
{
    assert(this != 0);
}

template <typename T>
LinkedList<T>::LinkedList()
    : m_sentinal(new Node<T>()), m_head(m_sentinal), m_tail(m_sentinal), m_size(0)
{
    m_sentinal->setNext(m_sentinal);
    axioms();
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> const &source)
: m_sentinal(new Node<T>(0, m_sentinal))
, m_head(m_sentinal)
, m_tail(m_sentinal)
, m_size()
{
    m_sentinal->setNext(m_sentinal);

    Node<T>* node = source.m_head;
    LinkedList list;
    while (node != source.m_sentinal)
    {
        list.add(node->getData());
        node = node->getNext();
    }

    node = list.m_head;
    while (node != list.m_sentinal)
    {
        add(node->getData());
        node = node->getNext();
    }

    m_size = source.size();
    axioms();
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> const &source)
{
    this->~LinkedList();
    m_sentinal = new Node<T>(0, m_sentinal);
    m_head = m_sentinal;
    m_tail = m_sentinal;
    m_sentinal->setNext(m_sentinal);

    Node<T>* node = source.m_head;
    LinkedList list;
    while (node != source.m_sentinal)
    {
        list.add(node->getData());
        node = node->getNext();
    }

    node = list.m_head;
    while (node != list.m_sentinal)
    {
        add(node->getData());
        node = node->getNext();
    }

    m_size = source.size();
    axioms();
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (!isEmpty())
    {
        remove();
    }

    delete m_sentinal;
}

template <typename T>
void LinkedList<T>::add(T a_data)
{
    if (isEmpty())
    {
        Node<T>* node = new Node<T>(a_data, m_sentinal);
        m_head = node;
        m_tail = node;
    }
    else
    {
        Node<T>* node = new Node<T>(a_data, m_head);
        m_head = node;
    }
    m_size++;
    axioms();
}

template <typename T>
T LinkedList<T>::remove()
{
    assert(!isEmpty());
    Node<T>* node = m_head;
    T data = m_head->getData();
    m_head = m_head->getNext();
    m_size--;
    delete node;
    return data;
    axioms();
}

template <typename T>
T LinkedList<T>::first() const
{
    assert(!isEmpty());
    return m_head->getData();
}

template <typename T>
T LinkedList<T>::last() const
{
    assert(!isEmpty());
    return m_tail->getData();
}

template <typename T>
bool LinkedList<T>::contains(int a_data) const
{
    return containsData(*this, a_data);
}

template <typename T>
void LinkedList<T>::axioms()
{
    assert(m_size >= 0);
    assert((m_sentinal->getNext()) == m_sentinal);
    assert(m_head != 0);
    assert(m_tail != 0);
    assert(m_sentinal != 0);
}

template <typename T>
bool containsData(LinkedList<T> const &a_list, int a_data)
{
    return rangeContains(a_list.begin(), a_list.end(), a_data);
}

template <typename T>
bool rangeContains(ListIterator<T> a_begin, ListIterator<T>  a_end, T a_data)
{
    if(a_end.data() == a_data)
    {
        return true;
    }
    int save = a_end.data();
    a_end.setData(a_data);
    while (a_begin.data() != a_data)
    {
        a_begin.next();
    }
    if(a_begin.equal(a_end))
    {
        a_end.setData(save);
        return false;
    }
    return true;
    a_end.setData(save);
}

template <typename T>
LinkedList<T> const intersect(LinkedList<T> const &a_first, LinkedList<T> const &a_second, LinkedList<T> &a_result)
{
    size_t size = a_first.size();

    Hash *hashMap = HashCreate(size, HashFormula<T>, IsEqual<T>);

    fillHashFromList(hashMap, a_first);

    getIntersection(hashMap, a_second, a_result);

    HashDestroy(&hashMap, ItemDestroy<T>);
    return a_result;
}

template <typename T>
size_t LinkedList<T>::size() const
{
    return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return size() == 0;
}

template <typename T>
ListIterator<T>::ListIterator(Node<T>* a_node)
: m_current(a_node)
{

}

template <typename T>
ListIterator<T> &ListIterator<T>::next()
{
    m_current = m_current->getNext();
    return *this;
}

template <typename T>
T& ListIterator<T>::data()
{
    return m_current->getData();
}

template <typename T>
void ListIterator<T>::setData(T a_data)
{
    m_current->setData(a_data);
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
	this->next();
	return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator++(int)
{
	ListIterator opening = *this;
	++ *this;
	return opening;
}

template <typename T>
 T& ListIterator<T>::operator*()
 {
    return data();
 }

template <typename T>
 T* ListIterator<T>::operator->()
 {
    return &data();
 }

template <typename T>
static void fillHashFromList(Hash *a_hashMap, LinkedList<T> const &a_list)
{
    ListIterator<T> itr = a_list.begin();
    ListIterator<T> end = a_list.end();

    while (itr.notEqual(end))
    {
        int *value = new int;
        *value = itr.data();
        HashInsert(a_hashMap, value);
        itr.next();
    }
}

template <typename T>
static void getIntersection(Hash *a_hashMap, LinkedList<T> const &a_list, LinkedList<T> &a_result)
{
    ListIterator<T> itr = a_list.begin();
    ListIterator<T> end = a_list.end();

    while (itr.notEqual(end))
    {
        int value = itr.data();
        if (HashIsFound(a_hashMap, &value) == 1)
        {
            a_result.add(value);
        }
        itr.next();
    }
}

template <typename T>
static size_t HashFormula(void *a_data)
{
    return *(T *)a_data;
}

template <typename T>
static int IsEqual(void *a_firstData, void *a_secondData)
{
    if (*(T *)a_firstData == *(T *)a_secondData)
    {
        return 1;
    }

    return 0;
}

template <typename T>
static void ItemDestroy(void *a_item)
{
    delete (T *)a_item;
}

template <typename T>
bool operator==(ListIterator<T> const& a_first, ListIterator<T> const& a_second)
{
    return a_first.equal(a_second);
}

template <typename T>
bool operator!=(ListIterator<T> const& a_first, ListIterator<T> const& a_second)
{
    return a_first.notEqual(a_second);
}

template <typename T>
ListIterator<T> LinkedList<T>::begin() const
{
    return m_head;
}

template <typename T>
ListIterator<T> LinkedList<T>::end() const
{
    return m_sentinal;
}

template <typename T>
bool ListIterator<T>::notEqual(const ListIterator & a_itr) const
{
    return a_itr.m_current != m_current;
}

template <typename T>
bool ListIterator<T>::equal(const ListIterator & a_itr) const
{
    return a_itr.m_current == m_current;
}

#endif  // LINKED_LIST_HXX