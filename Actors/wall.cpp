#include "wall.hpp"

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
