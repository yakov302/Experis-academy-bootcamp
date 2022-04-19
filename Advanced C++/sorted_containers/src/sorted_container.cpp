#include <iostream>
#include <cassert>
#include"sorted_container.hpp"

namespace cpp
{

template<typename T>
SortedContainer<T>::SortedContainer(){}

template<typename T>
SortedContainer<T>::~SortedContainer(){}

template<typename T>
void SortedContainer<T>::fill(T a_value, size_t a_times)
{
    while(a_times-- > 0)
    {
        insert(a_value);
    }
}

template<typename T>
void fill(SortedContainer<T>& container, int a_start, int a_end, int a_delta = 1)
{
    if(a_end > a_start)
    {
        for(int i = a_start; i < a_end; i+= a_delta)
        {
            container.insert(i);
        }    
    }
    else
    {
        for(int i = a_end; i > a_start; i-= a_delta)
        {
            container.insert(i);
        }  
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& a_ostream, SortedContainer<T> const& a_container)
{
    return a_container.print(a_ostream);
}


} //cpp namespace