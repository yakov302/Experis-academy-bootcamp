#pragma once

#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <memory>

#include "level.hpp"
#include "level_loader.hpp"
#include "brick.hpp"

namespace breaker
{

using speedVector = std::vector<size_t>;
using ballPtrVector = std::vector<std::unique_ptr<breaker::Ball>>;
using brickPtrVector = std::vector<std::unique_ptr<breaker::Brick>>;

class Game
{
public:
   Game(size_t a_numOfLevels);
   void run();

private:
    bool end();
    void setSpeed();
    void gameOverScreen();

private:
    size_t m_live;
    size_t m_level;
    size_t m_score;
    size_t m_numOfLevels;
    speedVector m_speed;
    ballPtrVector m_balls;
    brickPtrVector m_bricks;
};


}//namespace breaker
