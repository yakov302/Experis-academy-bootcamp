#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <string>
#include <cmath>

#include "rec.hpp"

namespace breaker
{

using  namespace std;
using  namespace sf;

class Brick : public Rectangle
{
public:
    friend class Level;
  
    Brick(float a_width, float a_length, string a_image, size_t a_hitLimit = 1, int a_x = 0, int a_y = 0);

    void hit();
    void moveToLeft();
    void moveToRight(size_t a_width);
    void setPosition(int a_x, int a_y);
    void draw(RenderWindow& a_window)const;

    size_t topCoordinate()const;
    size_t leftCoordinate()const;
    size_t rightCoordinate()const;
    size_t bottomCoordinate()const;

    bool operator==(Brick const& a_brick)const;

private:
    float m_width; 
    float m_length;
    size_t m_hitLimit;
    size_t m_hitCounter;

    float m_x;
    float m_y;
    bool m_destroy;

    Sprite m_name;
    Texture m_texture;
};


}//namespace shape