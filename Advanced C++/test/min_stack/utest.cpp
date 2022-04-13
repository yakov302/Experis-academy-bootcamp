#include "mu_test.h"
#include "min_stack.hpp"
#include "utils.hpp"


BEGIN_TEST(min_with_empty)

    MinStack m;
    m.min();
      
END_TEST


BEGIN_TEST(empty_stack)

    MinStack minStack(5);     
    ASSERT_EQUAL(minStack.min(), 4); 
     
END_TEST


BEGIN_TEST(push_pop_and_min)

    MinStack m;
    int j = 11;
    for (int i = 0; i < 10; i++)
    {
        m.push(j);
        ASSERT_THAT(!m.isEmpty());
        ASSERT_THAT(!m.isFull());
        ASSERT_EQUAL(m.min(), 11);
        j++;
    }

    j = 1;
    for (int i = 0; i < 10; i++)
    {
        m.push(j);
        ASSERT_THAT(!m.isEmpty());
        ASSERT_THAT(!m.isFull());
        ASSERT_EQUAL(m.min(), 1);
        j++;
    }

    int r;
    j = 10;
    for (int i = 0; i < 9; i++)
    {
        r = m.pop();
        ASSERT_EQUAL(r, j);
        ASSERT_EQUAL(m.min(), 1);
        j--;
    }

    j = 20;
    m.pop();
    for (int i = 0; i < 9; i++)
    {
        r = m.pop();
        ASSERT_EQUAL(r, j);
        ASSERT_EQUAL(m.min(), 11);
        j--;
    }

END_TEST


BEGIN_TEST(min_stack_shoot)

    MinStack minStack(10);  
    minStack.push(4);    
    minStack.push(3); 
    minStack.push(2); 
    minStack.push(7); 
    minStack.push(1); 
    //minStack.display();
    ASSERT_EQUAL(minStack.min(), 1);  
    ASSERT_EQUAL(minStack.pop(), 1); 
      
END_TEST


BEGIN_TEST(min_one_element_stack)

    MinStack minStack(5);  
    minStack.push(4);    
    ASSERT_EQUAL(minStack.min(), 4);  
    ASSERT_EQUAL(minStack.pop(), 4); 
      
END_TEST


BEGIN_TEST(min_stack_big_shoot)

    MinStack minStack(10);  
    for(int i = 10 ; i > 0; i--)
    {
          minStack.push(i);    
    }

    for(int i = 1 ; i < 10; i++)
    {
        ASSERT_EQUAL(minStack.min(), i);  
        ASSERT_EQUAL(minStack.pop(), i);  
        ASSERT_EQUAL(minStack.min(), i+1);  
    }
          
END_TEST


BEGIN_TEST(is_top_work)

    MinStack s;
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

    IGNORE_TEST(min_with_empty)
    IGNORE_TEST(empty_stack)
    TEST(push_pop_and_min)
    TEST(min_stack_shoot)
    TEST(min_one_element_stack)
    TEST(min_stack_big_shoot)
    TEST(is_top_work)

END_SUITE
