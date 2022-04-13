#include "mu_test.h"
#include "linear_algo.hpp"
#include "utils.hpp"
#include "ball.hpp"
#include <vector>
#include <map>
#include <fstream>


BEGIN_TEST(createChaos_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 20000;
	size_t const MAX = 1000;
    vector<double> vec;

	ASSERT_EQUAL(vec.capacity(), 0);
	ASSERT_EQUAL(vec.size(), 0);

	createChaos(vec, N, MAX);

	ASSERT_EQUAL(vec.capacity(),N);
	ASSERT_EQUAL(vec.size(), N);

	for(size_t i = 0; i < N; i++)
	{
		//std::cout <<"vec[" << i <<"] " << vec[i] << "\n";
	}

END_TEST


BEGIN_TEST(sum_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 10;
    vector<double> vec;
    vec.reserve(N);

	vec.push_back(1.5);
	vec.push_back(1.3);
	vec.push_back(1.25);
	vec.push_back(7.8);
	vec.push_back(8.4);
	vec.push_back(9.25);
	vec.push_back(6.53);
	vec.push_back(0.12);
	vec.push_back(8.18);
	vec.push_back(236.587);

	ASSERT_EQUAL(sum(vec), 280.917);

END_TEST


BEGIN_TEST(oddsOut_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 1000;
    vector<int> vec;
    vec.reserve(N);

	for(size_t i = 1; i < N + 1; i++)
	{
		vec.push_back(i);
	}

	ASSERT_EQUAL(vec.size(), N);
	oddsOut(vec);
	ASSERT_EQUAL(vec.size(), N/2);

	for(size_t i = 0; i < N/2; i++)
	{
		//std::cout <<"vec[" << i <<"] " << vec[i] << "\n";
	}

END_TEST


BEGIN_TEST(extremes_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 100;
	size_t const MAX = 10000;

	int min = -15;
	int max = MAX + 10;

    vector<int> vec;
	createChaos(vec, N - 2, MAX);
	vec.push_back(min);
	vec.push_back(max);

	std::pair<size_t, size_t> result;
	result =  extremes(vec);

	for(size_t i = 0; i < N; i++)
	{
		//std::cout <<"vec[" << i <<"] " << vec[i] << "\n";
	}

	// std::cout << "min: " << vec[result.first] << "\n";
	// std::cout << "max: " << vec[result.second] << "\n";

	ASSERT_EQUAL(vec[result.first], min);
	ASSERT_EQUAL(vec[result.second], max);

END_TEST


BEGIN_TEST(extremes2_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 100;
	size_t const MAX = 10000;

	size_t min = 1;
	size_t max = MAX + 10;

    vector<size_t> vec;
	createChaos(vec, N - 2, MAX);
	vec.push_back(min);
	vec.push_back(max);

	std::pair<size_t, size_t> result;
	result =  extremes2(vec);

	for(size_t i = 0; i < N; i++)
	{
		//std::cout <<"vec[" << i <<"] " << vec[i] << "\n";
	}

	// std::cout << "min: " << vec[result.first] << "\n";
	// std::cout << "max: " << vec[result.second] << "\n";

	ASSERT_EQUAL(result.first, min);
	ASSERT_EQUAL(result.second, max);

END_TEST


BEGIN_TEST(firstDuplicate_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 10000;
    vector<Ball> vec;
    vec.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		vec.push_back(Ball('w', i));
		if(i == N/2)
		{
			vec.push_back(Ball('w', i - 30));
			vec.push_back(Ball('w', i - 20));
			vec.push_back(Ball('w', i - 10));
			vec.push_back(Ball('w', i + 30));
			vec.push_back(Ball('w', i + 20));
			vec.push_back(Ball('w', i + 10));
			vec.push_back(Ball('w', i));
		}
	}

	size_t result = firstDuplicate<Ball>(vec);
	ASSERT_EQUAL(result,N/2 - 30);

END_TEST


BEGIN_TEST(CommontStrange_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 1000;
    vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;
    vec1.reserve(N);
	vec2.reserve(N);
	vec3.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		vec1.push_back(i);
		vec2.push_back(i);
		if(i > N/2)
		{
			vec3.push_back(i);
		}
	}

	size_t result = CommontStrange(vec1, vec2, vec3);
	ASSERT_EQUAL(result,N/2 + 1);

END_TEST


BEGIN_TEST(findFirstUnique_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 10000;
    vector<int> vec;
    vec.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		vec.push_back(i);
	}
	for(size_t i = N; i >= 0 && i < N + 1; i--)
	{
		if(i != N - N/10)
		{
			vec.push_back(i);;
		}
	}

	size_t result = findFirstUnique(vec);
	ASSERT_EQUAL(result, N - N/10);

END_TEST


BEGIN_SUITE(TEST)

	TEST(createChaos_test)
	TEST(sum_test)
	TEST(oddsOut_test)
	TEST(extremes_test)
	TEST(extremes2_test)
	TEST(firstDuplicate_test)
	TEST(CommontStrange_test)
	TEST(findFirstUnique_test)

END_SUITE
