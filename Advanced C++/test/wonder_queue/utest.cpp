#include "mu_test.h"
#include "wonder_queue.hpp"

BEGIN_TEST(initialisation_test)

	WonderQueue q(10);
	ASSERT_EQUAL(q.capacity(),20);
	ASSERT_EQUAL(q.size(), 0);
	ASSERT_EQUAL(q.isFull(), false);
	ASSERT_EQUAL(q.isEmpty(), true);

END_TEST


BEGIN_TEST(enqueue_and_dequeue)

	WonderQueue q(10);
	for(size_t i = 0; i < 10; i++)
	{
		q.enqueue((int)i+1);
	}
	ASSERT_EQUAL(q.size(), 10);
	ASSERT_EQUAL(q.isFull(), false);
	ASSERT_EQUAL(q.isEmpty(), false);
	ASSERT_EQUAL(q.capacity(),20);


	for(size_t i = 0; i < 10; i++)
	{
		q.enqueue((int)i+1);
	}
	ASSERT_EQUAL(q.size(), 20);
	ASSERT_EQUAL(q.isFull(), true);
	ASSERT_EQUAL(q.isEmpty(), false);
	ASSERT_EQUAL(q.capacity(), 20);


	int r;
	for(size_t i = 0; i < 9; i++)
	{
		r = q.dequeue();
		ASSERT_EQUAL(r,(int) i + 1);
	}
	ASSERT_EQUAL(q.size(), 11);
	ASSERT_EQUAL(q.isFull(), true);
	ASSERT_EQUAL(q.isEmpty(), false);
	ASSERT_EQUAL(q.capacity(), 11);

	q.dequeue();
	ASSERT_EQUAL(q.size(), 10);
	ASSERT_EQUAL(q.isFull(), false);
	ASSERT_EQUAL(q.isEmpty(), false);
	ASSERT_EQUAL(q.capacity(), 20);

	for(size_t i = 0; i < 10; i++)
	{
		r = q.dequeue();
		ASSERT_EQUAL(r,(int) i + 1);
	}
	ASSERT_EQUAL(q.size(), 0);
	ASSERT_EQUAL(q.isFull(), false);
	ASSERT_EQUAL(q.isEmpty(), true);
	ASSERT_EQUAL(q.capacity(),20);

END_TEST


BEGIN_TEST(capacity_and_size)

	WonderQueue q(50);
	ASSERT_EQUAL(q.capacity(),100);
	ASSERT_EQUAL(q.size(), 0);

	for(size_t i = 0; i < 25; i++)
	{
		q.enqueue((int)i+1);
	}
	ASSERT_EQUAL(q.capacity(),100);
	ASSERT_EQUAL(q.size(), 25);

	for(size_t i = 0; i < 25; i++)
	{
		q.enqueue((int)i+1);
	}
	ASSERT_EQUAL(q.capacity(),100);
	ASSERT_EQUAL(q.size(), 50);

	for(size_t i = 0; i < 25; i++)
	{
		q.dequeue();
	}
	ASSERT_EQUAL(q.capacity(),75);
	ASSERT_EQUAL(q.size(), 25);

	for(size_t i = 0; i < 25; i++)
	{
		q.dequeue();
	}
	ASSERT_EQUAL(q.capacity(),100);
	ASSERT_EQUAL(q.size(), 0);

END_TEST


BEGIN_TEST(empty_and_full)

	WonderQueue q(50);
	ASSERT_EQUAL(q.isFull(), false);
	ASSERT_EQUAL(q.isEmpty(), true);

	for(size_t i = 0; i < 100; i++)
	{
		q.enqueue((int)i+1);
	}
	ASSERT_EQUAL(q.isFull(), true);
	ASSERT_EQUAL(q.isEmpty(), false);

	for(size_t i = 0; i < 40; i++)
	{
		q.dequeue();
	}
	ASSERT_EQUAL(q.isFull(), true);
	ASSERT_EQUAL(q.isEmpty(), false);

	for(size_t i = 0; i < 10; i++)
	{
		q.dequeue();
	}
	ASSERT_EQUAL(q.isFull(), false);
	ASSERT_EQUAL(q.isEmpty(), false);

	for(size_t i = 0; i < 50; i++)
	{
		q.dequeue();
	}
	ASSERT_EQUAL(q.isFull(), false);
	ASSERT_EQUAL(q.isEmpty(), true);

END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)

	TEST(initialisation_test)
	TEST(enqueue_and_dequeue)
	TEST(capacity_and_size)
	TEST(empty_and_full)

END_SUITE
