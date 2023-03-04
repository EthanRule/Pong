#include <iostream>
#include <SFML/Graphics.hpp>

struct Paddle {
    int x;
    int y;
    sf::Color color;
};

sf::RectangleShape createPaddle(Paddle paddleAttributes)
{
    sf::RectangleShape Paddle;
    Paddle.setFillColor(paddleAttributes.color);
    Paddle.setSize(sf::Vector2f(15, 100));
    Paddle.setOutlineColor(sf::Color::White);
    Paddle.setOutlineThickness(2);
    Paddle.setPosition(paddleAttributes.x, paddleAttributes.y);
    return Paddle;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Paddle leftPaddle;
        leftPaddle.x = 10;
        leftPaddle.y = 20;
        leftPaddle.color = sf::Color::Blue;

        Paddle rightPaddle;
        rightPaddle.x = 1255;
        rightPaddle.y = 600;
        rightPaddle.color = sf::Color::Red;

        sf::RectangleShape leftP = createPaddle(leftPaddle);
        sf::RectangleShape rightP = createPaddle(rightPaddle);

        window.draw(leftP);
        window.draw(rightP);
        window.display();
    }



    return 0;
}

