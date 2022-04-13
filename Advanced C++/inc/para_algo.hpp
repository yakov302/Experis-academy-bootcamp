#ifndef PARA_ALGO_HPP
#define PARA_ALGO_HPP

#include <iostream>
#include <cassert>

namespace cpp
{

namespace details_impl
{

template <typename T>
struct Arguments
{
    Arguments(std::vector<T>& a_vec, size_t a_start, size_t a_end);
    std::vector<T>& m_vec;
    size_t m_start;
    size_t m_end;
};


} // details_impl namespace

template <typename T>
T sum(std::vector<T>& a_vec, size_t a_numOfThreads = 1);

template <typename T>
std::vector<T> sort(std::vector<T>& a_vec, size_t a_numOfThreads = 1);

} //cpp namespace

#include "./inl/para_algo.hxx"

#endif  // PARA_ALGO_HPP