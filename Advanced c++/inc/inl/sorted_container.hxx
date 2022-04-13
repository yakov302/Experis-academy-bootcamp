#include <iostream>
#include <cassert>

namespace cpp
{
    
template<typename T>
bool ContainerIterator<T>::operator==(const ContainerIterator<T>& a_rhs)const
{
    return **this == *a_rhs;
}

template<typename T>
bool ContainerIterator<T>::operator!=(const ContainerIterator<T>& a_rhs)const
{
    return **this != *a_rhs;
}

template<typename T>
ContainerIterator<T>::ContainerIterator(){}

template<typename T>
ContainerIterator<T>::~ContainerIterator(){}

template<typename T>
SortedContainer<T>::SortedContainer(){}

template<typename T>
SortedContainer<T>::~SortedContainer(){}

template<typename T>
size_t SortedContainer<T>::fill(value_type a_value, size_t a_times)
{
    size_t count = 0;
    while(a_times-- > 0)
    {
        insert(a_value);
        ++count;
    }
    return count;
}

template<typename T>
bool SortedContainer<T>::empty()const
{
    return size() == 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& a_ostream, SortedContainer<T> const& a_container)
{
    return a_container.print(a_ostream);
}

template <typename T>
std::ostream& printContainer(T const& a_container, std::ostream& a_ostream)
{
    typename T::const_iterator it = a_container.begin(); 
    typename T::const_iterator end = a_container.end();  
   
    a_ostream << '{';
    if(it != end)
    {
        a_ostream << *it++;  
    }
    while(it != end)
    {
        a_ostream << ", " << *it++; 
    }
    a_ostream << "}\n"; 

    return a_ostream;
}

template <typename T>
typename T::value_type containerMedian(T const& a_container)
{
    typename T::const_iterator it = a_container.begin();
    size_t med = a_container.size()/2;
    for(size_t i = 0; i < med; ++i)
    {
        ++it;
    }
    return *it;
} 

template <typename T>
bool isSorted(SortedContainer<T> const& a_container)
{
    ContainerIterator<T>* prev = a_container.begin();
    ContainerIterator<T>* it = a_container.begin();
    ContainerIterator<T>* end = a_container.end();

     ++(*it);
    while(*it != *end)
    {
        if(**it < **prev)
        {
            delete prev;
            delete it;
            delete end;
            return false;
        }
        ++(*it);
        ++(*prev);
    } 
    delete prev;
    delete it;
    delete end;
    return true;
}

template <typename T>
bool isUniform(SortedContainer<T> const& a_container)
{
    ContainerIterator<T>* prev = a_container.begin();
    ContainerIterator<T>* it = a_container.begin();
    ContainerIterator<T>* end = a_container.end();

    ++(*it);
    while(*it != *end)
    {
        if(!(**prev == **it))
        {
            delete prev;
            delete it;
            delete end;
           return false;  
        }
        ++(*it);
        ++(*prev);
    }
    delete prev;
    delete it;
    delete end;
    return true;
} 


} //cpp namespace