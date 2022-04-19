#include <cstddef>
#include <ostream>
#include "ball.hpp"
#include <algorithm>
#include <iostream>

namespace cpp
{

Ball::Ball(char a_color, int a_radius)
: m_color(a_color)
, m_radius(a_radius)
{

}

int Ball::getRadius()const
{
    return m_radius;
}

void Ball::setRadius(int a_radius)
{
    m_radius = a_radius;
}

void Ball::swap(Ball& a_ball)
{
	using std::swap;
	swap(this->m_color, a_ball.m_color);
	swap(this->m_radius, a_ball.m_radius);
}

void swap(Ball& a, Ball& b)
{
    a.swap(b);
}

bool operator==(Ball const& a_first, Ball const& a_second)
{
	return a_first.getRadius() == a_second.getRadius();
}

bool operator!=(Ball const& a_first, Ball const& a_second)
{
	return !(a_first == a_second);
}

bool operator<(Ball const& a_first, Ball const& a_second)
{
    return a_first.getRadius() - a_second.getRadius() < 0;
}

bool operator>(Ball const& a_first, Ball const& a_second)
{
	return !(a_first < a_second);
}

bool operator>=(Ball const& a_first, Ball const& a_second)
{
	return (a_first > a_second) || (a_first == a_second);
}

bool operator<=(Ball const& a_first, Ball const& a_second)
{
	return (a_first < a_second) || (a_first == a_second);
}

std::ostream& operator<<(std::ostream& a_ostream, Ball const& a_ball)
{
	return std::cout << a_ball.getRadius();
}


} //cpp namespace
