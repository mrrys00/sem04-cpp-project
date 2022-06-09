#include <iostream>

class Constants
{
private:
    int windowWidth = 1280, windowHeight = 720;
    float ballRadius = 5;
    int ballStartX, ballStartY;
    float ballSpeed = 0.12;
    int paddleWidth = 5, paddleHeight;
    int paddle1StartX, paddle1StartY, paddle2StartX, paddle2StartY;
    float paddleSpeed = 0.1;
    int wallSize = 10;

public:
    Constants();
    ~Constants();

    int getWindowWidth() { return windowWidth; }

    int getWindowHeight() { return windowHeight; }

    float getBallRadius() { return ballRadius; }

    int getBallStartX() { return ballStartX; }

    int getBallStartY() { return ballStartY; }

    float getBallSpeed() { return ballSpeed; }

    int getPaddleWidth() { return paddleWidth; }

    int getPaddleHeight() { return paddleHeight; }

    int getPaddle1StartX() { return paddle1StartX; }

    int getPaddle1StartY() { return paddle1StartY; }

    int getPaddle2StartX() { return paddle2StartX; }

    int getPaddle2StartY() { return paddle2StartY; }

    float getPaddleSpeed() { return paddleSpeed; }

    int getWallSize() { return wallSize; }
    
    sf::Vector2f dirleft = {-1.0, 0.0};
    sf::Vector2f dirright = {1.0, 0.0};
    sf::Vector2f dirUpLeft = {-1.0 / sqrt(2), -1.0 / sqrt(2)};
    sf::Vector2f dirUpRight = {1.0 / sqrt(2), -1.0 / sqrt(2)};
    sf::Vector2f dirDownLeft = {-1.0 / sqrt(2), 1.0 / sqrt(2)};
    sf::Vector2f dirDownRight = {1.0 / sqrt(2), 1.0 / sqrt(2)};
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
