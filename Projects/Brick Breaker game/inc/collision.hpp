#include "ball.hpp"
#include "padel.hpp"
#include "brick.hpp"

namespace breaker
{

using ballPtr = std::unique_ptr<breaker::Ball>;
using brickPtr = std::unique_ptr<breaker::Brick>;
using ballPtrVector = std::vector<std::unique_ptr<breaker::Ball>>;
using brickPtrVector = std::vector<std::unique_ptr<breaker::Brick>>;

class Collision
{
public:
    Collision(ballPtr& a_ball, Padel& a_padel, ballPtrVector& a_balls, brickPtrVector& a_bricks, size_t a_width, size_t a_length);

private:
    void checkPadelCollision();
    void checkWallsCollision();
    void checkBallsCollision();
    void checkBricksCollision();

    void pullOutFromeTopBrick(brickPtr& a_brick);
    void pullOutFromeBottomBrick(brickPtr& a_brick);
    void pullOutFromeLeftBrick(brickPtr& a_brick);
    void pullOutFromeRightBrick(brickPtr& a_brick);

    void pullOutFromePadel();
    void pullOutFromeTopWall();
    void pullOutFromeLeftWall();
    void pullOutFromeRightWall();
    void pullOutFromeBrick(brickPtr& a_brick);
    void pullOutFromeBall(Ball& a_ball);

    void avoidRightAndLeftWallCollision();
    void avoidTopAndBottomCollision();
    void avoidBallCollision(Ball& a_ball);
    void avoidBricksCollision(brickPtr& a_brick);

private:
    size_t m_width;
    size_t m_length;

    ballPtr& m_ball;
    Padel& m_padel;
    ballPtrVector& m_balls;
    brickPtrVector& m_bricks;
};


}//namespace breaker
