#include <iostream>
#include <cassert>
#include <vector>
#include <cstdio>
#include "sorted_vector.hpp"
#include "sorted_container.hpp"

namespace cpp
{

template<typename T>
SortedUniqueVector<T>::SortedUniqueVector(size_t a_size)
: SortedContainer<T>()
, m_vector()
{
    m_vector.reserve(a_size);
}

template<typename T>
SortedUniqueVector<T>::~SortedUniqueVector()
{

}

template<typename T>
void SortedUniqueVector<T>::insert(value_type a_item)
{
    if(contains(a_item))
    {
        return;
    }
    size_t size = m_vector.size();
    for(size_t i = 0; i < size; i++)
    {
        if(a_item < m_vector[i])
        {
            m_vector.insert(m_vector.begin() + i, a_item);
            return;
        }
    }
    m_vector.push_back(a_item);
}

template<typename T>
size_t SortedUniqueVector<T>::remove(value_type a_item)
{
    size_t size = m_vector.size();
    for(size_t i = 0; i < size; ++i)
    {
        if(a_item == m_vector[i])
        {
            m_vector.erase(m_vector.begin() + i);
            return 1;
        }
    }
    return 0;
}

template<typename T>
size_t SortedUniqueVector<T>::contains(value_type a_item)const
{
    ConstItr end = m_vector.end();
    ConstItr it = std::lower_bound(m_vector.begin(), m_vector.end(), a_item);
    size_t count = 0;
    while(it != end && *it == a_item)
    {
        ++count;
        ++it;
    }
    return count;
}

template<typename T>
typename SortedUniqueVector<T>::value_type SortedUniqueVector<T>::front() const
{
    return m_vector.front();
}

template<typename T>
typename SortedUniqueVector<T>::value_type SortedUniqueVector<T>::back() const
{
    return m_vector.back();
}

template<typename T>
std::ostream& SortedUniqueVector<T>::print(std::ostream& a_ostream)const
{
    return printContainer(m_vector, a_ostream);
}

template<typename T>
size_t SortedUniqueVector<T>::size()const
{
    return m_vector.size();
}

template<typename T>
size_t SortedUniqueVector<T>::fill(value_type a_item, size_t a_times)
{
    if(contains(a_item))
    {
        return 0;
    }
    insert(a_times);
    return 1;
}

template<typename T>
typename SortedUniqueVector<T>::value_type SortedUniqueVector<T>::median() const
{
    return containerMedian(m_vector);
}

template<typename T>
ContainerIterator<T>* SortedUniqueVector<T>::begin()const
{
    return new SortedVectorIterator<T>(m_vector.begin());
}

template<typename T>
ContainerIterator<T>* SortedUniqueVector<T>::end()const 
{
   return new SortedVectorIterator<T>(m_vector.end());
}


} //cpp namespace