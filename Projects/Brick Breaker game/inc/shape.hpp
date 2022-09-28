#include <SFML/Graphics.hpp>

namespace breaker
{

using namespace sf;

class Shape
{
public:
    Shape() = default;
    virtual ~Shape() = default;
    Shape& operator=(Shape const& a_shape) = delete;
    Shape(Shape const& a_shaper) = delete;

    virtual void setPosition(int a_x, int a_y) = 0;
    virtual void draw(RenderWindow& a_window)const = 0;
};


}//namespace shape
