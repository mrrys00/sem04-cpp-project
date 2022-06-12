#include <SFML/Graphics.hpp>
// #include <SFML/Graphics/Text.hpp>
#include <string.h>
#include "wall.hpp"

#ifndef SCORE_HPP
#define SCORE_HPP

class Score
{
private:
    sf::Font f;
    sf::Text t;
    ScoreWall *wall;

public:
    Score(ScoreWall *w, sf::Vector2f pos);
    virtual ~Score();

    void setScore();

    void drawTo(sf::RenderWindow &window);
};

#endif
