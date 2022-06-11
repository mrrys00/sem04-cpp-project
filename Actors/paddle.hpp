#include <SFML/Graphics.hpp>
#include "ball.hpp"

class Paddle
{
public:
    Paddle(sf::Vector2f size, float speed, sf::Vector2f pos);

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(paddle);
    }

    void move(sf::Vector2f distance)
    {
        sf::Vector2f pos = paddle.getPosition();
        if (pos.y > 0 + wallSize + distance.x || pos.y < (float) windowHeight - wallSize - distance.y)
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
    float paddleSpeed;
};

Paddle::Paddle(sf::Vector2f size, float speed, sf::Vector2f pos)
{
    paddle.setSize(size);
    paddleSpeed = speed;
    paddle.setPosition(pos);
}
