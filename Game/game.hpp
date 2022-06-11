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
    ScoreWall wallLeft, wallRight;

public:
    Game();
    ~Game();

    void waitForInit()
    {
        window.clear();
        player1.drawTo(window);
        player2.drawTo(window);
        ball.drawTo(window);
        window.display();

        while (true)
        {
            std::cout << "aaaa" << std::endl;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                break;
            }
            else
                sleep(1);
        }
    }

    void reset()
    {
        ball.setPos({ballStartX, ballStartY});
        player1.setPos({paddle1StartX, paddle1StartY});
        player2.setPos({paddle2StartX, paddle2StartY});
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
        std::cout << "działaj2" << std::endl;

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
        // draw();
        window.clear();
        player1.drawTo(window);
        player2.drawTo(window);
        ball.drawTo(window);
        wallTop.drawTo(window);
        wallBottom.drawTo(window);
        window.display();

        std::cout << "działaj" << std::endl;
        // waitForInit();

        window.clear();
        player1.drawTo(window);
        player2.drawTo(window);
        ball.drawTo(window);
        window.display();

        while (true)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                break;
        }

        while (window.isOpen())
        {
            // catchEventMove();
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

            // catchCloseEvent();
            sf::Event Event;
            while (window.pollEvent(Event))
            {
                switch (Event.type)
                {

                case sf::Event::Closed:
                    window.close();
                }
            }

            // checkBallCollisions();
            player1.isCollidingWith(&ball);
            player2.isCollidingWith(&ball);

            wallTop.isCollidingWith(&ball);
            wallBottom.isCollidingWith(&ball);
            wallLeft.isCollidingWith(&ball);
            wallRight.isCollidingWith(&ball);

            // move fucking ball
            ball.move();

            // draw();
            window.clear();
            player1.drawTo(window);
            player2.drawTo(window);
            ball.drawTo(window);
            wallTop.drawTo(window);
            wallBottom.drawTo(window);
            window.display();

            // waitingForReset();
            if (wallLeft.getCollisionToHandle() || wallRight.getCollisionToHandle())
            {
                std::cout << "score " << wallLeft.getHits() << " : " << wallRight.getHits() << std::endl;
                sleep(2);
                
                ball.setPos({ballStartX, ballStartY});
                ball.zeroHitsCounter();
                player1.setPos({paddle1StartX, paddle1StartY});
                player2.setPos({paddle2StartX, paddle2StartY});
                wallLeft.falseCollisionToHandle();
                wallRight.falseCollisionToHandle();

                while (true)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                        break;
                }

            }
        }
    }

    void play() { gameInProgress(); }
};

Game::Game() : ball(ballRadius, ballSpeed, {ballStartX, ballStartY}),
               player1({paddleWidth, paddleHeight}, paddleSpeed, {paddle1StartX, paddle1StartY}),
               player2({paddleWidth, paddleHeight}, paddleSpeed, {paddle2StartX, paddle2StartY}),
               wallTop({(float)windowWidth, wallSize}, {wallTopX, wallTopY}),
               wallBottom({(float)windowWidth, wallSize}, {wallBotX, wallBotY}),
               wallLeft({wallSize, (float)windowHeight}, {wallLefX, wallLefY}),
               wallRight({wallSize, (float)windowHeight}, {wallRigX, wallRigY})
{
    // window setup
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
    window.create(sf::VideoMode(windowWidth, windowHeight), "Pong", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
}

Game::~Game()
{
}
