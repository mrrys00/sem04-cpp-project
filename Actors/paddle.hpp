#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "direction.hpp"

class Paddle
{
public:
    Paddle(sf::Vector2f size)
    {
        paddle.setSize(size);
    }

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(paddle);
    }

    void move(sf::Vector2f distance)
    {
        paddle.move(distance);
    }

    bool isCollidingWith(Ball ball)
    {
        if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
        {
            return true;
        }
        return false;
    }

    void setPos(sf::Vector2f newPos)
    {
        paddle.setPosition(newPos);
    }

private:
    sf::RectangleShape paddle;
};

#pragma once