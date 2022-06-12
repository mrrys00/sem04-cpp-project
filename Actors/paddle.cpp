#include "paddle.hpp"

Paddle::Paddle(sf::Vector2f size, float speed, sf::Vector2f pos)
{
    paddle.setSize(size);
    paddleSpeed = speed;
    position = pos;
    paddle.setPosition(pos);
}

void Paddle::drawTo(sf::RenderWindow &window)
{
    window.draw(paddle);
}

void Paddle::move(sf::Vector2f distance, Ball ball)
{
    sf::Vector2f pos = paddle.getPosition();
    if ((distance.y < 0 && pos.y >= 0 + wallSize + distance.y) || (distance.y > 0 && pos.y <= (float)windowHeight - wallSize - paddleHeight - distance.y))
        paddle.move({distance.x, distance.y * paddleSpeed * (sqrt((float)ball.getHitsCounter()) / 3)});
}

void Paddle::isCollidingWith(Ball *ball)
{
    if (ball->getGlobalBounds().intersects(paddle.getGlobalBounds()))
    {
        sf::Vector2f dir = ball->getDirection();
        if (dir == dirDownLeft)
        {
            ball->setDirection(dirDownRight);
        }
        else if (dir == dirUpLeft)
        {
            ball->setDirection(dirUpRight);
        }
        else if (dir == dirDownRight)
        {
            ball->setDirection(dirDownLeft);
        }
        else if (dir == dirUpRight)
        {
            ball->setDirection(dirUpLeft);
        }
        else if (dir == dirleft || dir == dirright)
        {
            ball->setRadnomDirection(dir);
        }
        ball->incrementHitsCounter();
    }
    return;
}

void Paddle::setPos(sf::Vector2f newPos)
{
    paddle.setPosition(newPos);
}
