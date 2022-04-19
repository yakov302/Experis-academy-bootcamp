#ifndef LINIAR_ALGO_HXX
#define LINIAR_ALGO_HXX

#include <cassert>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include "utils.hpp"
#include "ball.hpp"

namespace cpp
{

namespace details_impl
{

template<typename T, typename Comparator>
static size_t findx(std::vector<T> const& a_vector, Comparator a_compar)
{
    size_t const size = a_vector.size();
    size_t index = 0;

    for(size_t i = 0; i < size; i++)
    {
        if(a_compar(a_vector[i], a_vector[index]))
        {
            index = i;
        }
    }

    return index;
}

template<typename T>
static void fromVectorToMap(std::vector<T> const& a_vector, std::map<T, size_t> &a_map)
{
    size_t size = a_vector.size();
    for(size_t i = 0; i < size; i++)
    {
        ++a_map[a_vector[i]];
    }
}

template<typename T>
static void firstAndNotSecondSet(std::set<T const*, comparByPointer<T> > &a_set, std::vector<T> const& a_first,  std::vector<T> const& a_second)
{
    using namespace std;

    size_t const firstSize = a_first.size();
    for(size_t i = 0; i < firstSize; i++)
    {
        a_set.insert(&a_first[i]);
    }

    size_t const secondSize = a_second.size();
    for(size_t i = 0; i < secondSize; i++)
    {
        a_set.erase(&a_second[i]);
    }
}

template<typename T>
static void setMin(size_t index, std::vector<T> const& a_vec, std::pair<size_t, size_t>& minMax)
{
    if( minMax.first > std::min(a_vec[index], a_vec[index+1]))
    {
        minMax.first = std::min(a_vec[index], a_vec[index+1]);
    }
}

template<typename T>
static void setMax(size_t index, std::vector<T> const& a_vec, std::pair<size_t, size_t>& minMax)
{
    if( minMax.second < std::max(a_vec[index], a_vec[index+1]))
    {
        minMax.second = std::max(a_vec[index], a_vec[index+1]);
    }
}


} // details_impl namespace

template<typename T>
void createChaos(std::vector<T>& a_vector, size_t a_size, size_t a_max)
{
    a_vector.reserve(a_size);
    for(size_t i = 0; i < a_size; i++)
    {
        T random = T(rand())/T(RAND_MAX) + rand()%a_max;
        a_vector.push_back(random);
    }
}

template<typename T>
double sum(std::vector<T> const& a_vector)
{
    size_t const size = a_vector.size();
    T sum = 0;
    for(size_t i = 0; i < size; i++)
    {
        sum += a_vector[i];
    }
    return sum;
}

template<typename T>
void oddsOut(std::vector<T>& a_vector)
{
    size_t const size = a_vector.size();
    size_t oddIndex = 0;

    for(size_t evenIndex = 0; evenIndex < size; evenIndex++)
    {
        if(a_vector[evenIndex]%2 == 0 && evenIndex >= oddIndex)
        {
            a_vector[oddIndex] = a_vector[evenIndex];
            ++oddIndex;
        }
    }

    for(size_t i = size - 1; i > 0 && i >= oddIndex; i--)
    {
        a_vector.pop_back();
    }
}

template<typename T>
std::pair<size_t, size_t> extremes(std::vector<T> const& a_vector)
{
    std::pair<size_t, size_t> minMax;
    if(a_vector.size() == 0)
    {
        minMax.first = a_vector.size();
        minMax.second = a_vector.size();
        return minMax;
    }

    minMax.first = details_impl::findx(a_vector, NaturalLess<T>());
    minMax.second = details_impl::findx(a_vector, NaturalGreterThan<T>());
    return minMax;
}

template<typename T>
std::pair<size_t, size_t> extremes2(std::vector<T> const& a_vector)
{
    size_t j = 0;
    std::pair<size_t, size_t> minMax;

    if(a_vector.size() == 0)
    {
        minMax.first = a_vector.size();
        minMax.second = a_vector.size();
        return minMax;
    }

    else if(a_vector.size() % 2 == 0)
    {
        minMax.first = std::min(a_vector[0], a_vector[1]);
        minMax.second = std::max(a_vector[0], a_vector[1]);
       j = 2;
    }

    else
    {
        minMax.first = minMax.second = a_vector[0];
        j = 1;
    }
    
    for( size_t i = j; i < a_vector.size(); i = i+2)
    {
        details_impl::setMin(i,a_vector, minMax);
        details_impl::setMax(i,a_vector, minMax);
    }
    return minMax;
}

template<typename T>
size_t CommontStrange(std::vector<T> const& a_first, std::vector<T> const& a_second,  std::vector<T> const& a_third)
{
    using namespace std;

    set<T const*, comparByPointer<T> > secondAndNotThird;
    details_impl::firstAndNotSecondSet(secondAndNotThird, a_second, a_third);

    size_t count = 0;
    size_t size = a_first.size();
    for(size_t i = 0; i < size; i++)
    {
       count += secondAndNotThird.count(&a_first[i]);
    }
    
    return count;
}

template<typename T>
size_t firstDuplicate(std::vector<T> const& a_vector)
{
    using std::map;
    map<const T*, size_t, comparByPointer<T> > mapT;
    size_t size = a_vector.size();
    size_t duplicate = a_vector.size() + 1;

    for(size_t i = 0; i < size; i++)
    {
        const T* element = &a_vector[i];
        if(mapT[element] == 0)
        {
            mapT[element] = i + 1;
        }
        else
        {
            if(i < duplicate)
            {
                duplicate = mapT[element];
            }
        }
    }
    return duplicate - 1;
}

template<typename T>
size_t findFirstUnique(std::vector<T> const& a_vector)
{
    using std::map;
    map<const T*, size_t, comparByPointer<T> > mapT;

    size_t size = a_vector.size();
    for(size_t i = 0; i < size; ++i)
    {
        ++mapT[&a_vector[i]];
    }

    for(size_t i = 0; i < size; ++i)
    {
        if(mapT[&a_vector[i]] == 1)
        {
            return i;
        }
    }

    return size;
}


} //cpp namespace

#endif // LINIAR_ALGO_HXX
