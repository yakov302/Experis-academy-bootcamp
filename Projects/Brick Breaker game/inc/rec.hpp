#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <string>
#include <cmath>

#include "shape.hpp"

namespace breaker 
{

using namespace sf;

class Rectangle : public Shape
{
public:
    Rectangle(size_t a_width, size_t a_length, Color a_color, size_t a_hitLimit = 1, int a_x = 0, int a_y = 0);
    Rectangle() = default;

    virtual void hit();
    virtual void moveToLeft();
    virtual void moveToRight(size_t a_width);
    virtual void setPosition(int a_x, int a_y);

    virtual size_t topCoordinate()const;
    virtual size_t leftCoordinate()const;
    virtual size_t rightCoordinate()const;
    virtual size_t bottomCoordinate()const;

    virtual void draw(RenderWindow& a_window)const;
    bool operator==(Rectangle const& a_rectangle)const;

private:
    size_t m_width; 
    size_t m_length;
    size_t m_hitLimit;
    size_t m_hitCounter;

    float m_x;
    float m_y;
    bool m_destroy;

    Color m_color;
    Vector2f m_size;
    RectangleShape m_name;
};


}//namespace shape