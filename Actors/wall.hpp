#include <SFML/Graphics.hpp>
#include "paddle.hpp"

#ifndef WALL_HPP
#define WALL_HPP

class Wall
{
protected:
    sf::RectangleShape wall;

public:
    Wall(sf::Vector2f size, sf::Vector2f pos)
    {
        wall.setSize(size);
        wall.setPosition(pos);
    }

    virtual ~Wall() {}

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(wall);
    }

    sf::RectangleShape getWallShape()
    {
        return wall;
    }

    virtual void isCollidingWith(Ball *ball);
};

class StandardWall
{
private:
    sf::RectangleShape wall;

public:
    StandardWall(sf::Vector2f size, sf::Vector2f pos);

    void drawTo(sf::RenderWindow &window);

    sf::RectangleShape getWallShape();

    void isCollidingWith(Ball *ball);
};

class ScoreWall
{
private:
    sf::RectangleShape wall;
    int hits;
    bool collisionToHandle = false;

public:
    ScoreWall(sf::Vector2f size, sf::Vector2f pos);

    void drawTo(sf::RenderWindow &window);

    sf::RectangleShape getWallShape();

    void isCollidingWith(Ball *ball);

    bool getCollisionToHandle();

    int getHits();

    void falseCollisionToHandle();

    void zeroPoints();
};

#endif
