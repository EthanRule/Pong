#include "Paddle.cpp"
#include "SFML/Graphics.hpp"

sf::RectangleShape createPaddle(Paddle p) {
    sf::RectangleShape Paddle;
    Paddle.setFillColor(p.getColor());
    Paddle.setSize(sf::Vector2f(15, 100));
    Paddle.setOutlineColor(sf::Color(0, 0, 128, 255));
    Paddle.setOutlineThickness(2);
    Paddle.setPosition(p.getXPosition(), p.getYPosition());

    return Paddle;
}