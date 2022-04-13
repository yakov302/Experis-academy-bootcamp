#include <iostream>
#include <cassert>
#include "sorted_list.hpp"
#include <cstdio>

namespace cpp
{

template<typename T>
SortedList<T>::SortedList()
: SortedContainer<T>()
, m_list()
{}

template<typename T>
SortedList<T>::~SortedList(){}

template<typename T>
void SortedList<T>::insert(T a_item)
{
    typename std::list<T>::iterator it = m_list.begin(); 
    typename std::list<T>::iterator end = m_list.end();
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
size_t SortedList<T>::remove(T a_item)
{
    typename std::list<T>::iterator it = m_list.begin(); 
    typename std::list<T>::iterator end = m_list.end();
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
size_t SortedList<T>::contains(T a_item)const
{
    typename std::list<T>::const_iterator it = m_list.begin(); 
    typename std::list<T>::const_iterator end = m_list.end();
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
T SortedList<T>::front() const
{
    return m_list.front();
}

template<typename T>
T SortedList<T>::back() const
{
    return m_list.back();
}

template<typename T>
std::ostream& SortedList<T>::print(std::ostream& a_ostream)const
{
    typename std::list<T>::const_iterator it = m_list.begin(); 
    typename std::list<T>::const_iterator end = m_list.end();
    a_ostream << "{";
    while(it != end)
    {
        a_ostream << *it << ", ";
        ++it;
    }
    a_ostream << "}";
    return a_ostream;
}

template<typename T>
size_t SortedList<T>::size()const
{
    return m_list.size();
}


} //cpp namespace