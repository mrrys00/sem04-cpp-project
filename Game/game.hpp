#include <iostream>
#include <unistd.h>

#include "../Actors/wall.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
    sf::RenderWindow window;
    Ball ball;
    Paddle player1, player2;
    StandardWall wallTop, wallBottom;
    ScoreWall wallLeft, wallRight;

    void reset();

    void checkBallCollisions();

    void draw();

    void gameInProgress();

public:
    Game();
    virtual ~Game();

    void play();
};

#endif