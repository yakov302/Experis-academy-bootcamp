#include "mu_test.h"
#include <vector>
#include <numeric>
#include"para_algo.hpp"

BEGIN_TEST(vec_sum_1000_1_thread)

	using namespace cpp;
	size_t const N = 1000;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	int r = sum(v, 1);
	int e = std::accumulate(v.begin(), v.end(), 0);
	ASSERT_EQUAL(r, e);

END_TEST

BEGIN_TEST(vec_sum_1000_2_threads)

	using namespace cpp;
	size_t const N = 1003;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	int r = sum(v, 2);
	int e = std::accumulate(v.begin(), v.end(), 0);
	ASSERT_EQUAL(r, e);;

END_TEST

BEGIN_TEST(vec_sum_1000_4_threads)

	using namespace cpp;
	size_t const N = 1005;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	int r = sum(v, 4);
	int e = std::accumulate(v.begin(), v.end(), 0);
	ASSERT_EQUAL(r, e);

END_TEST

BEGIN_TEST(vec_sum_1000_16_threads)

	using namespace cpp;
	size_t const N = 1000;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	int r = sum(v, 16);
	int e = std::accumulate(v.begin(), v.end(), 0);
	ASSERT_EQUAL(r, e);

END_TEST

BEGIN_TEST(vec_sum_1m_1_thread)

	using namespace cpp;
	size_t const N = 1000000;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	int r = sum(v, 1);
	int e = std::accumulate(v.begin(), v.end(), 0);
	ASSERT_EQUAL(r, e);

END_TEST

BEGIN_TEST(vec_sum_1m_2_threads)

	using namespace cpp;
	size_t const N = 1000000;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	int r = sum(v, 2);
	int e = std::accumulate(v.begin(), v.end(), 0);
	ASSERT_EQUAL(r, e);

END_TEST

BEGIN_TEST(vec_sum_1m_4_threads)

	using namespace cpp;
	size_t const N = 1000000;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	int r = sum(v, 4);
	int e = std::accumulate(v.begin(), v.end(), 0);
	ASSERT_EQUAL(r, e);

END_TEST

BEGIN_TEST(vec_sum_1m_16_threads)

	using namespace cpp;
	size_t const N = 1000000;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	int r = sum(v, 16);
	int e = std::accumulate(v.begin(), v.end(), 0);
	ASSERT_EQUAL(r, e);

END_TEST

template <typename T>
bool isSort(std::vector<T>& a_vec)
{
	size_t const size = a_vec.size();
	for(size_t i = 1; i < size - 1; i++)
	{
		if(a_vec[i] < a_vec[i-1])
		{
			return false;
		}
	}
	return true;
}

BEGIN_TEST(vec_sort_1000_1_thread)

	using namespace cpp;
	size_t const N = 1000;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(rand()%N);
	}

	ASSERT_EQUAL(isSort(v), false);
	sort(v, 1);
	ASSERT_EQUAL(isSort(v), true);

END_TEST

BEGIN_TEST(vec_sort_1M_1_thread)

	using namespace cpp;
	size_t const N = 1000000;
	std::vector<long int> v;
	v.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		v.push_back(rand()%N);
	}

	ASSERT_EQUAL(isSort(v), false);
	sort(v, 1);
	ASSERT_EQUAL(isSort(v), true);

END_TEST

BEGIN_SUITE(TEST)

	TEST(vec_sum_1000_1_thread)
	TEST(vec_sum_1000_2_threads)
	TEST(vec_sum_1000_4_threads)
	TEST(vec_sum_1000_16_threads)
	TEST(vec_sum_1m_1_thread)
	TEST(vec_sum_1m_2_threads)
	TEST(vec_sum_1m_4_threads)
	TEST(vec_sum_1m_16_threads)
	TEST(vec_sort_1000_1_thread)
	TEST(vec_sort_1M_1_thread)

END_SUITE
