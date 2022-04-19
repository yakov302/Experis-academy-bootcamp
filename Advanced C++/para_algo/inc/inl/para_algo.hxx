#ifndef PARA_ALGO_HXX
#define PARA_ALGO_HXX

#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include "thread.hpp"

namespace cpp
{

namespace details_impl
{

template <typename T>
Arguments<T>::Arguments(std::vector<T>& a_vec, size_t a_start, size_t a_end)
: m_vec(a_vec)
, m_start(a_start)
, m_end(a_end)
{

}

template <typename T>
void* sortPart (void* a_arg)
{
    assert(a_arg);
    Arguments<T>* details = static_cast< Arguments<T>*>(a_arg);
    typename std::vector<T>::iterator start = details->m_vec.begin() + details->m_start;
    typename std::vector<T>::iterator end = details->m_vec.begin() + details->m_end;
    std::sort(start, end);
    void* r = 0;
    return  r;
}

template <typename T>
void* sumPart (void* a_arg)
{
    assert(a_arg);
    Arguments<T>* details = static_cast< Arguments<T>*>(a_arg);
    std::vector<T> vec = details->m_vec;
    T sum = T();
    for(size_t i = details->m_start; i < details->m_end; i++)
    {
       sum += vec[i];
    }
    delete details;
    T* p = new T(sum);
    return static_cast<void*>(p);
}

template <typename T>
void createThreads(std::vector<T>& a_vec, std::vector<pthread_t>& a_threadsId, size_t a_numOfThreads)
{
    size_t const delta = a_vec.size()/a_numOfThreads;

    size_t i = 0;
    for(i = 0; i < a_numOfThreads - 1; i++)
    {
        details_impl::Arguments<T>* arg = new details_impl::Arguments<T>(a_vec, delta*i ,delta*i + delta);
        int result = ::pthread_create(&a_threadsId[i], 0, details_impl::sumPart<T>, static_cast<void*>(arg));
        assert(!result);
    }

    details_impl::Arguments<T>* arg = new details_impl::Arguments<T>(a_vec, delta*i ,a_vec.size());
    int result = ::pthread_create(&a_threadsId[i], 0, details_impl::sumPart<T>, static_cast<void*>(arg));
    assert(!result);
}

void JoinThreads(std::vector<pthread_t>& a_threadsId, std::vector<void*>& a_sums, size_t a_numOfThreads)
{
    for(size_t i = 0; i < a_numOfThreads; i++)
    {
        void* r = 0;
        int result = ::pthread_join(a_threadsId[i], &r);
        assert(!result);
        a_sums[i] = r;
    }
}

long int CalculateSums( std::vector<void*> a_sums, size_t a_numOfThreads)
{
    long int sum = 0;
    for(size_t i = 0; i < a_numOfThreads; i++)
    {
        sum += *static_cast<long int*>(a_sums[i]);
        delete static_cast<long int*>(a_sums[i]);
    }
    return sum;
}


} // details_impl namespace

template <typename T>
T sum(std::vector<T>& a_vec, size_t a_numOfThreads)
{
    if(a_numOfThreads < 2)
    {
        return std::accumulate(a_vec.begin(), a_vec.end(), 0);
    }

    std::vector<pthread_t> threadsId(a_numOfThreads);
    std::vector<void*> sums(a_numOfThreads);

    details_impl::createThreads(a_vec, threadsId, a_numOfThreads);
    details_impl::JoinThreads(threadsId, sums, a_numOfThreads);
    T sum = details_impl::CalculateSums(sums, a_numOfThreads);

    return sum;
}

template <typename T>
std::vector<T> sort(std::vector<T>& a_vec, size_t a_numOfThreads)
{
    size_t const part = a_vec.size()/a_numOfThreads;
    size_t start = 0;
    size_t end = part;
    for(size_t i = 0; i < a_numOfThreads; i++)
    {
        cpp::details_impl::Arguments<T>* arg = new cpp::details_impl::Arguments<T>(a_vec, start ,end);
        pthread_t thread;
        ::pthread_create(&thread, 0, details_impl::sortPart<T>, static_cast<void*>(arg));
        ::pthread_join(thread, 0);
        start = end;
        end = end + part;
    }
    return a_vec;
}


} //cpp namespace

#endif // PARA_ALGO_HXX