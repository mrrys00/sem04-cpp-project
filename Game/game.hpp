#include <iostream>
#include <unistd.h>

#include "../Actors/score.hpp"

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
    Score score1, score2;

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