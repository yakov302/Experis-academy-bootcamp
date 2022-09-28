#include "collision.hpp"

namespace breaker
{

Collision::Collision(ballPtr& a_ball, Padel& a_padel, ballPtrVector& a_balls, brickPtrVector& a_bricks, size_t a_width, size_t a_length)
: m_width(a_width)
, m_length(a_length)
, m_ball(a_ball)
, m_padel(a_padel)
, m_balls(a_balls)
, m_bricks(a_bricks)
{
    checkBallsCollision();
    checkPadelCollision();
    checkBricksCollision();
    checkWallsCollision();
}

void Collision::checkWallsCollision()
{
    avoidRightAndLeftWallCollision();
    avoidTopAndBottomCollision();
}

void Collision::avoidRightAndLeftWallCollision()
{
    if (m_ball->m_x >= (int)(m_width - m_ball->m_radius * 2) || m_ball->m_x <= 0)
    {
        if(m_ball->m_x > (int)(m_width - m_ball->m_radius * 2))
        {
            pullOutFromeRightWall();
        }
        else if(m_ball->m_x < 0)
        {
            pullOutFromeLeftWall();
        }
        m_ball->m_Xdirection *= -1;
    }
}

void Collision::avoidTopAndBottomCollision()
{
    if (m_ball->m_y <= 0)
    {
        if(m_ball->m_y < 0)
        {
            pullOutFromeTopWall();
        }
        m_ball->m_Ydirection *= -1;
    }
    else if (m_ball->m_y >= (int)(m_length - m_ball->m_radius * 2))
    {
       m_ball->setPosition(1500, 900);
       m_ball->playFall();
       m_ball->m_destroy = true;
    }
}

void Collision::pullOutFromeRightWall()
{
    while(m_ball->m_x > (int)(m_width - m_ball->m_radius * 2))
    {
        --m_ball->m_x;
    }
}

void Collision::pullOutFromeLeftWall()
{
    while(m_ball->m_x < 0)
    {
        ++m_ball->m_x;
    }
}

void Collision::pullOutFromeTopWall()
{
    while(m_ball->m_y < 0)
    {
        ++m_ball->m_y;
    }
}

void Collision::checkBallsCollision()
{
    for (auto &e : m_balls)
    {
        if (*m_ball == *e){}
        else
        {
            avoidBallCollision(*e);
        }
    }
}

void Collision::avoidBallCollision(Ball &a_ball)
{
    float dx = m_ball->m_x - a_ball.m_x;
    float dy = m_ball->m_y - a_ball.m_y;
    float distance = std::sqrt((dx * dx) + (dy * dy));
    if (distance <= m_ball->m_radius + a_ball.m_radius)
    {
        m_ball->m_Xdirection *= -1;
        m_ball->m_Ydirection *= -1;

        if(distance < m_ball->m_radius + a_ball.m_radius)
        {
            pullOutFromeBall(a_ball);
        }
    }
}

void Collision::pullOutFromeBall(Ball &a_ball)
{
    float dx = m_ball->m_x - a_ball.m_x;
    float dy = m_ball->m_y - a_ball.m_y;
    float distance = std::sqrt((dx * dx) + (dy * dy));

    while(distance < m_ball->m_radius)
    {
        ++m_ball->m_x;
        ++m_ball->m_y;;
    }
}

void Collision::checkBricksCollision()
{
    for (auto& r : m_bricks)
    {
        avoidBricksCollision(r);
    }
}

void Collision::avoidBricksCollision(brickPtr& a_brick)
{
    if (m_ball->m_x <= (int)a_brick->rightCoordinate()
    && m_ball->m_x >= (int)(a_brick->leftCoordinate() - 2 * m_ball->m_radius)
    && m_ball->m_y >= (int)(a_brick->topCoordinate() - 2 * m_ball->m_radius)
    && m_ball->m_y <= (int)a_brick->bottomCoordinate())
    {
        m_ball->playBrickHit();
        a_brick->hit();

        if (m_ball->m_x < (int)a_brick->rightCoordinate()
        && m_ball->m_x > (int)(a_brick->leftCoordinate() - 2 * m_ball->m_radius)
        && m_ball->m_y > (int)(a_brick->topCoordinate() - 2 * m_ball->m_radius)
        && m_ball->m_y < (int)a_brick->bottomCoordinate())
        { 
            pullOutFromeBrick(a_brick);
        }
        m_ball->m_Ydirection *= -1;
    }
}

void Collision::pullOutFromeBrick(brickPtr& a_brick)
{
    int xr = a_brick->rightCoordinate() - m_ball->m_x;
    int xl = m_ball->m_x - (int)(a_brick->leftCoordinate() - 2 * m_ball->m_radius);
    int yt = m_ball->m_y - (int)(a_brick->topCoordinate() - 2 * m_ball->m_radius);
    int yb = (int)a_brick->bottomCoordinate() - m_ball->m_y;

    if(xr <= xl && xr <= yt && xr <= yb)
    {
        pullOutFromeRightBrick(a_brick);
    }
    else if (xl <= xr && xl <= yt && xl <= yb)
    {
        pullOutFromeLeftBrick(a_brick);
    }
    else if (yt <= xr && yt <= xl && yt <= yb)
    { 
        pullOutFromeTopBrick(a_brick);
    }
    else if (yb <= xr && yb <= xl && yb <= yt)
    {
        pullOutFromeBottomBrick(a_brick);
    }
}

void Collision::pullOutFromeTopBrick(brickPtr& a_brick)
{
    while (m_ball->m_y > (int)((a_brick->topCoordinate() - 2 * m_ball->m_radius)))
    {
        --m_ball->m_y;
    }
}

void Collision::pullOutFromeBottomBrick(brickPtr& a_brick)
{
    while (m_ball->m_y < (int)a_brick->bottomCoordinate())
    {
        ++m_ball->m_y;
    }
}

void Collision::pullOutFromeLeftBrick(brickPtr& a_brick)
{
    while (m_ball->m_x > (int)(a_brick->leftCoordinate() - 2 * m_ball->m_radius))
    {
        --m_ball->m_x;
    }
}

void Collision::pullOutFromeRightBrick(brickPtr& a_brick)
{
    while (m_ball->m_x < (int)a_brick->rightCoordinate())
    {
            ++m_ball->m_x;
    }
}

void Collision::checkPadelCollision()
{
    if (m_ball->m_x <= (int)m_padel.rightCoordinate()
    && m_ball->m_x >= (int)(m_padel.leftCoordinate() - 2 * m_ball->m_radius)
    && m_ball->m_y >= (int)(m_padel.topCoordinate() - 2 * m_ball->m_radius)
    && m_ball->m_y <= (int)m_padel.bottomCoordinate())
    {
        m_ball->playBrickHit();

        if (m_ball->m_x < (int)m_padel.rightCoordinate()
        && m_ball->m_x > (int)(m_padel.leftCoordinate() - 2 * m_ball->m_radius)
        && m_ball->m_y > (int)(m_padel.topCoordinate() - 2 * m_ball->m_radius)
        && m_ball->m_y < (int)m_padel.bottomCoordinate())
        { 
            pullOutFromePadel();
        }
        m_ball->m_Ydirection *= -1;
    }
}

void Collision::pullOutFromePadel()
{
    while (m_ball->m_y > (int)(m_padel.topCoordinate() - 2 * m_ball->m_radius))
    {
        --m_ball->m_y;
    } 
}


}//namespace breaker