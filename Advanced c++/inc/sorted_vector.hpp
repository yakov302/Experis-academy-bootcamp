#ifndef SORTED_VECTOR_HPP
#define SORTED_VECTOR_HPP

#include <iostream>
#include <cassert>
#include <vector>
#include"sorted_container.hpp"

namespace cpp
{

template<typename T>
class SortedVectorIterator: public ContainerIterator<T>
{
public:
    SortedVectorIterator(typename std::vector<T>::const_iterator a_it);
    void operator++();
    void operator++(int);
    T operator*()const;

private:
   typename std::vector<T>::const_iterator m_it;
};

template<typename T>
class SortedVector: public SortedContainer<T>
{
public:
    typedef T value_type;
    SortedVector(size_t a_size = 64);
    ~SortedVector();

    void insert(value_type a_item);
    size_t remove(value_type a_item);

    size_t contains(value_type a_item)const;
    size_t size()const;
    value_type front() const;
    value_type back() const;
    std::ostream& print(std::ostream& a_ostream = std::cout)const;
    
    size_t fill(value_type a_item, size_t a_times);
    value_type median()const;

    ContainerIterator<T>* begin()const; 
    ContainerIterator<T>* end()const;

private:
    typedef std::vector<T> Container;
    typedef typename Container::const_iterator ConstItr;
    typedef typename Container::iterator Itr;
    Container m_vector;
};


} //cpp namespace

#include "./inl/sorted_vector.hxx"

#endif  // SORTED_VECTOR_HPP