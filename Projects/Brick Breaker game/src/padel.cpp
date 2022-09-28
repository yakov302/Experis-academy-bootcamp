#include "padel.hpp"

namespace breaker
{

Padel::Padel(string a_image, float a_width, float a_length , int a_x, int a_y)
: m_width(a_width)
, m_length(a_length)
, m_x(a_x)
, m_y(a_y)
, m_name()
, m_texture()
{
    m_texture.loadFromFile(a_image);
    m_name.setTexture(m_texture);
    m_name.scale(a_width, a_length);
    m_name.setPosition(a_x , a_y);
}

void Padel::moveToLeft()
{
    if(m_x > 0)
    {
        m_x -= 4;
        setPosition(m_x, m_y);
    }
}

void Padel::moveToRight(size_t a_width)
{
    if(m_x +  m_name.getGlobalBounds().width < a_width)
    {
        m_x += 4;
        setPosition(m_x, m_y);
    }
}

size_t Padel::topCoordinate()const
{
    return m_name.getPosition().y;
}

size_t Padel::leftCoordinate()const
{
    return m_name.getPosition().x;
}

size_t Padel::rightCoordinate()const
{
    return m_name.getPosition().x + m_name.getGlobalBounds().width;
}

size_t Padel::bottomCoordinate()const
{
    return m_name.getPosition().y + m_name.getGlobalBounds().left;
}

void Padel::draw(RenderWindow& a_window)const
{
    a_window.draw(m_name);
}

bool Padel::operator==(Padel const& a_padel)const
{
    return (m_width == a_padel.m_width) 
    && (m_length == a_padel.m_length)
    && (m_y == a_padel.m_x) 
    && (m_x == a_padel.m_y);  
}

void Padel::setPosition(int a_x, int a_y)
{
    m_x = a_x;
    m_y = a_y;
    m_name.setPosition(m_x , m_y);
}


}//namespace shape