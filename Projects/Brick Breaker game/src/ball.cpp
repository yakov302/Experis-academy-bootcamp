#include "ball.hpp"

namespace breaker
{

Ball::Ball(size_t a_radius, Color a_color, int a_x, int a_y, size_t a_speed)
: m_x(a_x)
, m_y(a_y)
, m_Xdirection(1)
, m_Ydirection(-1)
, m_destroy(false)
, m_speed(a_speed)
, m_radius(a_radius)
, m_color(a_color)
, m_sound()
, m_texture(new Texture)
, m_name(m_radius)
, m_buffer()
{
    m_name.setPosition(m_x, m_y);
    m_name.setOutlineColor(Color::Black);
    m_name.setOutlineThickness(2);
    (*m_texture).loadFromFile("./resources/gold.png");
    m_name.setTexture(m_texture);
}

Ball::~Ball()
{
    delete m_texture;
}

void Ball::MoveBall()
{
    m_x += m_Xdirection * m_speed;
    m_y += m_Ydirection * m_speed;
    setPosition(m_x, m_y);
}

void Ball::setPosition(int a_x, int a_y)
{
    m_x = a_x;
    m_y = a_y;
    m_name.setPosition(m_x, m_y);
}

void Ball::draw(RenderWindow &a_window) const
{
    a_window.draw(m_name);
}

void Ball::playFall()
{
    m_buffer.loadFromFile("./resources/mixkit-retro-arcade-game-over-470.wav");
    m_sound.setBuffer(m_buffer);
    m_sound.play();
}

void Ball::playBrickHit()
{
    m_buffer.loadFromFile("./resources/mixkit-retro-game-notification-212.wav");
    m_sound.setBuffer(m_buffer);
    m_sound.play();
}

bool Ball::operator==(Ball const &a_balls) const
{
    return (m_x == a_balls.m_x) && (m_y == a_balls.m_y) && (m_color == a_balls.m_color) && (m_radius == a_balls.m_radius) && (m_speed == a_balls.m_speed) && (m_Xdirection == a_balls.m_Xdirection) && (m_Ydirection == a_balls.m_Ydirection);
}

bool const Ball::operator<(Ball const &a_balls) const
{
    return (m_radius < a_balls.m_radius) || (m_x < a_balls.m_x);
}


} // namespace shape