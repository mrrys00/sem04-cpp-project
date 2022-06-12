#include <SFML/Graphics.hpp>
#include "ball.hpp"

#ifndef PADDLE_HPP
#define PADDLE_HPP

class Paddle
{
public:
    Paddle(sf::Vector2f size, float speed, sf::Vector2f pos);

    void drawTo(sf::RenderWindow &window);

    void move(sf::Vector2f distance, Ball ball);

    void isCollidingWith(Ball *ball);

    void setPos(sf::Vector2f newPos);

private:
    sf::RectangleShape paddle;
    float paddleSpeed;
    sf::Vector2f position;
};

#endif
