#ifndef STACK_H
#define STACK_H

#include <cstddef>

const size_t STACK_SIZE = 100;

class Stack
{
public:
    Stack(size_t a_capacity = STACK_SIZE);
    Stack(int *a_arr, size_t a_capacity = STACK_SIZE);
    Stack(int *a_arr, size_t a_numOfPush, size_t a_capacity = STACK_SIZE);
    Stack(Stack const &source);
    Stack &operator=(Stack const &source);
    ~Stack();

    void empty();
    void push(int a_item);
    size_t push(int *a_arr, size_t a_numOfPush);
    size_t pop(int *a_arr, size_t a_numOfPop);
    int pop();
    void drain(Stack &a_source);
    void ensureCapacity(size_t a_capacity);

    size_t size() const;
    int top() const;
    size_t getCapacity() const;
    bool isEmpty() const;
    bool isFull() const;
    void dump() const;

private:
    void dumpElements() const;
    void axioms() const;

private:
    int *m_elements;
    int m_tos;
    int m_capacity;
};

void combine(Stack &a_first, Stack &a_second, Stack &a_result);

#endif /*#ifndefSTACK_H122*/
