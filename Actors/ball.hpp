#include <SFML/Graphics.hpp>
#include <math.h>

class Ball
{
public:
    Ball(float r)
    {
        ball.setRadius(r);
    }

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(ball);
    }

    void move(float ballSpeed)
    {
        ball.move({ballSpeed * direction.x, ballSpeed * direction.y});
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
};