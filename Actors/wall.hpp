#include <SFML/Graphics.hpp>
#include "paddle.hpp"

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

/// ================================================

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

StandardWall::StandardWall(sf::Vector2f size, sf::Vector2f pos)
{
    wall.setSize(size);
    wall.setPosition(pos);
}

void StandardWall::drawTo(sf::RenderWindow &window)
{
    window.draw(wall);
}

sf::RectangleShape StandardWall::getWallShape()
{
    return wall;
}

void StandardWall::isCollidingWith(Ball *ball)
{
    if (ball->getGlobalBounds().intersects(wall.getGlobalBounds()))
    {
        if (ball->getDirection() == dirDownLeft)
        {
            ball->setDirection(dirUpLeft);
        }
        else if (ball->getDirection() == dirUpLeft)
        {
            ball->setDirection(dirDownLeft);
        }
        else if (ball->getDirection() == dirDownRight)
        {
            ball->setDirection(dirUpRight);
        }
        else if (ball->getDirection() == dirUpRight)
        {
            ball->setDirection(dirDownRight);
        }
    }
    return;
}

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
};

ScoreWall::ScoreWall(sf::Vector2f size, sf::Vector2f pos)
{
    wall.setSize(size);
    wall.setPosition(pos);
    hits = 0;
}

void ScoreWall::drawTo(sf::RenderWindow &window)
{
    window.draw(wall);
}

sf::RectangleShape ScoreWall::getWallShape()
{
    return wall;
}

void ScoreWall::isCollidingWith(Ball *ball)
{
    if (ball->getGlobalBounds().intersects(wall.getGlobalBounds()))
    {
        hits++;
        collisionToHandle = true;
    }
    return;
}

bool ScoreWall::getCollisionToHandle() { return collisionToHandle; }

int ScoreWall::getHits() { return hits; }

void ScoreWall::falseCollisionToHandle() { collisionToHandle = false; }
