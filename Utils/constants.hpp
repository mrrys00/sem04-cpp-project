#include <iostream>
#include <SFML/Graphics.hpp>

inline sf::Vector2f dirleft = {(float)-1.0, (float)0.0};
inline sf::Vector2f dirright = {(float)1.0, (float)0.0};
inline sf::Vector2f dirUpLeft = {(float)-1.0 / sqrt(2), (float)-1.0 / sqrt(2)};
inline sf::Vector2f dirUpRight = {(float)1.0 / sqrt(2), (float)-1.0 / sqrt(2)};
inline sf::Vector2f dirDownLeft = {(float)-1.0 / sqrt(2), (float)1.0 / sqrt(2)};
inline sf::Vector2f dirDownRight = {(float)1.0 / sqrt(2), (float)1.0 / sqrt(2)};
inline sf::Vector2f directions[] = {dirleft, dirUpLeft, dirDownLeft, dirright, dirUpRight, dirDownRight};

inline int windowWidth = 1280, windowHeight = 720;

inline float ballRadius = 5;
inline float ballStartX = windowWidth / 2 - ballRadius / 2;
inline float ballStartY = windowHeight / 2 - ballRadius / 2;
inline float ballSpeed = 0.12;

inline float wallSize = 10;
inline float paddleWidth = 5;
inline float paddleHeight = windowHeight / 10;
inline float paddle1StartX = 0 + wallSize + windowWidth / 100;
inline float paddle1StartY = windowHeight / 2 - paddleHeight / 2;
inline float paddle2StartX = windowWidth - (wallSize + windowWidth / 100);
inline float paddle2StartY = windowHeight / 2 - paddleHeight / 2;
inline float paddleSpeed = 0.07;

inline float wallTopX = 0;
inline float wallTopY = 0;

inline float wallBotX = 0;
inline float wallBotY = (float)(windowHeight - wallSize);

inline float wallLefX = 0;
inline float wallLefY = 0;

inline float wallRigX = (float)(windowWidth - wallSize);
inline float wallRigY = 0;
