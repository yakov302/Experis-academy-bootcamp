#ifndef SORTED_UNIQUE_LIST_HPP
#define SORTED_UNIQUE_LIST_HPP

#include <iostream>
#include <cassert>
#include <list>
#include "sorted_container.hpp"
#include "sorted_list.hpp"

namespace cpp
{

template<typename T>
class SortedUniqueList: public SortedContainer<T>
{
public:
    typedef T value_type;
    SortedUniqueList();
    ~SortedUniqueList();

    void insert(value_type a_item);
    size_t remove(value_type a_item);

    size_t contains(value_type a_item) const;
    size_t size()const;
    value_type front() const;
    value_type back() const;
    std::ostream& print(std::ostream& a_ostream = std::cout) const;

    value_type median()const;
    size_t fill(value_type a_item, size_t a_times);

    ContainerIterator<T>* begin()const; 
    ContainerIterator<T>* end()const;

private:
    typedef std::list<T> Container;
    typedef typename Container::const_iterator ConstItr;
    typedef typename Container::iterator Itr;
    Container m_list;
};


} //cpp namespace

#include "./inl/sorted_unique_list.hxx"

#endif  // SORTED_UNIQUE_LIST_HPP