#include <iostream>
#include <SFML/Graphics.hpp>

static sf::Vector2f dirleft = {-1.0, 0.0};
static sf::Vector2f dirright = {1.0, 0.0};
static sf::Vector2f dirUpLeft = {-1.0 / sqrt(2), -1.0 / sqrt(2)};
static sf::Vector2f dirUpRight = {1.0 / sqrt(2), -1.0 / sqrt(2)};
static sf::Vector2f dirDownLeft = {-1.0 / sqrt(2), 1.0 / sqrt(2)};
static sf::Vector2f dirDownRight = {1.0 / sqrt(2), 1.0 / sqrt(2)};
static sf::Vector2f directions[] = {dirleft, dirright, dirUpLeft, dirUpRight, dirDownLeft, dirDownRight};

class Constants
{
private:
    int windowWidth = 1280, windowHeight = 720;
    
    float ballRadius = 5;
    float ballStartX, ballStartY;
    float ballSpeed = 0.12;
    
    float paddleWidth = 5, paddleHeight;
    float paddle1StartX, paddle1StartY, paddle2StartX, paddle2StartY;
    float paddleSpeed = 0.1;
    
    float wallSize = 10;
    
    float wallTopX = 0;
    float wallTopY = 0;

    float wallBotX = 0;
    float wallBotY = (float) windowHeight;

public:
    Constants();
    ~Constants();

    float getWindowWidth() { return windowWidth; }

    float getWindowHeight() { return windowHeight; }


    float getBallRadius() { return ballRadius; }

    float getBallStartX() { return ballStartX; }

    float getBallStartY() { return ballStartY; }

    float getBallSpeed() { return ballSpeed; }

    inline sf::Vector2f getBallStartPosition()
    {
        return {ballStartX, ballStartY};
    }


    float getPaddleWidth() { return paddleWidth; }

    float getPaddleHeight() { return paddleHeight; }

    sf::Vector2f getPaddleSize() { return {paddleWidth, paddleHeight}; }

    float getPaddle1StartX() { return paddle1StartX; }

    float getPaddle1StartY() { return paddle1StartY; }

    sf::Vector2f getPaddle1StartPosition() { return {paddle1StartX, paddle1StartY}; }

    float getPaddle2StartX() { return paddle2StartX; }

    float getPaddle2StartY() { return paddle2StartY; }

    sf::Vector2f getPaddle2StartPosition() { return {paddle2StartX, paddle2StartY}; }

    float getPaddleSpeed() { return paddleSpeed; }


    float getWallSize() { return wallSize; }

    sf::Vector2f getWallTopPosition() { return {wallTopX, wallTopY}; }

    sf::Vector2f getWallBotPosition() { return {wallBotX, wallBotY}; }
};

Constants::Constants()
{
    paddleHeight = windowHeight / 10;
    ballStartX = windowWidth / 2;
    ballStartY = windowHeight / 2;
    paddle1StartX = 0 + wallSize + windowWidth / 100;
    paddle1StartY = paddle2StartY = windowHeight / 2;
    paddle2StartX = windowWidth - (wallSize + windowWidth / 100);
}

Constants::~Constants()
{
}
