#include "rec.hpp"

namespace breaker
{

Rectangle::Rectangle(size_t a_width, size_t a_length, Color a_color, size_t a_hitLimit, int a_x, int a_y)
: m_width(a_width)
, m_length(a_length)
, m_hitLimit(a_hitLimit)
, m_hitCounter(0)
, m_x(a_x)
, m_y(a_y)
, m_destroy(false)
, m_color(a_color)
, m_size(m_width, m_length)
, m_name(m_size)
{
    m_name.setFillColor(m_color);
    m_name.setPosition(m_x, m_y);
    m_name.setOutlineColor(Color::Black);
    m_name.setOutlineThickness(2);
}

void Rectangle::moveToRight(size_t a_width)
{
    if(m_x + m_width < a_width)
    {
        m_x += 4;
        setPosition(m_x, m_y);
    }
}

void Rectangle::moveToLeft()
{
    if(m_x > 0)
    {
        m_x -= 4;
        setPosition(m_x, m_y);
    }
}

void Rectangle::setPosition(int a_x, int a_y)
{
    m_x = a_x;
    m_y = a_y;
    m_name.setPosition(m_x, m_y);
}

void Rectangle::draw(RenderWindow& a_window)const
{
    a_window.draw(m_name);
}

size_t Rectangle::topCoordinate()const
{
    return m_name.getPosition().y;
}

size_t Rectangle::leftCoordinate()const
{
    return m_name.getPosition().x;
}

size_t Rectangle::rightCoordinate()const
{
    return m_name.getPosition().x + m_name.getGlobalBounds().width;
}

size_t Rectangle::bottomCoordinate()const
{
    return m_name.getPosition().y + m_name.getGlobalBounds().left;
}

void Rectangle::hit()
{
    m_hitCounter += 1;
    if(m_hitCounter == m_hitLimit)
    {
        m_destroy = true;
    }
}

bool Rectangle::operator==(Rectangle const& a_rectangle)const
{
    return (m_x == a_rectangle.m_x) 
        && (m_y == a_rectangle.m_y)
        && (m_color == a_rectangle.m_color) 
        && (m_size == a_rectangle.m_size)
        && (m_hitLimit == a_rectangle.m_hitLimit)
        && (m_hitCounter == a_rectangle.m_hitCounter);
}


}//namespace shape