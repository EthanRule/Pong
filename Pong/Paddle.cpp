#include "Paddle.hpp"


Paddle::Paddle(int xPosition, int yPosition, sf::Color color) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->color = color;
	this->paddleSpeed = 5;
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

void Paddle::updatePosition() {
	this->updatePaddleSpeed();
	this->yPosition -= this->paddleSpeed;
}

void Paddle::updatePaddleSpeed() {
	if (this->yPosition < 0 || this->yPosition > 620) {
		this->paddleSpeed *= -1;
	}
}
