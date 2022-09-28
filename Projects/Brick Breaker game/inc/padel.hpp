#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <string>
#include <cmath>

#include "rec.hpp"

namespace breaker
{

using namespace sf;
using namespace std;

class Padel : public Rectangle
{
public:
    Padel(string a_image, float a_width = 1, float a_length = 1, int a_x = 0, int a_y = 0);

    void moveToLeft();
    void moveToRight(size_t a_width);
    void setPosition(int a_x, int a_y);
    void draw(RenderWindow& a_window)const;

    size_t topCoordinate()const; 
    size_t leftCoordinate()const;
    size_t rightCoordinate()const;
    size_t bottomCoordinate()const;

    bool operator==(Padel const& a_rectangle)const;

private:
    float m_width; 
    float m_length;
    float m_x;
    float m_y;

    Sprite m_name;
    Texture m_texture;
};


}//namespace shape