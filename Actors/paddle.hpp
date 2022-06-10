#include <SFML/Graphics.hpp>
#include "ball.hpp"

class Paddle
{
public:
    Paddle(sf::Vector2f size, sf::Vector2f pos)
    {
        paddle.setSize(size);
        paddle.setPosition(pos);
    }

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(paddle);
    }

    void move(sf::Vector2f distance)
    {
        paddle.move(distance);
    }

    void isCollidingWith(Ball *ball)
    {
        if (ball->getGlobalBounds().intersects(paddle.getGlobalBounds()))
        {
            if (ball->getDirection() == dirDownLeft)
            {
                ball->setDirection(dirDownRight);
            }
            else if (ball->getDirection() == dirUpLeft)
            {
                ball->setDirection(dirUpRight);
            }
            else if (ball->getDirection() == dirDownRight)
            {
                ball->setDirection(dirDownRight);
            }
            else if (ball->getDirection() == dirUpRight)
            {
                ball->setDirection(dirUpLeft);
            }
            else if (ball->getDirection() == dirleft || ball->getDirection() == dirright)
            {
                ball->setRadnomDirection();
            }
            ball->incrementHitsCounter();
        }
        return;
    }

    void setPos(sf::Vector2f newPos)
    {
        paddle.setPosition(newPos);
    }

private:
    sf::RectangleShape paddle;
    sf::Vector2f dirleft = dirleft;
    sf::Vector2f dirright = dirright;
    sf::Vector2f dirUpLeft = dirUpLeft;
    sf::Vector2f dirUpRight = dirUpRight;
    sf::Vector2f dirDownLeft = dirDownLeft;
    sf::Vector2f dirDownRight = dirDownRight;
};

#pragma once