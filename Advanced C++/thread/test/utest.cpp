#include "mu_test.h"
#include <iostream>
#include"thread.hpp"

const size_t arrSize = 1000;
const size_t N = 1000 * 1000 * 10;
int arr[arrSize];
int g = 0;
int sum = 0;

void* fillOdd(void*)
{
    for(size_t i = 1; i < arrSize; i += 2) 
	{
        arr[i] = i;
    }
    return 0;
}

void* fillEven(void*)
{
    for(size_t i = 0; i < arrSize; i += 2)
	{
        arr[i] = i;
    }
    return 0;
}

void* zeroArrayOdd (void*)
{
	for(size_t i = 1; i < arrSize; i+=2) 
	{
        arr[i] = 0;
    }
    return 0;
}

void* zeroArrayEven (void*)
{
	for(size_t i = 0; i < arrSize; i+=2) 
	{
        arr[i] = 0;
    }
    return 0;

}

void* fillBySize(void* a_arg)
{
	int size = *static_cast<int*>(a_arg);
    for(int i = 0; i < size; ++i) 
	{
        arr[i] = 555;
    }
	int* r = new int;
	*r = 1826;
    return static_cast<void*>(r);
}

BEGIN_TEST(fill_array)
    cpp::Thread th1(fillEven);
    cpp::Thread th2(fillOdd);  
    th1.join();  
    th2.join();

	for(size_t i = 1; i < arrSize; ++i) 
	{
		ASSERT_EQUAL(arr[i] - arr[i - 1], 1);    
    }

END_TEST


BEGIN_TEST(zero_array)
    cpp::Thread th1(zeroArrayEven);
    cpp::Thread th2(zeroArrayOdd);  
  	th1.join();
    th2.join();    
    
	for(size_t i = 0; i < arrSize; ++i) 
	{
		ASSERT_EQUAL(arr[i] , 0);    
    }

END_TEST

BEGIN_TEST(fill_array_with_arg)

	int n = 100;
	void* arg = static_cast<void*>(&n);
    cpp::Thread th1(fillBySize, arg);
  	void* r = th1.join();  

	for(int i = 0; i < n ; ++i) 
	{
		ASSERT_EQUAL(arr[i] , 555);    
    }
	for(int i = n; i < n*2 ; ++i) 
	{
		ASSERT_NOT_EQUAL(arr[i] , 555);    
    }

	ASSERT_EQUAL(*static_cast<int*>(r) , 1826);
	delete static_cast<int*>(r); 

END_TEST


BEGIN_SUITE(tread_tests)

    TEST(fill_array)
	TEST(zero_array)
	TEST(fill_array_with_arg)

END_SUITE
