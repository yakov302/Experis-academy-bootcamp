#include <iostream>
#include <cassert>
#include <cstdio>

namespace cpp
{

template<typename T>
SortedListIterator<T>::SortedListIterator(typename std::list<T>::const_iterator a_it)
 :m_it(a_it) 
 {
     
 }

template<typename T>
void SortedListIterator<T>::operator++()
 {
    ++m_it;
 }

template<typename T>
void SortedListIterator<T>::operator++(int) 
{
    operator++(); 
}

template<typename T>
T SortedListIterator<T>::operator*() const 
{
    return *m_it;
}

template<typename T>
SortedList<T>::SortedList()
: SortedContainer<T>()
, m_list()
{
    
}

template<typename T>
SortedList<T>::~SortedList(){}

template<typename T>
void SortedList<T>::insert(value_type a_item)
{
    Itr it = m_list.begin(); 
    Itr end = m_list.end();
    while(it != end)
    {
        if(a_item < *it)
        {
            m_list.insert(it , a_item);
            return;
        }
        ++it;
    }
    m_list.push_back(a_item);
}

template<typename T>
size_t SortedList<T>::remove(value_type a_item)
{
    Itr it = m_list.begin(); 
    Itr end = m_list.end();
    size_t count = 0;
    while(it != end)
    {
        if(a_item == *it)
        {
            m_list.erase(it++);
            if(it != end--)
            {
                --it;  
            }
            count += 1;
        }
        ++it;
    }
    return count;
}

template<typename T>
size_t SortedList<T>::contains(value_type a_item)const
{
    ConstItr it = m_list.begin(); 
    ConstItr end = m_list.end();
    size_t count = 0;
    while(it != end)
    {
        if(a_item == *it)
        {
            count += 1;
        }
        ++it;
    }
    return count;
}

template<typename T>
typename SortedList<T>::value_type SortedList<T>::front() const
{
    return m_list.front();
}

template<typename T>
typename SortedList<T>::value_type SortedList<T>::back() const
{
    return m_list.back();
}

template<typename T>
std::ostream& SortedList<T>::print(std::ostream& a_ostream)const
{
    return printContainer(m_list, a_ostream);
}

template<typename T>
size_t SortedList<T>::size()const
{
    return m_list.size();
}

template<typename T>
typename SortedList<T>::value_type SortedList<T>::median()const
{
    return containerMedian(m_list);
}

template<typename T>
ContainerIterator<T>* SortedList<T>::begin()const
{
    return new SortedListIterator<T>(m_list.begin());
}

template<typename T>
ContainerIterator<T>* SortedList<T>::end()const 
{
   return new SortedListIterator<T>(m_list.end());
}


} //cpp namespace