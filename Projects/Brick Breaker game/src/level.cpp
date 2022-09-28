#include "level.hpp"


namespace breaker
{

namespace impel
{

void setBackground(Sprite& a_sprite, Texture& a_texture)
{
    a_texture.loadFromFile("./resources/background.jpg");
    a_sprite.setTexture(a_texture);
    a_sprite.scale(1.045, 1.12);
    a_sprite.setPosition(0 , 0);
}

void setLiveTextStyle(Text& a_text)
{
    a_text.setStyle(Text::Bold);
    a_text.setFillColor(Color::Yellow);
    a_text.setPosition(305, 0);
    a_text.setOutlineColor(Color::Black);
    a_text.setOutlineThickness(2);
}

void setLevelTextStyle(Text& a_text)
{
    a_text.setStyle(Text::Bold);
    a_text.setFillColor(Color::Yellow);
    a_text.setPosition(445, 0);
    a_text.setOutlineColor(Color::Black);
    a_text.setOutlineThickness(2);
}

void setScoreTextStyle(Text& a_text)
{
    a_text.setStyle(Text::Bold);
    a_text.setFillColor(Color::Yellow);
    a_text.setPosition(615, 0);
    a_text.setOutlineColor(Color::Black);
    a_text.setOutlineThickness(2);
}


}//namespace impel

Level::Level(ballPtrVector& a_balls, brickPtrVector& a_bricks, size_t a_width, size_t a_length, size_t a_speed, size_t& a_live, size_t a_level, size_t& a_score)
: m_live(a_live)
, m_level(a_level)
, m_width(a_width)
, m_length(a_length)
, m_score(a_score)
, m_font()
, m_event()
, m_sound()
, m_liveText(setLiveText(), m_font, 30)
, m_levelText(setLevelText(), m_font, 30)
, m_scoreText(setScoreText(), m_font, 30)
, m_buffer()
, m_window(VideoMode(m_width, m_length), "SFML works!")
, m_background()
, m_backgroundTexture()
, m_padel("./resources/padel.jpg", 0.125, 0.035, 520, 565)
, m_liveImage(12, Color::Yellow, 275, 7)
, m_balls(a_balls)
, m_bricks(a_bricks)
{
    m_window.setFramerateLimit(a_speed);
    m_font.loadFromFile("./resources/arial.ttf");
    setStyle();
}

bool Level::fail()const
{
    if(m_balls.size() == 0)
    {
        return true;
    }
    return false;
}

bool Level::succeeded()const
{
    if(m_bricks.size() == 0)
    {
        return true;
    }
    return false;
}

void Level::checkKeyboard()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        m_padel.moveToLeft();
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        m_padel.moveToRight(m_width);
    }

    if (Keyboard::isKeyPressed(Keyboard::N))
    {
        size_t size = m_bricks.size();
        for(size_t i = 0; i < size; ++i)
        {
            m_bricks.pop_back();
        }
    }
}

bool Level::checkBricksDestroy()
{
    size_t itPos = 0;
    bool destroy = false;
    size_t size = m_bricks.size();
    for(size_t i = 0; i < size; ++i)
    {
        if(m_bricks[i]->m_destroy)
        {
            m_score += m_bricks[i]->m_hitLimit;
            auto it = m_bricks.begin() + itPos;
            m_bricks.erase(it);
            destroy = true;
            --size;
        }
        ++itPos;
    }
    return destroy;
}

bool Level::checkBallsDestroy()
{
    size_t itPos = 0;
    bool ballFell = false;
    size_t size = m_balls.size();
    for(size_t i = 0; i < size; ++i)
    {
        if(m_balls[i]->m_destroy)
        {
            if(size > 1 || m_live < 2)
            {
                auto it = m_balls.begin() + itPos;
                m_balls.erase(it);
                --size;
            }
            else
            {
                m_balls[i]->m_destroy = false;
                m_balls[i]->m_Ydirection *= -1;
                m_balls[i]->setPosition(350, 520);
                sleep(2);
            }
            --m_live;
            ballFell = true;
        }
        ++itPos;
    }
    return ballFell;
}

void Level::playFail()
{
    m_buffer.loadFromFile("./resources/mixkit-player-losing-or-failing-2042.wav");
    m_sound.setBuffer(m_buffer);
    m_sound.play();
}

void Level::playSucceeded()
{
    m_buffer.loadFromFile("./resources/mixkit-video-game-win-2016.wav");
    m_sound.setBuffer(m_buffer);
    m_sound.play();
}

void Level::playBackground()
{
    m_buffer.loadFromFile("./resources/mixkit-game-level-music-689.wav");
    m_sound.setBuffer(m_buffer);
    m_sound.play();
}

string Level::setLevelText()
{
    string level = to_string(m_level);
    string levelText("Level "  + level);
    return levelText;
}

string Level::setLiveText()
{
    string live = to_string(m_live);
    string liveText("x"  + live);
    return liveText;
}

string Level::setScoreText()
{
    string score = to_string(m_score);
    string scoreText("Score "  + score);
    return scoreText;
}

void Level::setStyle()
{
    impel::setBackground(m_background, m_backgroundTexture);
    impel::setLiveTextStyle(m_liveText);
    impel::setLevelTextStyle(m_levelText);
    impel::setScoreTextStyle(m_scoreText);
}

void Level::checkWindow()
{
    m_window.pollEvent(m_event);
    if (m_event.type == Event::Closed)
    {
        m_live = 0;
        m_window.close();
    }
}

void Level::drawAll()
{
    m_window.draw(m_background);
    m_window.draw(m_levelText);
    m_window.draw(m_scoreText);
    m_liveImage.draw(m_window);
    m_padel.draw(m_window);
    m_window.draw(m_liveText);

    for(auto& e: m_bricks)
    {
        e->draw(m_window);
    }

    for(auto& e: m_balls)
    {
        e->draw(m_window);
    }
}

void Level::run()
{
    while (m_window.isOpen() && !fail() && !succeeded())
    {
        checkWindow();
        
        if(checkBricksDestroy())
            m_scoreText.setString(setScoreText());

        if(checkBallsDestroy())
            m_liveText.setString(setLiveText());

        for(auto& e: m_balls)
        {
            Collision(e, m_padel, m_balls, m_bricks, m_width, m_length);
            e->MoveBall();
        }

        drawAll();
        checkKeyboard();     
        m_window.display();
    }

    if(fail()){playFail(); sleep(2);}
    if(succeeded()){playSucceeded(); sleep(2);}
}


}//namespace breaker