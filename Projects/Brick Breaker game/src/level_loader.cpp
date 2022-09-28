#include "level_loader.hpp"

namespace breaker
{

namespace impel
{

Color intToColor(string& a_color) 
{
    static Color lut[] = 
    {
        Color::Black, 
        Color::White, 
        Color::Red, 
        Color::Green, 
        Color::Blue, 
        Color::Yellow, 
        Color::Magenta,
        Color::Cyan,
        Color::Transparent
    };

    int color = stoi(a_color);
    if( 0 <= color &&  color <= 9)
    {
        return lut[color];
    }
    return Color::Yellow;
}


}//namespace impel

LevelLoader::LevelLoader(ballPtrVector& a_balls, brickPtrVector& a_bricks)
: m_balls(a_balls)
, m_bricks(a_bricks)
{

}

size_t LevelLoader::loadContainers(int a_level)
{
    string brickFilePath("./resources/" + to_string(a_level) + ".brick");
    ifstream brickFile(brickFilePath);
    readBricksFromeFile(brickFile);

    string ballFilePath("./resources/" + to_string(a_level) + ".ball");
    ifstream ballFile(ballFilePath);
    return readBallsFromeFile(ballFile);
}

size_t LevelLoader::readBallsFromeFile(ifstream &a_file)
{
    string line;
    size_t count = 0;
    while(getline(a_file, line))
    {
        loadBall(line);
        ++count;
    }
    return count;
}

void LevelLoader::readBricksFromeFile(ifstream &a_file)
{
    string line;    
    while(getline(a_file, line))
    {        
        loadBrick(line);     
    }
}

void LevelLoader::loadBall(string& a_line)
{
    size_t begine = 0;
    size_t end = a_line.find(',', begine);
    size_t radius =  stol(a_line.substr(begine, end-begine));

    begine = end + 1;
    end = a_line.find(',', begine);
    string numOfColor = a_line.substr(begine, end-begine);
    Color color = impel::intToColor(numOfColor);

    begine = end + 1;
    end = a_line.find(',', begine);
    int x = stoi(a_line.substr(begine, end-begine));

    begine = end + 1;
    end = a_line.find(',', begine);
    int y = stoi(a_line.substr(begine, end-begine));

    begine = end + 1;
    end = a_line.find(',', begine);
    size_t speed =  stol(a_line.substr(begine, end-begine));

    m_balls.push_back(ballPtr(new Ball(radius, color, x, y, speed)));
}

void LevelLoader::loadBrick(string& a_line)
{
    size_t begine = 0;
    size_t end = a_line.find(',', begine);
    float width = stof(a_line.substr(begine, end-begine));

    begine = end + 1;
    end = a_line.find(',', begine);
    float length = stof(a_line.substr(begine, end-begine));

    begine = end + 1;
    end = a_line.find(',', begine);
    string image = a_line.substr(begine, end-begine);

    begine = end + 1;
    end = a_line.find(',', begine);
    size_t hitLimit =  stol(a_line.substr(begine, end-begine));

    begine = end + 1;
    end = a_line.find(',', begine);
    int x =  stoi(a_line.substr(begine, end-begine));

    begine = end + 1;
    end = a_line.find(',', begine);
    int y =  stoi(a_line.substr(begine, end-begine));

    m_bricks.push_back(brickPtr(new Brick(width, length, image, hitLimit, x, y)));
}


}//namespace breaker