#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <algorithm>
#include <utility>
#include <unistd.h>
#include <string>
#include <cmath>

#include "rec.hpp"
#include "padel.hpp"
#include "brick.hpp"

namespace breaker
{

using namespace sf;

class Ball : public Shape
{
public:
    friend class Level;
    friend class Collision;

    Ball(size_t a_radius, Color a_color,  int a_x = 0, int a_y = 0, size_t a_speed = 1);
    ~Ball();

    void MoveBall();
    void setPosition(int a_x, int a_y);
    void draw(RenderWindow& a_window)const;

    bool operator==(Ball const& a_balls)const;
    bool const operator<(Ball const& a_balls)const;

private:
    void playFall();
    void playBrickHit();

private:
    int m_x;
    int m_y;
    int m_Xdirection;
    int m_Ydirection;

    bool m_destroy;
    size_t m_speed;
    size_t m_radius;

    Color m_color;
    Sound m_sound;
    Texture* m_texture;
    CircleShape m_name;
    SoundBuffer m_buffer;
};


}//namespace breaker