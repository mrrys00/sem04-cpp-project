#include <SFML/Graphics.hpp>
#include "paddle.hpp"

class Wall
{
private:
    sf::RectangleShape wall;

public:
    void drawTo(sf::RenderWindow &window)
    {
        window.draw(wall);
    }

    sf::RectangleShape getWallShape()
    {
        return wall;
    }

    virtual void isCollidingWith(Ball *ball);

    // void setPos(sf::Vector2f newPos)
    // {
    //     wall.setPosition(newPos);
    // }
};

/// ================================================

class StandardWall : public Wall
{
private:
    sf::RectangleShape wall;

public:
    StandardWall(sf::Vector2f size, sf::Vector2f pos)
    {
        paddle.setSize(size);
        paddle.setPosition(pos);
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
                ball->setDirection(dirUpLeft);
            }
            else if (ball->getDirection() == dirleft || ball->getDirection() == dirright)
            {
                ball->setRadnomDirection();
            }
        }
        return;
    }
};

class ScoreWall : public Wall
{
private:
    sf::RectangleShape wall;
    int hits;

public:
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
                ball->setDirection(dirUpLeft);
            }
            else if (ball->getDirection() == dirleft || ball->getDirection() == dirright)
            {
                ball->setRadnomDirection();
            }
        }
        return;
    }
};
