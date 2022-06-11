#include <SFML/Graphics.hpp>
#include <math.h>
#include "../Utils/constants.hpp"

#ifndef BALL_HPP
#define BALL_HPP

class Ball
{
public:
    Ball(float r, float ballSpee, sf::Vector2f pos);

    sf::Vector2f getDirection();

    void setDirection(sf::Vector2f newDirection);

    void setRadnomDirection(sf::Vector2f dir);

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

#endif
