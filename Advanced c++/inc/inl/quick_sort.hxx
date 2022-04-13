#ifndef QUICK_SORT_HXX
#define QUICK_SORT_HXX

#include <cassert>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "utils.hpp"

namespace cpp
{

namespace details_impl
{

const size_t THRESHOLD = 10;

template <typename T, typename LessComparator>
static void insertionSort(T* a_array, size_t a_start, size_t a_last, LessComparator less)
{
	size_t checkIndex = a_start + 1;
	T checkItem, runningItem;
	
	for(size_t i = a_start; i < a_last; i++)
	{
		checkItem = a_array[checkIndex];
		for(size_t j = checkIndex; j > 0; j--)
		{
			runningItem = a_array[j - 1];
			if(less(checkItem, runningItem))
			{
				a_array[j - 1] = checkItem;
				a_array[j] = runningItem;
       		}
			else
			{
				break;
			}	
		}
		checkIndex++;		
	}
}

template <typename T, typename LessComparator>
static void findBiggerOnLeft(T* a_array, T& a_pivot, size_t& a_start, size_t& a_last, LessComparator less)
{
	while(a_start <= a_last && less(a_array[a_start], a_pivot))
	{
		a_start++;
	}
}

template <typename T, typename LessComparator>
static void findSmallerOnRight(T* a_array, T& a_pivot, size_t& a_start, size_t& a_last, LessComparator less)
{
	while(!(a_last <= a_start) && !(less(a_array[a_last], a_pivot))) // instead of ">"
	{
		a_last--;
	}
}

template <typename T, typename LessComparator>
static size_t partition(T* a_array, size_t a_start, size_t a_last, T& a_pivot, LessComparator less)
{
	using std::swap;
    size_t start = a_start + 1;
    size_t last = a_last;

	while(start <= last)
	{
		findBiggerOnLeft( a_array,  a_pivot, start, a_last, less);	
		findSmallerOnRight(a_array, a_pivot, a_start, last, less);

		if(start <= last)
		{
			swap(a_array[start], a_array[last]);
		}	
	}
	
	swap(a_pivot,  a_array[last]);
	return last;
}

template <typename T>
T& selectPivot(T* a_array, size_t a_start, size_t a_last)
{
	return a_array[a_start];
}

template <typename T, typename LessComparator>
static void quickSortRec(T* a_array, size_t a_start, size_t a_last, LessComparator less)
{
	if(a_start >= a_last)
	{
		return;
	}
	
	T& pivot = selectPivot(a_array, a_start, a_last);
	size_t pivotIndex = partition(a_array, a_start, a_last, pivot, less);

	if((pivotIndex -1) - a_start < THRESHOLD)
	{
		insertionSort(a_array, a_start, pivotIndex -1, less);
	}
	else if(pivotIndex >= 1)
	{
		quickSortRec(a_array, a_start, pivotIndex -1, less);
	}

	if(a_last - (pivotIndex + 1) < THRESHOLD)
	{
		insertionSort(a_array, pivotIndex + 1, a_last, less);
	}
	else
	{
		quickSortRec(a_array, pivotIndex + 1, a_last, less);
	}
}


} //details_impl namespace

template <typename T, typename LessComparator>
inline void quickSort(T* a_array, size_t a_length, LessComparator less)
{
	if(!a_array || a_length < 2)
	{
		return;
	}

	details_impl::quickSortRec(a_array, 0, a_length -1, less);	
}


} //cpp namespace

#endif // QUICK_SORT_HXX
