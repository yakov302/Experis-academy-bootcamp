#include "mu_test.h"
#include "stack.hpp"
#include "utils.hpp"

BEGIN_TEST(new_stack_is_empty)

    Stack stack(5);
    ASSERT_THAT(stack.isEmpty());
    ASSERT_EQUAL(stack.size(), (size_t)0);

    END_TEST

BEGIN_TEST(stack_is_not_empty)

    Stack stack(5);
    stack.push(4);
    ASSERT_THAT(!stack.isEmpty());
    ASSERT_EQUAL(stack.size(), (size_t)1);

END_TEST


BEGIN_TEST(stack_is_full)

    Stack stack(3);
    stack.push(4);
    stack.push(9);
    stack.push(42);
    ASSERT_THAT(stack.isFull());
    ASSERT_EQUAL(stack.size(), (size_t)3);

END_TEST


BEGIN_TEST(stack_is_not_full)

    Stack stack(3);
    stack.push(4);
    stack.push(9);
    ASSERT_THAT(!stack.isFull());
    ASSERT_EQUAL(stack.size(), (size_t)2);

END_TEST


BEGIN_TEST(is_stack_size_work)

    int n = 10;
    int i;

    Stack stack(n);
    for (i = 0; i < n - 1; i++)
    {
        stack.push(i);
        ASSERT_EQUAL(stack.size(), (size_t)i + 1);
    }

END_TEST


BEGIN_TEST(stack_push_successfully)

    int n = 10;

    Stack stack(n);
    for (int i = 0; i < n - 1; i++)
    {
        stack.push(i);
        ASSERT_EQUAL(stack.size(), (size_t)i + 1);
        ASSERT_THAT(!stack.isFull());
        ASSERT_THAT(!stack.isEmpty());
    }

END_TEST


BEGIN_TEST(stack_push_full)

    int n = 10;
    int i;

    Stack stack(n);
    for (i = 0; i < n - 1; i++)
    {
        stack.push(i);
        ASSERT_EQUAL(stack.size(), (size_t)i + 1);
        ASSERT_THAT(!stack.isFull());
        ASSERT_THAT(!stack.isEmpty());
    }

    stack.push(i);
    ASSERT_EQUAL(stack.size(), (size_t)i + 1);
    ASSERT_THAT(stack.isFull());
    ASSERT_THAT(!stack.isEmpty());

END_TEST


BEGIN_TEST(stack_pop_successfully)

        int n = 10;
        int i;

        Stack stack(n);
        for (i = 0; i < n - 1; i++)
        {
            stack.push(i);
            ASSERT_EQUAL(stack.size(), (size_t)i + 1);
            ASSERT_THAT(!stack.isFull());
            ASSERT_THAT(!stack.isEmpty());
        }

        for (i = n - 2; i > 0; i--)
        {
            ASSERT_EQUAL(stack.pop(), i);
            ASSERT_EQUAL(stack.size(), (size_t)i);
            ASSERT_THAT(!stack.isEmpty());
        }

END_TEST


BEGIN_TEST(stack_pop_empty)

    int n = 10;
    int i;

    Stack stack(n);
    for (i = 0; i < n - 1; i++)
    {
        stack.push(i);
        ASSERT_EQUAL(stack.size(), (size_t)i + 1);
        ASSERT_THAT(!stack.isFull());
        ASSERT_THAT(!stack.isEmpty());
    }

    for (i = n - 2; i > 0; i--)
    {
        ASSERT_EQUAL(stack.pop(), i);
        ASSERT_EQUAL(stack.size(), (size_t)i);
        ASSERT_THAT(!stack.isEmpty());
    }

    stack.pop();
    ASSERT_EQUAL(stack.size(), (size_t)0);
    ASSERT_THAT(stack.isEmpty());

END_TEST


BEGIN_TEST(stack_empty)
    int n = 10;

    Stack stack(n);
    for (int i = 0; i < n - 1; i++)
    {
        stack.push(i);
    }
    stack.empty();
    ASSERT_THAT(stack.isEmpty());

END_TEST


BEGIN_TEST(new_stack_with_arr)

    size_t r;
    int *arr = new int[50];
    for (int i = 0; i < 50; i++)
    {
        arr[i] = i;
    }

    Stack stack(arr, 50, 50);
    for (int i = 49; i > 0; i--)
    {
        r = stack.pop();
        ASSERT_EQUAL(r, (size_t)i);
    }
    stack.pop();

    ASSERT_THAT(stack.isEmpty());

    delete[] arr;

END_TEST


BEGIN_TEST(new_stack_with_arr_choice_the_quantity)

    size_t r;
    int *arr = new int[80];
    for (int i = 0; i < 80; i++)
    {
        arr[i] = i;
    }

    Stack stack(arr, 30, 100);
    for (int i = 30; i > 0; i--)
    {
        r = stack.pop();
        ASSERT_EQUAL(r, (size_t)i - 1);
    }

    ASSERT_THAT(stack.isEmpty());

    delete[] arr;

END_TEST


BEGIN_TEST(push_arr)

    size_t r;
    int *arr = new int[80];
    for (int i = 0; i < 80; i++)
    {
        arr[i] = i;
    }

    Stack stack(85);
    stack.push(arr, (size_t)80);
    for (int i = 80; i > 0; i--)
    {
        r = stack.pop();
        ASSERT_EQUAL(r, (size_t)i - 1);
    }

    ASSERT_THAT(stack.isEmpty());

    delete[] arr;

END_TEST


BEGIN_TEST(pop_to_arr)

    int *arr = new int[80];
    for (int i = 0; i < 80; i++)
    {
        arr[i] = i;
    }

    Stack stack(85);
    stack.push(arr, (size_t)80);
    for (int i = 0; i < 80; i++)
    {
        arr[i] = 0;
    }

    stack.pop(arr, 80);
    int j = 79;
    for (int i = 0; i < 80; i++)
    {
        ASSERT_EQUAL((size_t)arr[i], (size_t)j);
        j--;
    }

    delete[] arr;

END_TEST


BEGIN_TEST(merge_two_stacks)

   int r;
    int *arr1 = new int[15];
    int j = 20;
    for (int i = 0; i <  10; i++)
    {
        arr1[i] = j;
        j--;
    }

    j = 10;
    int *arr2 = new int[15];
    for (int i = 0; i < 10; i++)
    {
        arr2[i] = j;
        j--;
    }

    Stack stack1(arr1,10,10);
    Stack stack2(arr2,10,10);
    Stack stack3;

    combine(stack2, stack1, stack3);
    

    for (int i = 20; i > 0; i--)
    {
        r = stack3.pop();
        ASSERT_EQUAL(r, i);
    }

    delete[] arr1;
    delete[] arr2;

END_TEST


BEGIN_TEST(is_realloc_work)
    
    Stack stack(10);
    ASSERT_EQUAL(stack.getCapacity(), 10);
    for(size_t i = 0; i < 10; i++)
    {
      stack.push(i+1); 
    }

    stack.ensureCapacity(20); 
    ASSERT_EQUAL(stack.getCapacity(), 20);

    int r;
    int j = 10;
    for(size_t i = 0; i < 10; i++)
    {
      r = stack.pop();
      ASSERT_EQUAL(r, j);
      j--; 
    }

END_TEST

void fx(Stack s)
{
    s.getCapacity();
}

BEGIN_TEST(copy_stacks)
    
    Stack source(53);
    for(int i = 1; i < 11; i++)
    {
        source.push(i);
    }
    Stack destination;
    destination = source;
    ASSERT_EQUAL(destination.getCapacity(), 53);
    ASSERT_THAT( !!! destination.isEmpty());

    int j = 10;
    int r;
    for(int i = 1; i < 11; i++)
    {
        r = destination.pop();
        ASSERT_EQUAL(r, j);
        j--;
    }

    fx(source);
    ASSERT_PASS();

END_TEST


BEGIN_TEST(empty_stack)

    Stack s;
    for(int i = 1; i < 11; i++)
    {
        s.push(i);
    }
    ASSERT_THAT( !!! s.isEmpty());

    s.empty();

    ASSERT_THAT( s.isEmpty());

END_TEST

BEGIN_TEST(is_top_work)

    Stack s;
    for(int i = 1; i < 11; i++)
    {
        s.push(i);
    }
    int r = s.top();
    ASSERT_EQUAL(r, 10);

    r = s.pop();
    ASSERT_EQUAL(r, 10);

END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)

    TEST(new_stack_is_empty)
    TEST(stack_is_not_empty)
    TEST(stack_is_full)
    TEST(stack_is_not_full)
    TEST(is_stack_size_work)
    TEST(stack_push_successfully)
    TEST(stack_push_full)
    TEST(stack_pop_successfully)
    TEST(stack_pop_empty)
    TEST(stack_empty)
    TEST(new_stack_with_arr_choice_the_quantity)
    TEST(new_stack_with_arr)
    TEST(push_arr)
    TEST(pop_to_arr)
    TEST(merge_two_stacks)
    TEST(is_realloc_work)
    TEST(copy_stacks)
    TEST(empty_stack)
    TEST(is_top_work)

END_SUITE
