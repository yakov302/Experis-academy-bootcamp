#ifndef BALL_H
#define BALL_H

#include <cstddef>
#include <ostream>

namespace cpp
{

class Ball
{
public:
    explicit Ball(char a_color = 'w', int a_radius = 1);
    int getRadius()const;
    void setRadius(int a_radius);
    void swap(Ball& a_ball);

private:
    char m_color;
    int m_radius;
};

void swap(Ball& a, Ball& b);

bool operator==(Ball const& a_first, Ball const& a_second);
bool operator!=(Ball const& a_first, Ball const& a_second);
bool operator<(Ball const& a_first, Ball const& a_second);
bool operator>(Ball const& a_first, Ball const& a_second);
bool operator>=(Ball const& a_first, Ball const& a_second);
bool operator<=(Ball const& a_first, Ball const& a_second);

std::ostream& operator<<(std::ostream& a_ostream, Ball const& a_ball);



} //cpp namespace

#endif /*#ifndefBALL_H122*/