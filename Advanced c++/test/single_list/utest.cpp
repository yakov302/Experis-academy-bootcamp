#include "mu_test.h"
#include "single_list.hpp"
#include <iostream>    
#include <algorithm>    
#include <vector> 
#include "ball.hpp"

BEGIN_TEST(empty_list)

	LinkedList<int> list;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	int r = list.first();
	r = list.last();
	ASSERT_EQUAL(r, 0);

END_TEST

BEGIN_TEST(add_and_remove)

	LinkedList<int> list;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	for (int i = 1; i < 11; i++)
	{
		list.add(i);
	}
	ASSERT_EQUAL(list.size(), 10);
	ASSERT_EQUAL(list.isEmpty(), false);

	for (int i = 1; i < 11; i++)
	{
		list.remove();
	}
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

END_TEST

BEGIN_TEST(all_function)

	LinkedList<int> list;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	ListIterator<int> it;
	it = list.begin();
	ASSERT_EQUAL(it.data(), 0);
	it = list.end();
	ASSERT_EQUAL(it.data(), 0);
	ASSERT_EQUAL(it.equal(list.begin()), true);
	ASSERT_EQUAL(it.notEqual(list.begin()), false);

	for (int i = 1; i < 11; i++)
	{
		list.add(i);
	}
	ASSERT_EQUAL(list.size(), 10);
	ASSERT_EQUAL(list.isEmpty(), false);
	ASSERT_EQUAL(list.first(), 10);
	ASSERT_EQUAL(list.last(), 1);

	it = list.begin();
	ASSERT_EQUAL(it.data(), 10);
	it.next();
	ASSERT_EQUAL(it.data(), 9);
	it = list.end();
	ASSERT_EQUAL(it.data(), 0);
	ASSERT_EQUAL(it.equal(list.begin()), false);
	ASSERT_EQUAL(it.notEqual(list.begin()), true);

	it = list.begin();
	int r;
	for (int i = 10; i > 0; i--)
	{
		r = it.data();
		ASSERT_EQUAL(r, i);
		it.next();
	}

	for (int i = 1; i < 11; i++)
	{
		list.remove();
	}
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	it = list.end();
	ASSERT_EQUAL(it.data(), 0);

END_TEST

void addOne(LinkedList<int> a_list)
{
	a_list.add(1);
}

BEGIN_TEST(test_cctor)

	LinkedList<int> list;
	ASSERT_THAT(list.isEmpty());
	addOne(list);
	ASSERT_EQUAL(list.size(), 0);

END_TEST

BEGIN_TEST(test_operator_equal)

	LinkedList<int> a;
	LinkedList<int> b;

	for (size_t i = 1; i < 6; i++)
	{
		b.add(i);
	}

	a = b;
	ASSERT_EQUAL(b.size(), 5);
	ASSERT_EQUAL(a.size(), 5);

END_TEST

BEGIN_TEST(contains)

	LinkedList<int> list;

	for (int i = 1; i < 10; i++)
	{
		list.add(i);
	}

	ASSERT_EQUAL(list.contains(1),true);
	ASSERT_EQUAL(list.contains(11),false);

END_TEST


BEGIN_TEST(containsData_test)

	LinkedList<int> list;

	for (int i = 1; i < 10; i++)
	{
		list.add(i);
	}

	ASSERT_EQUAL(containsData(list, 1),true);
	ASSERT_EQUAL(containsData(list, 11),false);

END_TEST


BEGIN_TEST(rangeContains_test)

	LinkedList<int> list;

	for (int i = 1; i < 10; i++)
	{
		list.add(i);
	}

	ListIterator<int> b = list.begin();
	ListIterator<int> e = list.end();

	ASSERT_EQUAL(rangeContains(b, e, 1),true);
	ASSERT_EQUAL(rangeContains(b, e, 11),false);

END_TEST


BEGIN_TEST(test_intersect)

	LinkedList<int> first;
	LinkedList<int> second;
	LinkedList<int> result;

	for (int i = 1; i < 10; i++)
	{
		first.add(i);
	}
	for (int i = 5; i < 10; i++)
	{
		second.add(i);
	}

	intersect(first, second, result);

	ASSERT_EQUAL(result.size(),5);

	ListIterator<int> it = result.begin();
	int j = 5;
	for (int i = 5; i < 10; i++)
	{
		ASSERT_EQUAL(it.data(),j);
		j++;
		it.next();
	}

END_TEST


BEGIN_TEST(equal_and_not_equal_operator)

	LinkedList<int> list;

	for (int i = 1; i < 3; i++)
	{
		list.add(i);
	}

	for (int i = 1; i < 3; i++)
	{
		list.add(i);
	}

	ListIterator<int> it = list.begin();
	ListIterator<int> next = list.begin().next();
	ASSERT_EQUAL(it != next, true);

	it = list.begin();
	next = list.begin();
	ASSERT_EQUAL(next == it, 1);

END_TEST


BEGIN_TEST(plus_plus_operator)

	LinkedList<int> list;

	list.add(3);
	list.add(2);
	list.add(1);
	list.add(0);

	ListIterator<int> it = list.begin();
	ListIterator<int> next = it++;
	ASSERT_EQUAL(it != next, true);
	ASSERT_EQUAL(next == list.begin(), true);
	ASSERT_EQUAL(it == list.begin().next(), true);

	it = list.begin();
	next = ++it;
	ASSERT_EQUAL(next == it, 1);
	ASSERT_EQUAL(next == list.begin().next(), true);
	ASSERT_EQUAL(it == list.begin().next(), true);

END_TEST


BEGIN_TEST(dereference_operator)

	LinkedList<int> list;

	list.add(3);
	list.add(2);
	list.add(1);
	list.add(0);

	ListIterator<int> it = list.begin();
	*it = 18;
	std::cout<< *it;
	ASSERT_EQUAL(list.begin().data(), 18);

END_TEST


BEGIN_TEST(dereference_and_pluse_operator)

	LinkedList<int> list;

	list.add(3);
	list.add(2);
	list.add(1);
	list.add(0);

	ListIterator<int> it = list.begin();
	*it++ = 4;
	ASSERT_EQUAL(list.begin().data(), 4);

END_TEST

struct BallFancyComp {
    BallFancyComp(int t) : threshold(t) {}
    bool operator()(cpp::Ball const& b) const{
        int r = b.getRadius();
        return r % 2 == 0 &&  r > threshold;
    }
private:
    int threshold;
};

BEGIN_TEST(find_if_test)
	using namespace cpp;
    LinkedList<Ball> list;

    for(size_t i = 0; i < 10; i++)
    {
        list.add(Ball('r', i));
    }

    ListIterator<Ball> it = list.begin();


    Ball b = *it;
    ASSERT_EQUAL(b.getRadius(), 9);

    //ASSERT_EQUAL((*it).getColor(), "red");
    // const char* c = (*it).getColor();
    // ASSERT_EQUAL_STR(c, "red");
    ++it;
    int r = it++->getRadius();
    ASSERT_EQUAL(r, 8);

    ListIterator<Ball> end = list.end();
    it = std::find_if(list.begin(), list.end(), BallFancyComp(5));
    ASSERT_THAT(it != end);
    // //TRACE(*it);

    it = std::find_if(list.begin(), list.end(), BallFancyComp(2));
    ASSERT_THAT(it != end);
    // TRACE(*it);

    it = std::find_if(list.begin(), list.end(), BallFancyComp(98978));
    ASSERT_THAT(it == end);


    ASSERT_PASS();
END_TEST


bool IsOdd (int i) {
  return ((i%2)==1);
}

BEGIN_TEST(IsOdd_tets)

  std::vector<int> myvector;
  myvector.push_back(10);
  myvector.push_back(25);
  myvector.push_back(40);
  myvector.push_back(55);

  std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(), IsOdd);
  std::cout << "The first odd value is " << *it << '\n';
  ASSERT_EQUAL(*it, 25);

END_TEST


bool IsEven (int i) 
{
  return ((i % 2) == 0);
}
BEGIN_TEST(find_if)
	
	LinkedList<int> a;
	
	for (size_t i = 1; i < 6; i++)
	{
		a.add(i);
	}
	
	ListIterator<int> it = std::find_if (a.begin(), a.end(), IsEven);
	std::cout << "the first: " << *it << '\n';
	ASSERT_EQUAL(*it, 4);

END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)

IGNORE_TEST(empty_list)
TEST(add_and_remove)
TEST(all_function)
TEST(test_cctor)
TEST(test_operator_equal)
TEST(contains)
TEST(test_intersect)
TEST(containsData_test)
TEST(rangeContains_test)
TEST(equal_and_not_equal_operator)
TEST(plus_plus_operator)
TEST(dereference_operator)
TEST(dereference_and_pluse_operator)
TEST(find_if_test)
TEST(IsOdd_tets)
TEST(find_if)

END_SUITE
