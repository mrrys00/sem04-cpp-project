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
    StandardWall(sf::Vector2f size, sf::Vector2f pos)
    {
        wall.setSize(size);
        wall.setPosition(pos);
    }

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(wall);
    }

    sf::RectangleShape getWallShape()
    {
        return wall;
    }

    void isCollidingWith(Ball *ball)
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
            // else if (ball->getDirection() == dirleft || ball->getDirection() == dirright)
            // {
            //     ball->setRadnomDirection();
            // }
        }
        return;
    }
};

class ScoreWall
{
private:
    sf::RectangleShape wall;
    int hits;
    bool collisionToHandle = false;

public:
    ScoreWall(sf::Vector2f size, sf::Vector2f pos)
    {
        wall.setSize(size);
        wall.setPosition(pos);
        hits = 0;
    }

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(wall);
    }

    sf::RectangleShape getWallShape()
    {
        return wall;
    }

    void isCollidingWith(Ball *ball)
    {
        if (ball->getGlobalBounds().intersects(wall.getGlobalBounds()))
        {
            hits++;
            collisionToHandle = true;
        }
        return;
    }

    bool getCollisionToHandle() { return collisionToHandle; }

    int getHits() { return hits; }

    void falseCollisionToHandle() { collisionToHandle = false; }
};
