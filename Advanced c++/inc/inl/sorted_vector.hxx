#include <iostream>
#include <cassert>
#include <vector>
#include <cstdio>

namespace cpp
{

template<typename T>
SortedVectorIterator<T>::SortedVectorIterator(typename std::vector<T>::const_iterator a_it)
 :m_it(a_it) 
 {
     
 }

template<typename T>
void SortedVectorIterator<T>::operator++()
 {
    ++m_it;
 }

template<typename T>
void SortedVectorIterator<T>::operator++(int) 
{
    operator++(); 
}

template<typename T>
T SortedVectorIterator<T>::operator*() const 
{
    return *m_it;
}

template<typename T>
SortedVector<T>::SortedVector(size_t a_size)
: SortedContainer<T>()
, m_vector()
{
    m_vector.reserve(a_size);
}

template<typename T>
SortedVector<T>::~SortedVector()
{

}

template<typename T>
void SortedVector<T>::insert(value_type a_item)
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
size_t SortedVector<T>::remove(value_type a_item)
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
size_t SortedVector<T>::contains(value_type a_item)const
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
typename SortedVector<T>::value_type SortedVector<T>::front() const
{
    return m_vector.front();
}

template<typename T>
typename SortedVector<T>::value_type SortedVector<T>::back() const
{
    return m_vector.back();
}

template<typename T>
std::ostream& SortedVector<T>::print(std::ostream& a_ostream)const
{
    return printContainer(m_vector, a_ostream);
}

template<typename T>
size_t SortedVector<T>::size()const
{
    return m_vector.size();
}

template<typename T>
size_t SortedVector<T>::fill(value_type a_item, size_t a_times)
{
    Itr it = std::lower_bound(m_vector.begin(), m_vector.end(), a_item);
    m_vector.insert(it, a_times, a_item);
    return a_times;
}

template<typename T>
typename SortedVector<T>::value_type SortedVector<T>::median() const
{
    return containerMedian(m_vector);
}

template<typename T>
ContainerIterator<T>* SortedVector<T>::begin()const
{
    return new SortedVectorIterator<T>(m_vector.begin());
}

template<typename T>
ContainerIterator<T>* SortedVector<T>::end()const 
{
   return new SortedVectorIterator<T>(m_vector.end());
}


} //cpp namespace