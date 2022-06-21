#include "game.hpp"

Game::Game() : ball(ballRadius, ballSpeed, {ballStartX, ballStartY}),
               player1({paddleWidth, paddleHeight}, paddleSpeed, {paddle1StartX, paddle1StartY}),
               player2({paddleWidth, paddleHeight}, paddleSpeed, {paddle2StartX, paddle2StartY}),
               wallTop({(float)windowWidth, wallSize}, {wallTopX, wallTopY}),
               wallBottom({(float)windowWidth, wallSize}, {wallBotX, wallBotY}),
               wallLeft({wallSize, (float)windowHeight}, {wallLefX, wallLefY}),
               wallRight({wallSize, (float)windowHeight}, {wallRigX, wallRigY}),
               score1(&wallRight, score1Pos),
               score2(&wallLeft, score2Pos)
{
    // window setup
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
    window.create(sf::VideoMode(windowWidth, windowHeight), "Pong 50th Anniversary", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
    ball.setRadnomStartDirection();
}

Game::~Game()
{
}

void Game::reset()
{
    ball.setPos({ballStartX, ballStartY});
    ball.zeroHitsCounter();
    player1.setPos({paddle1StartX, paddle1StartY});
    player2.setPos({paddle2StartX, paddle2StartY});
    wallLeft.falseCollisionToHandle();
    wallRight.falseCollisionToHandle();
    ball.setRadnomStartDirection();
}

void Game::checkBallCollisions()
{
    player1.isCollidingWith(&ball);
    player2.isCollidingWith(&ball);

    wallTop.isCollidingWith(&ball);
    wallBottom.isCollidingWith(&ball);
    wallLeft.isCollidingWith(&ball);
    wallRight.isCollidingWith(&ball);

    score1.setScore();
    score2.setScore();
}

void Game::draw()
{
    window.clear();
    player1.drawTo(window);
    player2.drawTo(window);
    ball.drawTo(window);
    wallTop.drawTo(window);
    wallBottom.drawTo(window);
    wallLeft.drawTo(window);
    wallRight.drawTo(window);
    score1.drawTo(window);
    score2.drawTo(window);
    window.display();
}

void Game::gameInProgress()
{
    bool wait = true;
    draw();

    while (window.isOpen())
    {
        while (wait)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                wait = false;
        }

        // catchEventMove();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player1.move({0, -1}, ball);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player1.move({0, 1}, ball);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player2.move({0, -1}, ball);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player2.move({0, 1}, ball);
        }

        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

        checkBallCollisions();

        ball.move();

        draw();

        if (wallLeft.getCollisionToHandle() || wallRight.getCollisionToHandle())
        {
            sleep(2);

            wait = true;
            if (wallLeft.getHits() == winScore || wallRight.getHits() == winScore)
            {
                score1.setWinner();
                score2.setWinner();
                draw();

                wallLeft.zeroPoints();
                wallRight.zeroPoints();

                while (wait)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                        wait = false;
                }
                wait = true;
            }

            reset();
            draw();
        }
    }
}

void Game::play() { gameInProgress(); }
