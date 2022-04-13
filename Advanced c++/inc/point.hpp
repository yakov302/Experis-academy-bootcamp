#ifndef POINT_H
#define POINT_H

#include <cstddef>

namespace cpp
{

template <typename T>
class Point
{
public:
    explicit Point(T x = 0, T y = 0);
    void setPoint(T x, T y);
    T getX()const;
    T getY()const;
    T getDistance()const;
    void swap(Point& a_point);

private:
    T m_x;
    T m_y;
};

template <typename T>
void swap(Point<T>& a, Point<T>& b);

template <typename T>
bool operator==(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator!=(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator<(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator>(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator>=(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator<=(Point<T> const& a_first, Point<T> const& a_second);


} //cpp namespace

#include "./inl/point.hxx"

#endif /*#ifndefPOINT_H122*/