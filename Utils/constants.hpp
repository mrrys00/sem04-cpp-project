#include <iostream>
#include <SFML/Graphics.hpp>

inline sf::Vector2f dirleft = {(float)-1.0, (float)0.0};
inline sf::Vector2f dirright = {(float)1.0, (float)0.0};
inline sf::Vector2f dirUpLeft = {(float)-1.0 / sqrt(2), (float)-1.0 / sqrt(2)};
inline sf::Vector2f dirUpRight = {(float)1.0 / sqrt(2), (float)-1.0 / sqrt(2)};
inline sf::Vector2f dirDownLeft = {(float)-1.0 / sqrt(2), (float)1.0 / sqrt(2)};
inline sf::Vector2f dirDownRight = {(float)1.0 / sqrt(2), (float)1.0 / sqrt(2)};
inline sf::Vector2f directions[] = {dirleft, dirright, dirUpLeft, dirUpRight, dirDownLeft, dirDownRight};

inline int windowWidth = 1280, windowHeight = 720;

inline float ballRadius = 5;
inline float ballStartX = windowWidth / 2, ballStartY = windowHeight / 2;
inline float ballSpeed = 0.12;

inline float wallSize = 10;
inline float paddleWidth = 5;
inline float paddleHeight = windowHeight / 10;
inline float paddle1StartX = 0 + wallSize + windowWidth / 100;
inline float paddle1StartY = windowHeight / 2;
inline float paddle2StartX = windowWidth - (wallSize + windowWidth / 100);
inline float paddle2StartY = windowHeight / 2;
inline float paddleSpeed = 0.07;

inline float wallTopX = 0;
inline float wallTopY = 0;

inline float wallBotX = 0;
inline float wallBotY = (float)(windowHeight - wallSize);

inline float wallLefX = 0;
inline float wallLefY = 0;

inline float wallRigX = (float)(windowWidth - wallSize);
inline float wallRigY = 0;

// class Constants
// {
// private:
//     int windowWidth = 1280, windowHeight = 720;

//     float ballRadius = 5;
//     float ballStartX, ballStartY;
//     float ballSpeed = 0.12;

//     float paddleWidth = 5, paddleHeight;
//     float paddle1StartX, paddle1StartY, paddle2StartX, paddle2StartY;
//     float paddleSpeed = 0.1;

//     float wallSize = 10;

//     float wallTopX = 0;
//     float wallTopY = 0;

//     float wallBotX = 0;
//     float wallBotY = (float)windowHeight;

// public:
//     Constants();
//     ~Constants();

    // int getWindowWidth() { return windowWidth; }

    // int getWindowHeight() { return windowHeight; }

    // float getBallRadius() { return ballRadius; }

    // float getBallStartX() { return ballStartX; }

    // float getBallStartY() { return ballStartY; }

    // float getBallSpeed() { return ballSpeed; }

    // inline sf::Vector2f getBallStartPosition()
    // {
    //     return {ballStartX, ballStartY};
    // }

    // float getPaddleWidth() { return paddleWidth; }

    // float getPaddleHeight() { return paddleHeight; }

    // sf::Vector2f getPaddleSize() { return {paddleWidth, paddleHeight}; }

    // float getPaddle1StartX() { return paddle1StartX; }

    // float getPaddle1StartY() { return paddle1StartY; }

    // sf::Vector2f getPaddle1StartPosition() { return {paddle1StartX, paddle1StartY}; }

    // float getPaddle2StartX() { return paddle2StartX; }

    // float getPaddle2StartY() { return paddle2StartY; }

    // sf::Vector2f getPaddle2StartPosition() { return {paddle2StartX, paddle2StartY}; }

    // float getPaddleSpeed() { return paddleSpeed; }

    // float getWallSize() { return wallSize; }

    // sf::Vector2f getWallTopPosition() { return {wallTopX, wallTopY}; }

    // sf::Vector2f getStandardWallSize() { return {(float) windowWidth, wallSize}; }

    // sf::Vector2f getWallBotPosition() { return {wallBotX, wallBotY}; }

    // sf::Vector2f getScoreWallSize() { return {wallSize, (float) windowHeight}; }

    // sf::Vector2f dirleft = {(float) -1.0, (float) 0.0};
    // sf::Vector2f dirright = {(float) 1.0, (float) 0.0};
    // sf::Vector2f dirUpLeft = {(float) (-1.0 / sqrtf(2)), (float) (-1.0 / sqrtf(2))};
    // sf::Vector2f dirUpRight = {(float) (1.0 / sqrtf(2)), (float) (-1.0 / sqrtf(2))};
    // sf::Vector2f dirDownLeft = {(float) (-1.0 / sqrtf(2)), (float) ( 1.0 / sqrtf(2))};
    // sf::Vector2f dirDownRight = {(float) (1.0 / sqrtf(2)), (float) (1.0 / sqrtf(2))};
    // sf::Vector2f directions[6] = {dirleft, dirright, dirUpLeft, dirUpRight, dirDownLeft, dirDownRight};
// };

// Constants::Constants()
// {
//     paddleHeight = windowHeight / 10;
//     ballStartX = windowWidth / 2;
//     ballStartY = windowHeight / 2;
//     paddle1StartX = 0 + wallSize + windowWidth / 100;
//     paddle1StartY = paddle2StartY = windowHeight / 2;
//     paddle2StartX = windowWidth - (wallSize + windowWidth / 100);
// }

// Constants::~Constants()
// {
// }
