#include "mu_test.h"
#include "queue.hpp"


BEGIN_TEST(int_queue)

	using namespace cpp;

	Queue<int> q(5);

	ASSERT_EQUAL(q.size(), 0);
	ASSERT_EQUAL(q.empty(), true);
	ASSERT_EQUAL(q.full(), false);

	for(int i = 1; i < 6; i++)
	{
		q.enqueue(i);
		ASSERT_EQUAL(q.size(), (size_t) i);
	}

	ASSERT_EQUAL(q.empty(), false);
	ASSERT_EQUAL(q.full(), true);

	Queue<int> copy;
	copy = q;
	ASSERT_EQUAL(copy.size(), 5);

	int temp;
	for(int i = 1; i < 6; i++)
	{
		q.dequeue(temp);
		ASSERT_EQUAL(temp, i);
	}

	ASSERT_EQUAL(q.empty(), true);
	ASSERT_EQUAL(q.full(), false);

	copy.clear();
	ASSERT_EQUAL(copy.size(), 0);
	ASSERT_EQUAL(copy.empty(), true);
	ASSERT_EQUAL(copy.full(), false);

	
END_TEST

class Cat
{
public:
	Cat(int a_numOfMeow = 1){m_numOfMeow = a_numOfMeow;}
	int numOfMeow(){return m_numOfMeow;}

private:
	int m_numOfMeow;
};

BEGIN_TEST(cat_queue)

	using namespace cpp;

	Queue<Cat> q(2);

	ASSERT_EQUAL(q.size(), 0);
	ASSERT_EQUAL(q.empty(), true);
	ASSERT_EQUAL(q.full(), false);

	Cat j;
	q.enqueue(j);
	ASSERT_EQUAL(q.size(), 1);

	Cat y(2);
	q.enqueue(y);
	ASSERT_EQUAL(q.size(), 2);


	ASSERT_EQUAL(q.empty(), false);
	ASSERT_EQUAL(q.full(), true);

	Queue<Cat> copy;
	copy = q;
	ASSERT_EQUAL(copy.size(), 2);

	Cat temp;
	q.dequeue(temp);
	ASSERT_EQUAL(temp.numOfMeow(), j.numOfMeow());

	q.dequeue(temp);
	ASSERT_EQUAL(temp.numOfMeow(), y.numOfMeow());


	ASSERT_EQUAL(q.empty(), true);
	ASSERT_EQUAL(q.full(), false);

	copy.clear();
	ASSERT_EQUAL(copy.size(), 0);
	ASSERT_EQUAL(copy.empty(), true);
	ASSERT_EQUAL(copy.full(), false);

END_TEST


BEGIN_TEST(queue_queue)

	using namespace cpp;

	Queue< Queue<int> > q(2);

	ASSERT_EQUAL(q.size(), 0);
	ASSERT_EQUAL(q.empty(), true);
	ASSERT_EQUAL(q.full(), false);

	Queue<int> first;
	first.enqueue(1);
	first.enqueue(2);
	first.enqueue(3);
	q.enqueue(first);
	ASSERT_EQUAL(q.size(), 1);

	Queue<int> second;
	second.enqueue(4);
	second.enqueue(5);
	q.enqueue(second);
	ASSERT_EQUAL(q.size(), 2);

	ASSERT_EQUAL(q.empty(), false);
	ASSERT_EQUAL(q.full(), true);

	Queue< Queue<int> > copy;
	copy = q;
	ASSERT_EQUAL(copy.size(), 2);

	Queue<int> temp;
	q.dequeue(temp);
	ASSERT_EQUAL(temp.size(), first.size());

	q.dequeue(temp);
	ASSERT_EQUAL(temp.size(), second.size());

	ASSERT_EQUAL(q.empty(), true);
	ASSERT_EQUAL(q.full(), false);

	copy.clear();
	ASSERT_EQUAL(copy.size(), 0);
	ASSERT_EQUAL(copy.empty(), true);
	ASSERT_EQUAL(copy.full(), false);

END_TEST

BEGIN_TEST(queue_of_queue_order_chack)

	using namespace cpp;

	Queue< Queue<int> > q(5);

	Queue<int> first;
	for(int i = 1; i < 6; i++)
	{
		first.enqueue(i);
	}

	Queue<int> second;
	for(int i = 6; i < 11; i++)
	{
		second.enqueue(i);
	}

	Queue<int> third;
	for(int i = 11; i < 16; i++)
	{
		third.enqueue(i);
	}

	q.enqueue(first);
	q.enqueue(second);
	q.enqueue(third);

	Queue<int> result;

	q.dequeue(result);
	int r;
	for(int i = 1; i < 6; i++)
	{
		result.dequeue(r);
		ASSERT_EQUAL(r, i);
	}

	Queue< Queue<int> > copy = q;

	copy.dequeue(result);
	for(int i = 6; i < 11; i++)
	{
		result.dequeue(r);
		ASSERT_EQUAL(r, i);
	}

	copy.dequeue(result);
	for(int i = 11; i < 16; i++)
	{
		result.dequeue(r);
		ASSERT_EQUAL(r, i);
	}

END_TEST

void copying (cpp::Queue<int> q)
{
	std::cout << "in function\n";
	q.print();
}

BEGIN_TEST(copying_queue)

	using namespace cpp;

	Queue<int> q(40);
	int item;

	for(int i = 0; i < 40; ++i)
	{
		q.enqueue(i);
	}
	for(int i = 0; i < 30; ++i)
	{
		q.dequeue(item);
	}
	for(int i = 0; i < 10; ++i)
	{
		q.enqueue(i);
	}

	copying (q);

	Queue<int> c;
	c = q;
	std::cout << "\nin test\n";
	c.print();

	ASSERT_PASS();

END_TEST

BEGIN_TEST(exceptions_enqueue_dequeue)

	using namespace cpp;

	Queue<int> q(5);

	for(int i = 0; i < 5; ++i)
	{
		try{
			q.enqueue(i);
		}
		catch(QueueExceptions& a_erroe){
			ASSERT_FAIL("should not throw exception");
		}
	}

	size_t exceptionCount = 0;
	for(int i = 0; i < 30; ++i)
	{
		try{
			q.enqueue(i);
		}
		catch(const std::exception& a_erroe){
			++exceptionCount;
			std::clog << a_erroe.what();
		}
	}
	
	ASSERT_EQUAL(exceptionCount, 30);

	int item;
	for(int i = 0; i < 5; ++i)
	{
		try{
			q.dequeue(item);
		}
		catch(QueueExceptions& a_erroe){
			ASSERT_FAIL("should not throw exception");
		}
	}

	size_t exceptionCount2 = 0;
	for(int i = 0; i < 30; ++i)
	{
		try{
			q.dequeue(item);
		}
		catch(const std::exception& a_erroe){
			++exceptionCount2;
			std::clog << a_erroe.what();
		}
	}

	ASSERT_EQUAL(exceptionCount2, 30);

END_TEST


BEGIN_SUITE(TEST)

	TEST(int_queue)
	TEST(cat_queue)
	TEST(queue_queue)
	TEST(queue_of_queue_order_chack)
	TEST(copying_queue)
	TEST(exceptions_enqueue_dequeue)

END_SUITE
