#include "mu_test.h"
#include "blocking_queue.hpp"
#include "mutex.hpp"
#include "thread.hpp"
#include <unistd.h>
#include <exception>

int const N = 1000000;

void* producer(void* a_arg)
{
	mt::BlockingQueue<int>* q = static_cast<mt::BlockingQueue<int>* >(a_arg);
	int i = 0;
	while(i < N)
	{
		try{
			q->enqueue(i);
			++i;
		}
		catch(mt::BlockingQueueExceptions& a_error){}
	}
	return 0;
}

void* consumer(void* a_arg)
{
	mt::BlockingQueue<int>* q = static_cast<mt::BlockingQueue<int>* >(a_arg);
	int i = 0;
	while(i < N)
	{
		try{		
			int r;
			q->dequeue(r);
			if(r == i){
				++i;
			}
			else{
				std::cout << "dequeue fail!\n";
				break;
			}
		}
		catch(mt::BlockingQueueExceptions& a_error){}
	}
	return 0;
}

void* positiveIn(void* a_arg)
{
	mt::BlockingQueue<int>* q = static_cast<mt::BlockingQueue<int>* >(a_arg);
	int i = 1;
	while(i < N/2)
	{
		try{
			q->enqueue(i);
			++i;
		}
		catch(mt::BlockingQueueExceptions& a_error){}
	}
	return 0;
}

void* NegativeIn(void* a_arg)
{
	mt::BlockingQueue<int>* q = static_cast<mt::BlockingQueue<int>* >(a_arg);
	int i = -1;
	while(i > -N/2)
	{
		try{
			q->enqueue(i);
			--i;
		}
		catch(mt::BlockingQueueExceptions& a_error){}
	}
	return 0;
}

void* outCheck(void* a_arg)
{
	mt::BlockingQueue<int>* q = static_cast<mt::BlockingQueue<int>* >(a_arg);
	int i = 0;
	int prevNegative = 0;
	int prevPositive = 0;
	while(i < N - 2)
	{
		try{
			int r;
			q->dequeue(r);
			if(r > 0){
				if(r - prevPositive == 1){
					prevPositive = r;
					++i;	
				}
				else{
					std::cout << "fail! current: " << r << "previous: " << prevPositive << "\n";
					int* bed = new int;
					*bed = 111;
					return static_cast<void*>(bed);
				}
			}
			else{
				if(r - prevNegative == -1){
					prevNegative = r;
					++i;	
				}
				else{
					std::cout << "fail! current: " << r << "previous: " << prevNegative << "\n";
					int* bed = new int;
					*bed = 111;
					return static_cast<void*>(bed);
				}
			}
		}
		catch(mt::BlockingQueueExceptions& a_error){}
	}
	int* good = new int;
	*good = 555;
	return static_cast<void*>(good);
}

void* fillQwithClear(void* a_arg)
{
	mt::BlockingQueue<int>* q = static_cast<mt::BlockingQueue<int>* >(a_arg);
	int i = 0;
	while(i < N)
	{
		if(i == N/2)
		{
			q->clear();
		}
		try{
			q->enqueue(i);
			++i;
		}
		catch(mt::BlockingQueueExceptions& a_error){}
	}
	return 0;
}

void* fillQwithSize(void* a_arg)
{
	mt::BlockingQueue<int>* q = static_cast<mt::BlockingQueue<int>* >(a_arg);
	size_t i = 0;
	while(i < 1000)
	{
		if(i != q->size())
		{
			std::cout << "size test fail";
			int* bed = new int;
			*bed = 111;
			return static_cast<void*>(bed);
		}
		try{
			q->enqueue(i);
			++i;
		}
		catch(mt::BlockingQueueExceptions& a_error){}
	}
	int* good = new int;
	*good = 555;
	return static_cast<void*>(good);
}

void* checkSize(void* a_arg)
{
	mt::BlockingQueue<int>* q = static_cast<mt::BlockingQueue<int>* >(a_arg);
	for(size_t i = 0; i < 1000; ++i)
	{
		q->size();
	}
	return 0;
}

BEGIN_TEST(stress_test)
    try
    {
		mt::BlockingQueue<int> q(1000);
		cpp::Thread p(producer, static_cast<void*>(&q));
		cpp::Thread c(consumer, static_cast<void*>(&q));
		p.join();
		c.join();

		ASSERT_EQUAL(q.size(), 0);
	}
	catch(cpp::ThreadExceptions const& a_exception)
    {
        std::clog << a_exception.getFunctionName() << " fail! error number: " << a_exception.getErrorNumber() << "\n";
    }
	
END_TEST

BEGIN_TEST(fifo_test)

	try
    {
		mt::BlockingQueue<int> q(1000);
		cpp::Thread inP(positiveIn, static_cast<void*>(&q));
		cpp::Thread inN(NegativeIn, static_cast<void*>(&q));
		cpp::Thread out(outCheck, static_cast<void*>(&q));

		inP.join();
		inN.join();
		void* r = out.join();

		ASSERT_EQUAL(*static_cast<int*>(r), 555);
		delete static_cast<int*>(r);
	}
	catch(cpp::ThreadExceptions const& a_exception)
    {
        std::clog << a_exception.getFunctionName() << " fail! error number: " << a_exception.getErrorNumber() << "\n";
    }
	
END_TEST

BEGIN_TEST(clear_test)

    try
    {
		mt::BlockingQueue<int> q(N*3);
		cpp::Thread t1(fillQwithClear, static_cast<void*>(&q));
		cpp::Thread t2(fillQwithClear, static_cast<void*>(&q));
		cpp::Thread t3(fillQwithClear, static_cast<void*>(&q));
		t1.join();
		t2.join();
		t3.join();
		ASSERT_THAT(q.size() < N/2*3);
	}
	catch(cpp::ThreadExceptions const& a_exception)
    {
        std::clog << a_exception.getFunctionName() << " fail! error number: " << a_exception.getErrorNumber() << "\n";
    }

END_TEST

BEGIN_TEST(size_test)

    try
    {
		mt::BlockingQueue<int> q(1000);
		cpp::Thread t1(fillQwithSize, static_cast<void*>(&q));
		cpp::Thread t2(checkSize, static_cast<void*>(&q));

		void* r = t1.join();
		t2.join();

		ASSERT_EQUAL(*static_cast<int*>(r), 555);
		ASSERT_EQUAL(q.size(), 1000);
		delete static_cast<int*>(r);
	}
	catch(cpp::ThreadExceptions const& a_exception)
    {
        std::clog << a_exception.getFunctionName() << " fail! error number: " << a_exception.getErrorNumber() << "\n"; 
    }
	
END_TEST

BEGIN_TEST(exceptions_enqueue_dequeue)

	using namespace mt;

	BlockingQueue<int> q(5);

	for(int i = 0; i < 5; ++i)
	{
		try{
			q.enqueue(i);
		}
		catch(BlockingQueueExceptions& a_erroe){
			ASSERT_FAIL("should not throw exception");
		}
	}

	size_t exceptionCount = 0;
	for(int i = 0; i < 30; ++i)
	{
		try{
			q.enqueue(i);
		}
		catch(BlockingQueueExceptions& a_erroe){
			++exceptionCount;
			//std::clog << a_erroe.what();
		}
	}
	
	ASSERT_EQUAL(exceptionCount, 30);

	int item;
	for(int i = 0; i < 5; ++i)
	{
		try{
			q.dequeue(item);
		}
		catch(BlockingQueueExceptions& a_erroe){
			ASSERT_FAIL("should not throw exception");
		}
	}

	size_t exceptionCount2 = 0;
	for(int i = 0; i < 30; ++i)
	{
		try{
			q.dequeue(item);
		}
		catch(BlockingQueueExceptions& a_erroe){
			++exceptionCount2;
			//std::clog << a_erroe.what();
		}
	}

	ASSERT_EQUAL(exceptionCount2, 30);
	if(item){}

END_TEST

BEGIN_SUITE(TEST)

	TEST(stress_test)
	TEST(fifo_test)
	TEST(clear_test)
	TEST(size_test)
//	TEST(exceptions_enqueue_dequeue)

END_SUITE
