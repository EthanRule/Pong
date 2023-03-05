/*
Created by Moff and Ethan Rule

Objective: Build the game 
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Paddle.hpp"

sf::RectangleShape createPaddle(Paddle p) {
    sf::RectangleShape Paddle;
    Paddle.setFillColor(p.getColor());
    Paddle.setSize(sf::Vector2f(15, 100));
    Paddle.setOutlineColor(sf::Color(0, 0, 128, 255));
    Paddle.setOutlineThickness(2);
    Paddle.setPosition(p.getXPosition(), p.getYPosition());

    return Paddle;
}

int main() {
    bool keyHeldDown = false;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong");

    Paddle leftPaddle = Paddle(10, 20, sf::Color::Blue);
    Paddle rightPaddle = Paddle(1255, 600, sf::Color::Red);

    sf::RectangleShape leftP = createPaddle(leftPaddle);
    sf::RectangleShape rightP = createPaddle(rightPaddle);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::W) {

                    leftPaddle.updatePosition(true);
                }

                if (event.key.code == sf::Keyboard::S) {

                    leftPaddle.updatePosition(false);
                }

                // Right Paddle
                if (event.key.code == sf::Keyboard::Up) {

                    rightPaddle.updatePosition(true);
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    rightPaddle.updatePosition(false);
                }

                break;
            }
        }

        leftP.setPosition(leftPaddle.getXPosition(), leftPaddle.getYPosition());
        rightP.setPosition(rightPaddle.getXPosition(), rightPaddle.getYPosition());

        window.clear();

        window.draw(leftP);
        window.draw(rightP);
        window.display();
    }

    return 0;
}

