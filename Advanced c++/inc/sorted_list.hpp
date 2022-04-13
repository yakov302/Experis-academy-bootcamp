#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

#include <iostream>
#include <cassert>
#include <list>
#include "sorted_container.hpp"

namespace cpp
{

template<typename T>
class SortedListIterator: public ContainerIterator<T>
{
public:
    SortedListIterator(typename std::list<T>::const_iterator a_it);
    void operator++();
    void operator++(int);
    T operator*()const;

private:
   typename std::list<T>::const_iterator m_it;
};

template<typename T>
class SortedList: public SortedContainer<T>
{
public:
    typedef T value_type;
    SortedList();
    ~SortedList();

    void insert(value_type a_item);
    size_t remove(value_type a_item);

    size_t size()const;
    value_type front() const;
    value_type back() const;
    size_t contains(value_type a_item) const;
    std::ostream& print(std::ostream& a_ostream = std::cout) const;
    
    value_type median()const;

    ContainerIterator<T>* begin()const; 
    ContainerIterator<T>* end()const;

private:
    typedef std::list<T> Container;
    typedef typename Container::const_iterator ConstItr;
    typedef typename Container::iterator Itr;
    Container m_list;
};


} //cpp namespace

#include "./inl/sorted_list.hxx"

#endif  // SORTED_LIST_HPP