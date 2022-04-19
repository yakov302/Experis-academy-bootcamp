#include "mu_test.h"
#include "quick_sort.hpp"
#include "ball.hpp"
#include "point.hpp"
#include "utils.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <algorithm>




BEGIN_TEST(int_sort_test)
	using namespace cpp;

	int array[] = {1, -9, -10, 4, 9, -6, 2, -8, 3, 8, 0, -1, 7, -4, 5, -5, -2, 6, -3, 10, -7};
	int expected[] = {-10, -9, - 8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	quickSort<int>(array, ARRAY_SIZE(array), NaturalLess<int>());
	for (int i = 0; i < int (ARRAY_SIZE(array)); i++)
	{
		ASSERT_EQUAL(array[i], expected[i]);
		//std::cout << "arr[" << i << "] :" << array[i] << "\n";
	}

END_TEST


int intComper (const void * first, const void * second)
{
	return (*(int*)first - *(int*)second);
}

int const N = 1000000;
BEGIN_TEST(int_large_sort_test)

	using namespace cpp;


	int* array = randomIntArray(N);
	int* copy = new int[N];

	arrCopy(copy, array, N);

	quickSort<int>(array, N, NaturalLess<int>());
	std::qsort(copy, N, sizeof(int), intComper);

	for (int i = 0; i < N; i++)
	{
		ASSERT_EQUAL(array[i], copy[i]);
		//std::cout << "arr[" << i << "] :" << array[i] << "\n";
		//std::cout << "cop[" << i << "] :" << copy[i] << "\n";
	}

	delete[] array;
	delete[] copy;

END_TEST


BEGIN_TEST(my_quickSort_time_test)

	using namespace cpp;



	int* array = randomIntArray(N);

	quickSort<int>(array, N, NaturalLess<int>());

	delete[] array;

	ASSERT_PASS();

END_TEST


BEGIN_TEST(qsort_sort_time_test)


	int* array = randomIntArray(N);

	std::qsort(array, N, sizeof(int), intComper);

	delete[] array;

	ASSERT_PASS();

END_TEST


BEGIN_TEST(char_sort_test)

	using namespace cpp;

	char array[] = "PAGacrNBbQHqZpsVWzgIRCftjMSOxYDoLyUuklheJnXiEdKvFmTwFh";
	char expected[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	quickSort<char>(array, 52, NaturalLess<char>());
	for (int i = 0; i < 52; i++)
	{
		ASSERT_EQUAL(array[i], expected[i]);
		//std::cout << "arr[" << i << "] :" << array[i] << "\n";
	}

END_TEST


BEGIN_TEST(ball_sort_test)

	using namespace cpp;

	Ball array[10];
	array[0].setRadius(4);
	array[1].setRadius(7);
	array[2].setRadius(3);
	array[3].setRadius(8);
	array[4].setRadius(5);
	array[5].setRadius(6);
	array[6].setRadius(2);
	array[7].setRadius(9);
	array[8].setRadius(1);
	array[9].setRadius(10);

	quickSort<Ball>(array, int(ARRAY_SIZE(array)), NaturalLess<Ball>());
	for (int i = 0; i < int(ARRAY_SIZE(array)); i++)
	{
		ASSERT_EQUAL(array[i].getRadius(), i + 1);
		//std::cout << "arr[" << i << "] :" << array[i].getRadius() << "\n";
	}

END_TEST


BEGIN_TEST(point_sort_test)

	using namespace cpp;

	Point<double> array[10];
	array[0].setPoint(4, 4);
	array[1].setPoint(1, 1);
	array[2].setPoint(10, 10);
	array[3].setPoint(7, 7);
	array[4].setPoint(6, 6);
	array[5].setPoint(9, 9);
	array[6].setPoint(3, 3);
	array[7].setPoint(2, 2);
	array[8].setPoint(5, 5);
	array[9].setPoint(8, 8);

	quickSort<Point<double> >(array, ARRAY_SIZE(array), NaturalLess<Point<double> >());
	for (int i = 0; i < int (ARRAY_SIZE(array)); i++)
	{
		ASSERT_EQUAL( array[i].getX(), i + 1);
		ASSERT_EQUAL( array[i].getY(), i + 1);
		//std::cout << "arr[" << i << "] :" << array[i].getX() << ", " << array[i].getY() << "\n";
	}

END_TEST


BEGIN_TEST(insertion_sort_test)

	using namespace cpp;

	int array[] = {1, -9, -10, 4, 9, -6, 2, -8, 3, 8, 0, -1, 7, -4, 5, -5, -2, 6, -3, 10, -7};
	int expected[] = {-10, -9, - 8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


	cpp::details_impl::insertionSort(array, 0, ARRAY_SIZE(array) - 1, NaturalLess<int>());
	for (size_t i = 0; i < ARRAY_SIZE(array); i++)
	{
		ASSERT_EQUAL(array[i], expected[i]);
		//std::cout << "arr[" << i << "] :" << array[i] << "\n";
	}

END_TEST


struct ComperByX
{
	bool operator()(cpp::Point<double> const& a, cpp::Point<double> const& b)const
	{
		if (a.getX() - b.getX() < 0)
		{
			return true;
		}
		return false;
	}
};

BEGIN_TEST(comperator_test)

	using namespace cpp;

	Point<double> array[10];
	array[0].setPoint(4, 4);
	array[1].setPoint(1, 1);
	array[2].setPoint(-2, 10);
	array[3].setPoint(-3, 7);
	array[4].setPoint(-1, 6);
	array[5].setPoint(-4, 9);
	array[6].setPoint(3, 3);
	array[7].setPoint(2, 2);
	array[8].setPoint(0, 5);
	array[9].setPoint(-5, 8);

	quickSort<Point<double> >(array, ARRAY_SIZE(array), ComperByX());
	for (int i = 0; i < int (ARRAY_SIZE(array)); i++)
	{
		ASSERT_EQUAL( array[i].getX(), i - 5);
		//std::cout << "arr[" << i << "] :" << array[i].getX() << ", " << array[i].getY() << "\n";
	}

END_TEST


BEGIN_SUITE(TEST)

	TEST(int_sort_test)
	TEST(int_large_sort_test)
	TEST(my_quickSort_time_test)
	TEST(qsort_sort_time_test)
	TEST(char_sort_test)
	TEST(ball_sort_test)
	TEST(point_sort_test)
	TEST(insertion_sort_test)
	TEST(comperator_test)

END_SUITE
