#include "score.hpp"

Score::Score(ScoreWall *w, sf::Vector2f pos) : t("0", f, 30)
{
    wall = w;
    f.loadFromFile("Resources/roboto.ttf");
    t.setCharacterSize(30);

    t.setFillColor(sf::Color::White);
    t.setPosition(pos);
}

Score::~Score()
{
}

void Score::setScore()
{
    t.setString(std::to_string(wall->getHits()));
}

void Score::drawTo(sf::RenderWindow &window)
{
    window.draw(t);
}

void Score::setWinner()
{
    if (wall->getHits() == winScore)
        t.setString("WINNER");
    else 
        t.setString("LOSER");
}
