#pragma once

#include <fstream>
#include <string>

#include "ball.hpp"
#include "rec.hpp"
#include "brick.hpp"

namespace breaker
{

using ballPtr = std::unique_ptr<breaker::Ball>;
using brickPtr = std::unique_ptr<breaker::Brick>;
using ballPtrVector = std::vector<std::unique_ptr<breaker::Ball>>;
using brickPtrVector = std::vector<std::unique_ptr<breaker::Brick>>;
using namespace std;

class LevelLoader
{
public:
   LevelLoader(ballPtrVector& a_balls, brickPtrVector& m_bricks);
   size_t loadContainers(int a_level);

private:
    void loadBall(string& a_line);
    void loadBrick(string& a_line);
    size_t readBallsFromeFile(ifstream &a_file);
    void readBricksFromeFile(ifstream &a_file);

private:
    ballPtrVector& m_balls;
    brickPtrVector& m_bricks;
};


}//namespace breaker
