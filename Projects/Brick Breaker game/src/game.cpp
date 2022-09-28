#include "game.hpp"

namespace breaker
{

Game::Game(size_t a_numOfLevels)
: m_live(2)
, m_level(1)
, m_score(0)
, m_numOfLevels(a_numOfLevels)
, m_speed()
, m_balls()
, m_bricks()
{
    setSpeed();
    m_balls.reserve(10);
    m_bricks.reserve(150);
}

void Game::setSpeed()
{
    for(size_t i = 0; i <= m_numOfLevels; ++i)
    {
        m_speed.push_back(200);
    }
}

void Game::run()
{ 
    while(end())
    {
        m_balls.clear();
        m_bricks.clear();
        LevelLoader loader(m_balls, m_bricks);
        m_live += loader.loadContainers(m_level);
        Level level (m_balls, m_bricks, 1000, 600, m_speed[m_level] ,m_live, m_level, m_score);
        level.run();
        if(m_live > 0)
        {
            ++m_level;
        }
    }
}

bool Game::end()
{
    if(m_live == 0 || m_level > m_numOfLevels)
    {
        gameOverScreen();
        return false;
    }
    return true;
}

void Game::gameOverScreen()
{
    RenderWindow window(VideoMode(1000, 600), "SFML works!");
    window.clear();
    Sprite gameOver;
    Texture texture;
    texture.loadFromFile("./resources/gameOver.jpg");
    gameOver.setTexture(texture);
    gameOver.scale(0.5, 0.5);
    gameOver.setPosition(300 , 150);
    window.draw(gameOver);  
    window.display();
    usleep(500000);
    window.close();
}


}//namespace breaker