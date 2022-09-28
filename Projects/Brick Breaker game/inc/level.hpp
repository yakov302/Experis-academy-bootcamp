#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <string.h>

#include "ball.hpp"
#include "rec.hpp"
#include "padel.hpp"
#include "collision.hpp"

namespace breaker
{

using namespace sf;
using namespace std;
using ballPtrVector = std::vector<std::unique_ptr<breaker::Ball>>;
using brickPtrVector = std::vector<std::unique_ptr<breaker::Brick>>;

class Level
{
public:
   Level(ballPtrVector& a_balls, brickPtrVector& a_bricks, size_t a_width, size_t a_length, size_t a_speed, size_t& a_live, size_t a_level, size_t& a_score);
   void run();

private:
    void playFail();
    void playSucceeded();
    void playBackground();
    void checkKeyboard();
    void checkWindow();
    void setStyle();
    void drawAll();

    string setLiveText();
    string setLevelText();
    string setScoreText ();
    
    bool fail()const; 
    bool succeeded()const;
    bool checkBallsDestroy();
    bool checkBricksDestroy();

private:
    size_t& m_live;
    size_t m_level;
    size_t m_width;
    size_t m_length;
    size_t& m_score;

    Font m_font;
    Event m_event;
    Sound m_sound;
    Text m_liveText;
    Text m_levelText;
    Text m_scoreText;
    SoundBuffer m_buffer;
    RenderWindow m_window;
    Sprite m_background;
    Texture m_backgroundTexture;

    Padel m_padel;
    Ball m_liveImage;
    ballPtrVector& m_balls;
    brickPtrVector& m_bricks;
};


}//namespace breaker
