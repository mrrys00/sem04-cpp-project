#include "../Actors/wall.hpp"
class Game
{
private:
    sf::RenderWindow window;
    Wall wallTop, wallBottom, wallLeft, wallRight;
    Ball ball;
    Paddle player1, player2;
    Constants constt;

public:
    Game();
    ~Game();

    void init()
    {

    }

    void reset()
    {
    }

    void scoreUp()
    {
    }
};

Game::Game()
{
    // window setup
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
    window.create(sf::VideoMode(constt.getWindowWidth(), constt.getWindowHeight()), "Pong", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);

    ball = ball(constt.getBallRadius(), constt.getBallSpeed(), constt.getBallStartPosition());

}

Game::~Game()
{
}
