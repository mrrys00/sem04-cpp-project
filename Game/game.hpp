#include <iostream>
#include <unistd.h>

#include "../Actors/wall.hpp"

class Game
{
private:
    sf::RenderWindow window;
    Ball ball;
    Paddle player1, player2;
    StandardWall wallTop, wallBottom;
    // ScoreWall wallLeft, wallRight;
    Constants constt;

public:
    Game();
    ~Game();

    void waitForInit()
    {
        while (true)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                break;
            }
            window.clear();
            player1.drawTo(window);
            player2.drawTo(window);
            ball.drawTo(window);
            window.display();
        }
    }

    void reset()
    {
        ball.setPos(constt.getBallStartPosition());
        player1.setPos(constt.getPaddle1StartPosition());
        player2.setPos(constt.getPaddle2StartPosition());
        waitForInit();
    }

    void catchCloseEvent()
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {

            case sf::Event::Closed:
                window.close();
            }
        }
    }

    void catchEventMove()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player1.move({0, -1});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player1.move({0, 1});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player2.move({0, -1});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player2.move({0, 1});
        }
    }

    void checkBallCollisions()
    {
        player1.isCollidingWith(&ball);
        player2.isCollidingWith(&ball);

        wallTop.isCollidingWith(&ball);
        wallBottom.isCollidingWith(&ball);
        // wallLeft, wallRight; .isColliding with
    }

    void draw()
    {
        window.clear();
        player1.drawTo(window);
        player2.drawTo(window);
        ball.drawTo(window);
        wallTop.drawTo(window);
        wallBottom.drawTo(window);
        window.display();
    }

    // void waitingForReset()
    // {
    //     if (wallLeft || wallRight getCollitionToHandle)
    //     {
    //         sleep(2);
    //         reset();
    //     }
    // }

    void gameInProgress()
    {
        waitForInit();
        while (window.isOpen())
        {
            catchEventMove();
            catchCloseEvent();
            checkBallCollisions();
            draw();

            // waitingForReset();
        }
    }

    void play() { gameInProgress(); }
};

Game::Game() : ball(constt.getBallRadius(), constt.getBallSpeed(), constt.getBallStartPosition()),
               player1(constt.getPaddleSize(), constt.getPaddleSpeed(), constt.getPaddle1StartPosition()),
               player2(constt.getPaddleSize(), constt.getPaddleSpeed(), constt.getPaddle2StartPosition()),
               wallTop(constt.getWallSize(), constt.getWallTopPosition()),
               wallBottom(constt.getWallSize(), constt.getWallBotPosition())

{
    // window setup
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
    window.create(sf::VideoMode(constt.getWindowWidth(), constt.getWindowHeight()), "Pong", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
}

Game::~Game()
{
}
