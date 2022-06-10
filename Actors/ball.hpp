#include <SFML/Graphics.hpp>
#include <math.h>
#include "../Utils/constants.hpp"

class Ball
{
public:
    Ball(float r, float ballSpee, sf::Vector2f pos)
    {
        ball.setRadius(r);
        ballSpeed = ballSpee;
        hitsCounter = 0;
        ball.setPosition(pos);
    }

    sf::Vector2f getDirection()
    {
        return direction;
    }

    void setDirection(sf::Vector2f newDirection)
    {
        direction = newDirection;
    }

    void setRadnomDirection()
    {
        direction = directions[rand() % (sizeof(directions)/sizeof(*directions))];
    }

    void incrementHitsCounter()
    {
        // 
        hitsCounter++;
    }

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(ball);
    }

    void move()
    {
        ball.move({ballSpeed * direction.x * sqrt((float)hitsCounter), ballSpeed * direction.y * sqrt((float)hitsCounter)});
    }

    sf::FloatRect getGlobalBounds()
    {
        return ball.getGlobalBounds();
    }

    void setPos(sf::Vector2f newPos)
    {
        ball.setPosition(newPos);
    }

private:
    sf::CircleShape ball;
    sf::Vector2f direction;
    float ballSpeed;
    int hitsCounter;
};