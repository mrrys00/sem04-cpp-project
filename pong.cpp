#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game/game.hpp"
 
int main() {
    
 
 
 
 
    //Paddle Objects:
    Paddle paddle1({ 10, 100 });
    Paddle paddle2({ 10, 100 });
    paddle1.setPos({ 50, 200 });
    paddle2.setPos({ 850, 200 });
 
    //Ball Object:
    ball.setPos({ 400, 200 });
 
    while(true)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            break;
        } 
        window.clear();
        paddle1.drawTo(window);
        paddle2.drawTo(window);
        ball.drawTo(window);
        window.display();
    }

    //Main Loop:
    while (window.isOpen()) {
 
        sf::Event Event;
 
        const float moveSpeed = 0.2;
 
        //Player1 Movement:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            paddle1.move({ 0, -moveSpeed });
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            paddle1.move({ 0, moveSpeed });
        }
 
        //Player2 Movement:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            paddle2.move({ 0, -moveSpeed });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            paddle2.move({ 0, moveSpeed });
        }
 
        //Event Loop:
        while (window.pollEvent(Event)) {
            switch (Event.type) {
 
            case sf::Event::Closed:
                window.close();
            }
 
        }
 
        static bool goingLeft = true;
        static bool goingRight = false;

        // piłkę będzie trzeba przekazywać jako wskaźnik
        if (goingLeft == true && paddle1.isCollidingWith(&ball) == false) {
            ball.move({ -moveSpeed / 2, moveSpeed / 4 });
        }
        else if (goingLeft == true && paddle1.isCollidingWith(&ball) == true) {
            goingRight = true;
            goingLeft = false;
        }
 
        if (goingRight == true && paddle2.isCollidingWith(&ball) == false) {
            ball.move({ moveSpeed / 2, -moveSpeed / 4 });
        }
        else if (goingRight == true && paddle2.isCollidingWith(&ball) == true) {
            goingRight = false;
            goingLeft = true;
        }

        window.clear();
        paddle1.drawTo(window);
        paddle2.drawTo(window);
        ball.drawTo(window);
        window.display();
    }
}