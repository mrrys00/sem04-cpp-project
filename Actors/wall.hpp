#include <SFML/Graphics.hpp>
#include "paddle.hpp"

class Wall
{
private:
    sf::RectangleShape wall;

public:
    Wall();
    ~Wall();

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(wall);
    }

    // bool isCollidingWith(Ball ball)
    // {
    //     if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    void setPos(sf::Vector2f newPos)
    {
        wall.setPosition(newPos);
    }
};

Wall::Wall()
{
}

Wall::~Wall()
{
}
