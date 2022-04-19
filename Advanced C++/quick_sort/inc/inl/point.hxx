#ifndef POINT_HXX
#define POINT_HXX

#include <cassert>
#include <iostream>
#include <cmath>

namespace cpp
{

template <typename T>
Point<T>::Point(T x, T y)
: m_x(x)
, m_y(y)
{

}

template <typename T>
void Point<T>::setPoint(T x, T y)
{
    m_x = x;
    m_y = y;
}

template <typename T>
T Point<T>::getX()const
{
    return m_x;
}

template <typename T>
T Point<T>::getY()const
{
    return m_y;
}

template <typename T>
T Point<T>::getDistance()const
{
    return sqrt(m_x*m_x + m_y*m_y);
}

template <typename T>
void Point<T>::swap(Point& a_point)
{
	using std::swap;
	swap(this->m_x, a_point.m_x);
	swap(this->m_y, a_point.m_y);
}

template <typename T>
void swap(Point<T>& a, Point<T>& b)
{
    a.swap(b);
}

template <typename T>
bool operator==(Point<T> const& a_first, Point<T> const& a_second)
{
    return a_first.getDistance() == a_second.getDistance();
}

template <typename T>
bool operator!=(Point<T> const& a_first, Point<T> const& a_second)
{
    return !(a_first == a_second);
}

template <typename T>
bool operator<(Point<T> const& a_first, Point<T> const& a_second)
{
    return a_first.getDistance() - a_second.getDistance() < 0;
}

template <typename T>
bool operator>(Point<T> const& a_first, Point<T> const& a_second)
{
	return !(a_first < a_second);
}

template <typename T>
bool operator>=(Point<T> const& a_first, Point<T> const& a_second)
{
	return (a_first > a_second) || (a_first == a_second);
}

template <typename T>
bool operator<=(Point<T> const& a_first, Point<T> const& a_second)
{
	return (a_first < a_second) || (a_first == a_second);
}


} //cpp namespace

#endif // POINT_HXX