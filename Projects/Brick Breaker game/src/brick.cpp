#include "brick.hpp"

namespace breaker
{

Brick::Brick(float a_width, float a_length, string a_image, size_t a_hitLimit, int a_x, int a_y)
: m_width(a_width)
, m_length(a_length)
, m_hitLimit(a_hitLimit)
, m_hitCounter(0)
, m_x(a_x)
, m_y(a_y)
, m_destroy(false)
, m_name()
, m_texture()
{
    m_texture.loadFromFile(a_image);
    m_name.setTexture(m_texture);
    m_name.scale(a_width, a_length);
    m_name.setPosition(a_x , a_y);
}

void Brick::moveToRight(size_t a_width)
{
    if(m_x +  m_name.getGlobalBounds().width < a_width)
    {
        m_x += 4;
        setPosition(m_x, m_y);
    }
}

void Brick::moveToLeft()
{
    if(m_x > 0)
    {
        m_x -= 4;
        setPosition(m_x, m_y);
    }
}

void Brick::setPosition(int a_x, int a_y)
{
    m_x = a_x;
    m_y = a_y;
    m_name.setPosition(m_x, m_y);
}

void Brick::draw(RenderWindow& a_window)const
{
    a_window.draw(m_name);
}

size_t Brick::rightCoordinate()const
{
    return m_name.getPosition().x + m_name.getGlobalBounds().width;
}

size_t Brick::leftCoordinate()const
{
    return m_name.getPosition().x;
}

size_t Brick::topCoordinate()const
{
    return m_name.getPosition().y;
}

size_t Brick::bottomCoordinate()const
{
    return m_name.getPosition().y + m_name.getGlobalBounds().height;
}

void Brick::hit()
{
    m_hitCounter += 1;
    if(m_hitCounter == m_hitLimit)
    {
        m_destroy = true;
    }
}

bool Brick::operator==(Brick const& a_brick)const
{
    return (m_x == a_brick.m_x) 
        && (m_y == a_brick.m_y)
        && (m_hitLimit == a_brick.m_hitLimit)
        && (m_hitCounter == a_brick.m_hitCounter)
        && (m_width == a_brick.m_width)
        && (m_length == a_brick.m_length)
        && (m_destroy == a_brick.m_destroy);
}


}//namespace shape