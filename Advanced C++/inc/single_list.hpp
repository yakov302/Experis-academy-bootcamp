#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstddef>

template <typename T>
class Node;

template <typename T>
class ListIterator: public std::iterator<std::input_iterator_tag, int>
{
public:
    ListIterator(Node<T>* a_node = 0);

    ListIterator& next();
    T& data();
    void setData(T a_data);

    bool equal(const ListIterator<T>& a_itr) const;
    bool notEqual(const ListIterator<T> &a_itr) const;

    ListIterator& operator++();
	ListIterator operator++(int);
    T& operator*();
    T* operator->();

private:
    Node<T>* m_current;
};

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(LinkedList const &source);
    LinkedList &operator=(LinkedList const &source);
    ~LinkedList();

    void add(T a_data); 
    T remove();

    T first() const;  
    T last() const;  

    ListIterator<T> begin() const;
    ListIterator<T> end() const;

    size_t size() const;
    bool isEmpty() const;
    bool contains(int a_data) const;

private:
    void axioms();    
  
private:
    Node<T>* m_sentinal;
    Node<T>* m_head;
    Node<T>* m_tail;
    size_t m_size;
};

template <typename T>
LinkedList<T> const intersect (LinkedList<T> const& a_first, LinkedList<T> const& a_second, LinkedList<T>& a_result);

template <typename T>
bool containsData(LinkedList<T> const& a_list, int a_data);
template <typename T>
bool rangeContains(LinkedList<T> a_begin, LinkedList<T> a_end, int a_data);

template <typename T>
bool operator==(LinkedList<T> const& a_first, LinkedList<T> const& a_second);
template <typename T>
bool operator!=(LinkedList<T> const& a_first, LinkedList<T> const& a_second);




#include "./inl/singel_list.hxx"

#endif  // LINKED_LIST_HPP