#include <SFML/Graphics.hpp>
#include <math.h>
#include "../Utils/constants.hpp"

class Ball
{
public:
    Ball(float r, float ballSpee, sf::Vector2f pos);

    sf::Vector2f getDirection();

    void setDirection(sf::Vector2f newDirection);

    void setRadnomDirection();

    void incrementHitsCounter();

    void zeroHitsCounter();

    void drawTo(sf::RenderWindow &window);

    void move();

    sf::FloatRect getGlobalBounds();

    void setPos(sf::Vector2f newPos);

private:
    sf::CircleShape ball;
    sf::Vector2f direction;
    float ballSpeed;
    int hitsCounter;
};

Ball::Ball(float r, float ballSpee, sf::Vector2f pos)
{
    ball.setRadius(r);
    ballSpeed = ballSpee;
    hitsCounter = 1;
    ball.setPosition(pos);
    direction = directions[rand() % (sizeof(directions) / sizeof(*directions))];
}

sf::Vector2f Ball::getDirection()
{
    return direction;
}

void Ball::setDirection(sf::Vector2f newDirection)
{
    direction = newDirection;
}

void Ball::setRadnomDirection()
{
    direction = directions[rand() % (sizeof(directions) / sizeof(*directions))];
}

void Ball::incrementHitsCounter()
{
    // pts counter
    hitsCounter++;
}

void Ball::zeroHitsCounter()
{
    hitsCounter = 1;
}

void Ball::drawTo(sf::RenderWindow &window)
{
    window.draw(ball);
}

void Ball::move()
{
    ball.move({ballSpeed * direction.x * (sqrt((float)hitsCounter) / 3), ballSpeed * direction.y * (sqrt((float)hitsCounter) / 3)});
}

sf::FloatRect Ball::getGlobalBounds()
{
    return ball.getGlobalBounds();
}

void Ball::setPos(sf::Vector2f newPos)
{
    ball.setPosition(newPos);
}
