#include "utils.hpp"
#include "stack.hpp"
#include "min_stack.hpp"
#include <cassert>
#include <cstdio>

MinStack::MinStack(size_t a_capacity)
: m_data(a_capacity)
, m_min(a_capacity)
, m_capacity(a_capacity)
{
    axioms();
}

void MinStack::push(int a_item)
{
    assert(!isFull());
    if (m_data.isEmpty())
    {
        m_min.push(a_item);
    }
    else
    {
        if (a_item <= m_min.top())
        {
            m_min.push(a_item);
        }
    }

    m_data.push(a_item);
    axioms();
}

int MinStack::pop()
{
    assert(!isEmpty());
    int popItem = m_data.pop();
    if (popItem == m_min.top())
    {
        m_min.pop();
    }
    axioms();
    return popItem;
}

int MinStack::top() const
{
    assert(!isEmpty());
    return m_data.top();
}

int MinStack::min() const
{
    assert(!isEmpty());
    return m_min.top();
}

bool MinStack::isFull() const
{
    return m_data.isFull();
}

bool MinStack::isEmpty() const
{
    return m_data.isEmpty();
}

void MinStack::axioms() const
{
    assert(m_capacity >= 0);
    assert(m_data.size() >= m_min.size());
}

void MinStack::display() const
{
    printf("data: \n");
    m_data.dump();
    printf("\nmin: \n");
    m_min.dump();
}
