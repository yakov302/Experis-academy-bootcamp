#include <iostream>
#include <cassert>
#include <vector>
#include <cstdio>
#include "sorted_vector.hpp"

namespace cpp
{

template<typename T>
SortedVector<T>::SortedVector(size_t a_size)
: SortedContainer<T>()
, m_vector()
{
    m_vector.reserve(a_size);
}

template<typename T>
SortedVector<T>::~SortedVector(){}

template<typename T>
void SortedVector<T>::insert(T a_item)
{
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
size_t SortedVector<T>::remove(T a_item)
{
    size_t size = m_vector.size();
    size_t count = 0;
    for(size_t i = 0; i < size; ++i)
    {
        if(a_item == m_vector[i])
        {
            m_vector.erase(m_vector.begin() + i);
            if(i != size - 1)
            {
                --i;  
            }
            ++count;
        }
    }
    return count;
}

template<typename T>
size_t SortedVector<T>::contains(T a_item)const
{
    typename std::vector<T>::const_iterator end = m_vector.end();
    typename std::vector<T>::const_iterator it = std::lower_bound(m_vector.begin(), m_vector.end(), a_item);
    size_t count = 0;
    while(it != end && *it == a_item)
    {
        ++count;
        ++it;
    }
    return count;
}

template<typename T>
T SortedVector<T>::front() const
{
    return m_vector.front();
}

template<typename T>
T SortedVector<T>::back() const
{
    return m_vector.back();
}

template<typename T>
std::ostream& SortedVector<T>::print(std::ostream& a_ostream)const
{
    size_t size = m_vector.size();
    a_ostream << "{";
    for(size_t i = 0; i < size; i++)
    {
        a_ostream << m_vector[i] << ", ";
    }
    a_ostream << "}";
    return a_ostream;
}

template<typename T>
size_t SortedVector<T>::size()const
{
    return m_vector.size();
}

template<typename T>
void SortedVector<T>::fill(T a_item, size_t a_times)
{
    typename std::vector<T>::iterator it = std::lower_bound(m_vector.begin(), m_vector.end(), a_item);
    m_vector.insert(it, a_times, a_item);
}


} //cpp namespace