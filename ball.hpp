#include <SFML/Graphics.hpp>
 
class Ball {
public:
    Ball(sf::Vector2f size) {
        ball.setSize(size);
    }
 
    void drawTo(sf::RenderWindow &window) {
        window.draw(ball);
    }
 
    void move(sf::Vector2f distance) {
        ball.move(distance);
    }
 
    sf::FloatRect getGlobalBounds() {
        return ball.getGlobalBounds();
    }
 
    void setPos(sf::Vector2f newPos) {
        ball.setPosition(newPos);
    }
private:
    sf::RectangleShape ball;
};