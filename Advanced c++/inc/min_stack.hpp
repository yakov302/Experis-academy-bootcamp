#ifndef MIN_STACK_H
#define MIN_STACK_H
#include "stack.hpp"

class MinStack
{
public:
    MinStack(size_t a_capacity = STACK_SIZE);

    void push(int a_item);
    int pop();

    int top()const;
    int min()const;
    bool isFull() const;
    bool isEmpty() const;
    void display() const;

private:
    void axioms() const;

private:
    Stack m_data;
    Stack m_min;
    size_t const m_capacity;
};


#endif /* MIN_STACK_H*/