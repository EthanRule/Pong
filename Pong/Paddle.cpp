#include "Paddle.hpp"
#include <SFML/Graphics.hpp>

Paddle::Paddle(int xPosition, int yPosition, sf::Color color) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->color = color;
	this->paddleSpeed = 10;
}

int Paddle::getXPosition() {
	return this->xPosition;
}

int Paddle::getYPosition() {
	return this->yPosition;
}

sf::Color Paddle::getColor() {
	return this->color;
}

void Paddle::changeXPosition(int xPosition) {
	this->xPosition = xPosition;
}

void Paddle::changeYPosition(int yPosition) {
	this->yPosition = yPosition;
}

void Paddle::updatePosition(bool up) {
	this->yPosition -= up ? this->paddleSpeed: this->paddleSpeed * -1;
	restrictPaddlePosition();
}

void Paddle::restrictPaddlePosition() {
	if (this->yPosition < 0) {
		this->yPosition = 0;
	}

	if (this->yPosition > 620) {
		this->yPosition = 620;
	}
}
