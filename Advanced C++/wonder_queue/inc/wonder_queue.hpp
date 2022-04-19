#ifndef WONDER_QUEUE_H
#define WONDER_QUEUE_H
#include "stack.hpp"

const size_t QUEUE_SIZE = 100;

class WonderQueue
{
public:
    WonderQueue(size_t a_capacity = QUEUE_SIZE);

    void enqueue(int a_item);
    int dequeue();

    size_t capacity() const;
    size_t size() const;
    size_t leftSpese() const;

    bool isFull()const;
    bool isEmpty()const;
    void display() const;

private:
    void axioms() const;

private:
    Stack m_in;
    Stack m_out;
    size_t m_capacity;
};


#endif /* WONDER_QUEUE_H*/