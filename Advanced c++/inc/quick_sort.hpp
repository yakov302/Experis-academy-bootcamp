#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "utils.hpp"

#include <cstddef>

namespace cpp
{

template <typename T, typename LessComparator>
void quickSort(T* a_array, size_t a_length, LessComparator less = NaturalLess<T>());


} //cpp namespace

#include "./inl/quick_sort.hxx"

#endif /*#ifndefQUICK_SORT_H122*/
