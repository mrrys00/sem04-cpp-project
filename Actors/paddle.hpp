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
        if ((distance.y < 0 && pos.y >= 0 + wallSize + distance.y) || (distance.y > 0 && pos.y <= (float) windowHeight - wallSize - paddleHeight - distance.y))
            paddle.move(distance);
    }

    void isCollidingWith(Ball *ball)
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

    void setPos(sf::Vector2f newPos)
    {
        paddle.setPosition(newPos);
    }

private:
    sf::RectangleShape paddle;
    float paddleSpeed;
    sf::Vector2f position;
};

Paddle::Paddle(sf::Vector2f size, float speed, sf::Vector2f pos)
{
    paddle.setSize(size);
    paddleSpeed = speed;
    position = pos;
    paddle.setPosition(pos);
}
