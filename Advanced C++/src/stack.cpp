#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include "stack.hpp"
#include "utils.hpp"

Stack::Stack(size_t a_capacity)
: m_elements(new int[a_capacity])
, m_tos(0)
, m_capacity(a_capacity)
{
    assert(a_capacity >= 0);
    axioms();
}

Stack::Stack(int *a_arr, size_t a_capacity)
: m_elements(new int[a_capacity])
, m_tos(0)
, m_capacity(a_capacity)
{
    push(a_arr, a_capacity);
    axioms();
}

Stack::Stack(int *a_arr, size_t a_numOfPush, size_t a_capacity)
: m_elements(new int[a_capacity])
, m_tos(0)
, m_capacity(a_capacity)
{
    push(a_arr, a_numOfPush);
    axioms();
}

 Stack::Stack(Stack const& source)
: m_elements(new int[source.m_capacity])
, m_tos(source.m_tos)
, m_capacity(source.m_capacity)
 {
       memcpy(m_elements, source.m_elements, sizeof(int)*source.m_tos); 
 }

Stack& Stack::operator=(Stack const& source)
{
    m_tos = source.m_tos;
    m_capacity = source.m_capacity;
    int* newArr = new int[m_capacity];
    memcpy(newArr, source.m_elements, sizeof(int)*source.m_tos); 
    delete[]m_elements;
    m_elements = newArr;
    return *this;
}

Stack::~Stack()
{
    delete[] m_elements;
    axioms();
}

void Stack::empty()
{
    m_tos = 0;
    axioms();
}

int Stack::pop()
{
    assert(!isEmpty());
    int result = m_elements[--m_tos];
    axioms();
    return result;
}

size_t Stack::pop(int *a_arr, size_t a_numOfPop)
{
    size_t i;
    for (i = 0; i < a_numOfPop && !isEmpty(); i++)
    {
        a_arr[i] = pop();
    }
    return i;
    axioms();
}

void Stack::push(int a_item)
{
    assert(!isFull());
    m_elements[m_tos++] = a_item;
    axioms();
}

size_t Stack::push(int* a_arr, size_t a_numOfPush)
{
    assert(a_arr != 0);
    int numOfPush = minInt(a_numOfPush ,m_capacity - m_tos);
    memcpy(m_elements + m_tos , a_arr , numOfPush * sizeof(m_elements[0]));
    m_tos += numOfPush;
    axioms();
    return numOfPush;
}

void Stack::ensureCapacity(size_t a_capacity)
{
    if(getCapacity() >= a_capacity)
    {return;}
    int* newArr = new int[a_capacity];
    memcpy(newArr, m_elements, sizeof(m_elements[0])*m_tos);
    delete[]m_elements;
    m_elements = newArr;
    m_capacity = a_capacity;
    axioms();
}  

size_t Stack::size() const
{
    return m_tos;
}

int Stack::top()const
{
    assert(!isEmpty());
    return  m_elements[m_tos -1];
}

size_t Stack::getCapacity() const
{
    return m_capacity;
}

bool Stack::isEmpty() const
{
    return m_tos == 0;
}

bool Stack::isFull() const
{
    return m_tos == m_capacity;
}

void Stack::dump() const
{
    printf("tos: %d,  cap: %d\n", m_tos, m_capacity);
    dumpElements();
    printf("\n");
}

void Stack::dumpElements() const
{
    for (int i = 0; i < m_tos; i++)
    {
        printf("%d ", m_elements[i]);
    }
}

void Stack::axioms() const
{
    assert(m_tos >= 0 && m_tos <= m_capacity);
    assert(m_capacity >= 0 && m_capacity <= 100000000);
    assert(m_elements != 0);
}

void combine(Stack& a_first, Stack& a_second, Stack& a_result)
{
    a_result.drain(a_first);
    a_result.drain(a_second);
}

void Stack::drain(Stack& a_stack)
{
    while(!a_stack.isEmpty() && !isFull())
    {
       push(a_stack.pop());
    }
    axioms();
}

