#include "wonder_queue.hpp"
#include "utils.hpp"
#include "stack.hpp"
#include <cstdio>
#include <cassert>

WonderQueue::WonderQueue(size_t a_capacity)
: m_in(a_capacity)
, m_out(a_capacity)
, m_capacity(a_capacity)
{
    axioms();
}

void WonderQueue::enqueue(int a_item)
{
    assert( !!! isFull());
    if( !!! m_in.isFull())
    {
        m_in.push(a_item);
    }
    else
    {
        m_out.drain(m_in);
        m_in.push(a_item);
    }
    axioms();
}

int WonderQueue::dequeue()
{
    assert( !!! isEmpty());
    int popItem;
    if( !!! m_out.isEmpty())
    {
        popItem = m_out.pop();
    }
    else
    {
        m_out.drain(m_in);
        popItem = m_out.pop();
    }
    axioms();
    return popItem;
}

size_t WonderQueue::capacity() const
{
    if(m_out.isEmpty())
    {
        return m_capacity*2;
    }
    else
    {
        return m_capacity + m_out.size();
    }
}

size_t WonderQueue::size() const
{
    return m_in.size() + m_out.size();
}

size_t WonderQueue::leftSpese() const
{
    return capacity() - size();
}

bool WonderQueue::isEmpty() const
{
    return m_in.isEmpty() && m_out.isEmpty();
}

bool WonderQueue::isFull() const
{
    return m_in.isFull() && !m_out.isEmpty();
}

void WonderQueue::axioms() const
{
    assert(m_capacity >= 0);
    assert(capacity() <= m_capacity*2);
    assert(capacity() >= m_capacity);
    assert(capacity() - size()  == leftSpese());
}

void WonderQueue::display() const
{
    m_in.dump();
    m_out.dump();
}
