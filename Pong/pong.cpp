/*
Created by Moff and Ethan Rule

Objective: Build the game 
*/

#include <iostream>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Paddle.hpp"
#include "Ball.hpp"

sf::RectangleShape createPaddle(Paddle p) {
    sf::RectangleShape Paddle;
    Paddle.setFillColor(p.getColor());
    Paddle.setSize(sf::Vector2f(15, 100));
    Paddle.setOutlineColor(sf::Color(0, 0, 128, 255));
    Paddle.setOutlineThickness(2);
    Paddle.setPosition(p.getXPosition(), p.getYPosition());

    return Paddle;
}

sf::CircleShape createCircle(Ball b)
{
    sf::CircleShape Ball;
    Ball.setRadius(b.getRadius());
    Ball.setFillColor(sf::Color(255, 255, 255, 255));
    Ball.setOutlineColor(sf::Color(255, 0, 0, 255));
    Ball.setOutlineThickness(2);
    Ball.setPosition(b.getXPosition(), b.getYPosition());

    return Ball;
}

int main() {
    bool keyHeldDown = false;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong");

    Paddle leftPaddle = Paddle(10, 20, sf::Color::Blue);
    Paddle rightPaddle = Paddle(1255, 600, sf::Color::Red);
    Ball ball = Ball(640, 360, 10);

    sf::CircleShape ballFX = createCircle(ball);
    sf::RectangleShape leftP = createPaddle(leftPaddle);
    sf::RectangleShape rightP = createPaddle(rightPaddle);

    //TEXT
    sf::Font font;
    if (!font.loadFromFile("../Fonts/Shine.ttf"))
    {
        std::cout << "Error loading file TEXT" << std::endl;
        system("pause");
    }

    sf::Text text;
    text.setFont(font);
    text.setString("PONG!");
    text.setCharacterSize(200);
    text.setPosition(435, 60);
    text.setFillColor(sf::Color(255, 255, 255, 255));
    text.setOutlineColor(sf::Color(0, 0, 128, 255));
    text.setOutlineThickness(4);
    text.setStyle(sf::Text::Bold);

    sf::Text leftPaddleScore;
    leftPaddleScore.setFont(font);
    std::string left = std::to_string(leftPaddle.getScore());
    leftPaddleScore.setString(left);
    leftPaddleScore.setCharacterSize(30);
    leftPaddleScore.setPosition(leftPaddle.getXPosition() + 50, 30);
    leftPaddleScore.setStyle(sf::Text::Bold);
    leftPaddleScore.setFillColor(sf::Color(255, 255, 255, 255));

    sf::Text rightPaddleScore;
    rightPaddleScore.setFont(font);
    std::string right = std::to_string(rightPaddle.getScore());
    rightPaddleScore.setString(right);
    rightPaddleScore.setCharacterSize(30);
    rightPaddleScore.setPosition(rightPaddle.getXPosition() - 80, 30);
    rightPaddleScore.setStyle(sf::Text::Bold);
    rightPaddleScore.setFillColor(sf::Color(255, 255, 255, 255));

    //AUDIO
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../Audio/SoundTrack.wav"))
    {
        std::cout << "Error loading file SOUND" << std::endl;
        system("pause");
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(10.f);
    sound.setLoop(true);
    sound.play();


    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        // Update Paddle Position
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            leftPaddle.updatePosition(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            leftPaddle.updatePosition(false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rightPaddle.updatePosition(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rightPaddle.updatePosition(false);
        }

        if (ball.getXPosition() <= (leftPaddle.getXPosition() + 15) && ball.getYPosition() >= leftPaddle.getYPosition() && ball.getYPosition() <= leftPaddle.getYPosition() + 100) {
            double part = (ball.getYPosition() - leftPaddle.getYPosition()) / 100; // Will return 1, 0, -1
            ball.determineLocation(true, part);
        } 
        
        if (ball.getXPosition() >= (rightPaddle.getXPosition() - 15) && ball.getYPosition() >= (rightPaddle.getYPosition()) && ball.getYPosition() <= rightPaddle.getYPosition() + 100) {
            double part = (ball.getYPosition() - rightPaddle.getYPosition()) / 100; // Will return 1, 0, -1
            ball.determineLocation(false, part);
        }

        if (ball.getYPosition() <= 0 || ball.getYPosition() >= 700) {
            ball.setYSpeed();
        }

        if (ball.getXPosition() <= 0 || ball.getXPosition() >= 1280) {
            if (ball.getXPosition() <= 0) {
                rightPaddle.updateScore();
                std::string right = std::to_string(rightPaddle.getScore());
                rightPaddleScore.setString(right);
            }

            if (ball.getXPosition() >= 1280) {
                leftPaddle.updateScore();
                std::string left = std::to_string(leftPaddle.getScore());
                leftPaddleScore.setString(left);
            }

            ball.setXPosition(640);
            ball.setYPosition(360);
            ball.setXSpeed();
        }

        ball.updatePosition();
        ballFX.setPosition(ball.getXPosition(), ball.getYPosition());

        leftP.setPosition(leftPaddle.getXPosition(), leftPaddle.getYPosition());
        rightP.setPosition(rightPaddle.getXPosition(), rightPaddle.getYPosition());

        window.clear();

        window.draw(ballFX);
        window.draw(leftP);
        window.draw(rightP);
        window.draw(text);
        window.draw(leftPaddleScore);
        window.draw(rightPaddleScore);

        window.display();


    }

    return 0;
}

