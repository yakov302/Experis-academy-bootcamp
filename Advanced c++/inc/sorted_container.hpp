#ifndef SORTED_CONTAINER_HPP
#define SORTED_CONTAINER_HPP

#include <iostream>
#include <cassert>

namespace cpp
{

template<typename T>
class ContainerIterator
{
public:
    ContainerIterator();
    virtual ~ContainerIterator();
    virtual void operator++() = 0;
    virtual void operator++(int) = 0;
    virtual T operator*()const = 0;
    virtual bool operator==(const ContainerIterator<T>& a_rhs)const;
    virtual bool operator!=(const ContainerIterator<T>& a_rhs)const;

private:
    ContainerIterator& operator=(ContainerIterator const& a_containerIterator);
    ContainerIterator(ContainerIterator const& a_containeIteratorr);
};


template<typename T>
class SortedContainer
{
public:
    typedef T value_type;
    SortedContainer();
    virtual ~SortedContainer() = 0;

    virtual void insert(value_type a_item) = 0;
    virtual size_t remove(value_type a_item) = 0;
    
    virtual value_type front() const = 0;
    virtual value_type back() const = 0;
    virtual size_t size() const = 0;
    virtual size_t contains(value_type a_item)const = 0;
    virtual std::ostream& print(std::ostream& a_ostream)const = 0;

    virtual size_t fill(value_type a_item, size_t a_times);

    virtual ContainerIterator<T>* begin()const = 0; 
    virtual ContainerIterator<T>* end()const = 0;

    bool empty()const;

private:
    SortedContainer& operator=(SortedContainer const& a_container);
    SortedContainer(SortedContainer const& a_container);
};

template<typename T>
bool isUniform(SortedContainer<T> const& a_container);

template<typename T>
bool isSorted(SortedContainer<T> const& a_container);

template<typename T>
typename T::value_type containerMedian(T const& a_container);

template <typename T>
std::ostream& printContainer(T const& a_container, std::ostream& a_ostream = std::cout);

template<typename T>
inline bool empty(SortedContainer<T> const& a_container){return a_container.size() == 0;}

template<typename T>
std::ostream& operator<<(std::ostream& a_ostream, SortedContainer<T>  const& a_container);


} //cpp namespace

#include "./inl/sorted_container.hxx"

#endif  // SORTED_CONTAINER_HPP