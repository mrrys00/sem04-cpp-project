#include "ball.hpp"

Ball::Ball(float r, float ballSpee, sf::Vector2f pos)
{
    srand(time(NULL));
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

void Ball::setRadnomDirection(sf::Vector2f dir)
{
    if (dir.x > 0)
        direction = directions[rand() % ((sizeof(directions) / sizeof(*directions)) / 2)];
    else
        direction = directions[rand() % ((sizeof(directions) / sizeof(*directions)) / 2) + 3];
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

int Ball::getHitsCounter()
{
    return hitsCounter;
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
