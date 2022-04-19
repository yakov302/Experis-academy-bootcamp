#include "mu_test.h"
#include <vector>
#include <list>
#include "sorted_unique_vector.hpp"
#include "sorted_unique_list.hpp"
#include "sorted_vector.hpp"
#include "sorted_list.hpp"
#include "sorted_container.hpp"
#include "ball.hpp"
#include "utils.hpp"


BEGIN_TEST(vector_test)

	using namespace cpp;
	const int N = 20;
	SortedVector<int> vac(N);
	ASSERT_EQUAL(vac.empty(), true);

	vac.fill(5,5);
	
	//bool r = isUniform(vac);
	ASSERT_EQUAL(isUniform(vac), true);
	ASSERT_EQUAL(isSorted(vac), true);
	ASSERT_EQUAL(vac.median(), 5);

	for(int i = N; i > 0-N; i--)
	{
		vac.insert(i);
	}
	ASSERT_EQUAL(isUniform(vac), false);
	ASSERT_EQUAL(isSorted(vac), true);
	ASSERT_EQUAL(vac.empty(), false);


	//TRACER  << vac;

	ASSERT_EQUAL(vac.median(), 3);

	ASSERT_EQUAL(vac.size(), N*2 + 5);
	vac.remove(N/2);
	ASSERT_EQUAL(vac.size(), N*2 + 4);

	ASSERT_EQUAL(vac.contains(N/2), false);
	ASSERT_EQUAL(vac.contains(N/2 + 1), 1);
	vac.insert(N/2 + 1);
	ASSERT_EQUAL(vac.contains(N/2 + 1), 2);

	ASSERT_EQUAL(vac.front(), -19);
	ASSERT_EQUAL(vac.back(), N);

END_TEST


BEGIN_TEST(unique_vector_test)

	using namespace cpp;
	const int N = 20;
	SortedUniqueVector<int> vac(N);
	ASSERT_EQUAL(vac.empty(), true);
	vac.fill(5,5);
	ASSERT_EQUAL(vac.size(), 1);
	ASSERT_EQUAL(isUniform(vac), true);
	ASSERT_EQUAL(isSorted(vac), true);

	for(int i = 0; i < N; i++)
	{
		vac.insert(i);
		vac.insert(i);
	}
	ASSERT_EQUAL(isUniform(vac), false);
	ASSERT_EQUAL(isSorted(vac), true);
	ASSERT_EQUAL(vac.median(), 10);
	ASSERT_EQUAL(vac.empty(), false);

	//TRACER << vac;

	ASSERT_EQUAL(vac.size(), N);
	vac.remove(N/2);
	ASSERT_EQUAL(vac.size(), N - 1);

	ASSERT_EQUAL(vac.contains(N/2), false);
	ASSERT_EQUAL(vac.contains(N/2 + 1), 1);
	vac.insert(N/2 + 1);
	ASSERT_EQUAL(vac.contains(N/2 + 1), 1);

	ASSERT_EQUAL(vac.front(), 0);
	ASSERT_EQUAL(vac.back(), 19);

END_TEST


BEGIN_TEST(list_test)

	using namespace cpp;
	const int N = 100;
	SortedList<int> list;
	ASSERT_EQUAL(list.empty(), true);
	list.fill(5,5);
	ASSERT_EQUAL(list.size(), 5);
	ASSERT_EQUAL(list.median(), 5);
	ASSERT_EQUAL(isUniform(list), true);
	ASSERT_EQUAL(isSorted(list), true);

	for(int i = 0; i < N; i+=2)
	{
		list.insert(i);
	}

	for(int i = 1; i < N; i+=2)
	{
		list.insert(i);
	}
	ASSERT_EQUAL(list.median(), 47);
	ASSERT_EQUAL(isUniform(list), false);
	ASSERT_EQUAL(isSorted(list), true);

	//TRACER <<list;

	ASSERT_EQUAL(list.size(), N + 5);
	list.remove(N/2);
	ASSERT_EQUAL(list.size(), N + 4);

	ASSERT_EQUAL(list.contains(N/2), false);
	ASSERT_EQUAL(list.contains(N/2 + 1), 1);
	list.insert(N/2 + 1);
	ASSERT_EQUAL(list.contains(N/2 + 1), 2);

	ASSERT_EQUAL(list.front(), 0);
	ASSERT_EQUAL(list.back(), N-1);

END_TEST


BEGIN_TEST(unique_list_test)

	using namespace cpp;
	const int N = 100;
	SortedUniqueList<int> list;
	ASSERT_EQUAL(list.empty(), true);
	list.fill(5,5);
	ASSERT_EQUAL(list.size(), 1);
	ASSERT_EQUAL(isUniform(list), true);
	ASSERT_EQUAL(isSorted(list), true);

	for(int i = 0; i < N; i++)
	{
		list.insert(i);
		list.insert(i);
	}

	ASSERT_EQUAL(isUniform(list), false);
	ASSERT_EQUAL(isSorted(list), true);

	//TRACER <<list;

	ASSERT_EQUAL(list.size(), N);
	list.remove(N/2);
	ASSERT_EQUAL(list.size(), N-1);

	ASSERT_EQUAL(list.contains(N/2), false);
	ASSERT_EQUAL(list.contains(N/2 + 1), 1);
	list.insert(N/2 + 1);
	ASSERT_EQUAL(list.contains(N/2 + 1), 1);

	ASSERT_EQUAL(list.front(), 0);
	ASSERT_EQUAL(list.back(), N-1);

END_TEST


BEGIN_TEST(container_vector_test)

	using namespace cpp;
	const int N = 100;

	SortedVector<int> vac(N);
	SortedContainer<int>& sc = vac;

	for(int i = 0; i < N; i+=2)
	{
		sc.insert(i);
	}

	for(int i = 1; i < N; i+=2)
	{
		sc.insert(i);
	}

	//TRACER << sc;

	ASSERT_EQUAL(vac.size(), N);
	sc.remove(N/2);
	ASSERT_EQUAL(vac.size(), N-1);

	ASSERT_EQUAL(sc.contains(N/2), false);
	ASSERT_EQUAL(sc.contains(N/2 + 1), true);

	ASSERT_EQUAL(sc.front(), 0);
	ASSERT_EQUAL(sc.back(), N-1);

END_TEST

BEGIN_TEST(container_list_test)

	using namespace cpp;
	const int N = 100;

	SortedVector<int> list;
	SortedContainer<int>& sc = list;

	for(int i = 0; i < N; i+=2)
	{
		sc.insert(i);
	}

	for(int i = 1; i < N; i+=2)
	{
		sc.insert(i);
	}

	//sc.print(std::cout);

	ASSERT_EQUAL(list.size(), N);
	sc.remove(N/2);
	ASSERT_EQUAL(list.size(), N-1);

	ASSERT_EQUAL(sc.contains(N/2), false);
	ASSERT_EQUAL(sc.contains(N/2 + 1), true);

	ASSERT_EQUAL(sc.front(), 0);
	ASSERT_EQUAL(sc.back(), N-1);

END_TEST


BEGIN_TEST(removing_list_vector_tests)

	using namespace cpp;
	SortedList<int> vec;
	vec.insert(3);vec.insert(6);vec.insert(8);

	for(int i = 0; i < 8; ++i)
	{
		vec.insert(i);
	}

	vec.remove(0); 
	vec.remove(1); 
	vec.remove(2); 
	vec.remove(3); 
	vec.remove(4); 
	vec.remove(5); 
	vec.remove(6); 
	vec.remove(7);
	vec.remove(8);  

	//TRACER << vec;
	ASSERT_EQUAL(vec.empty(), true);

END_TEST


BEGIN_TEST(back_front_list_vector_tests)

	using namespace cpp;
	SortedVector<int> vec(5);
	SortedList<int> list;

	vec.insert(100);vec.insert(10);vec.insert(0);vec.insert(-6);vec.insert(30);
	list.insert(100);list.insert(10);list.insert(0);list.insert(-6);list.insert(30);

	ASSERT_EQUAL(vec.front(), -6);
	ASSERT_EQUAL(list.front(), -6);
	ASSERT_EQUAL(vec.back(), 100);
	ASSERT_EQUAL(list.back(), 100);

END_TEST


BEGIN_TEST(ball_test)

	using namespace cpp;
	const int N = 10;

	SortedVector<Ball> vec;
	SortedList<Ball> list;
	ASSERT_EQUAL(vec.empty(), true);
	ASSERT_EQUAL(list.empty(), true);

	for(int i = 1; i < N; i++)
	{
		vec.insert(Ball('r', i));
	}

	for(int i = 1; i < N; i++)
	{
		list.insert(Ball('r', i));
	}

	ASSERT_EQUAL(vec.median(), Ball('r',N/2));
	ASSERT_EQUAL(list.median(), Ball('r',N/2));

	//TRACER << vec;
	//TRACER << list;

	ASSERT_EQUAL(isSorted(vec), true);
	ASSERT_EQUAL(isSorted(list), true);
	ASSERT_EQUAL(isUniform(vec), false);
	ASSERT_EQUAL(isUniform(list), false);

	ASSERT_EQUAL(list.size(), N -1);
	ASSERT_EQUAL(vec.size(), N-1);
	list.remove(Ball('r', 5));
	vec.remove(Ball('r', 5));
	ASSERT_EQUAL(list.size(), N -2);
	ASSERT_EQUAL(vec.size(), N-2);

	ASSERT_EQUAL(list.contains(Ball('r', 5)), false);
	ASSERT_EQUAL(vec.contains(Ball('r', 5)), false);
	ASSERT_EQUAL(list.contains(Ball('r', 4)), true);
	ASSERT_EQUAL(vec.contains(Ball('r', 4)), true);

	ASSERT_EQUAL(list.front(), Ball('r', 1));
	ASSERT_EQUAL(list.back(), Ball('r', 9));
	ASSERT_EQUAL(vec.front(), Ball('r', 1));
	ASSERT_EQUAL(vec.back(), Ball('r', 9));

END_TEST


BEGIN_SUITE(TEST)

	 TEST(vector_test)
	TEST(unique_vector_test)
	TEST(list_test)
	TEST(unique_list_test)
	TEST(container_vector_test)
	TEST(container_list_test)
	TEST(removing_list_vector_tests)
	TEST(back_front_list_vector_tests)
	TEST(ball_test)

END_SUITE
