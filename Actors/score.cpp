#include "score.hpp"

Score::Score(ScoreWall *w, sf::Vector2f pos)
{
    wall = w;
    // f.loadFromFile("../Resources/lucida_console.ttf");
    f.loadFromFile("arial.ttf");
    t.setFont(f);
    t.setCharacterSize(30);
    
    t.setFillColor(sf::Color::White);
    t.setString("0");
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
