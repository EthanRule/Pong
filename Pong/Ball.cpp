#include "Ball.hpp"
#include <vector>

Ball::Ball(int xPosition, int yPosition, int radius)
{
	this->radius = radius;
	this->xSpeed = -.05;
	this->ySpeed = 0;
	this->xPosition = xPosition + radius;
	this->yPosition = yPosition - radius;
}

double Ball::getXSpeed() {
	return this->xSpeed;
}

double Ball::getYSpeed() {
	return this->ySpeed;
}

double Ball::getXPosition() {
	return this->xPosition;
}

double Ball::getYPosition() {
	return this->yPosition;
}

void Ball::setXPosition(double xPosition) {
	this->xPosition = xPosition;
}

void Ball::setYPosition(double yPosition) {
	this->yPosition = yPosition;
}

void Ball::determineLocation(bool left, double part) {
	int partVal = 0;

	if (part > .6) {
		partVal = 1;
	} else if (part <= .6 && part >= .4) {
		partVal = 0;
	} else if (part < .4) {
		partVal = -1;
	}
	
	if (left) {
		switch (partVal) {
		case 1:
			this->xSpeed = .1;
			this->ySpeed = .1;
			break;
		case 0:
			this->xSpeed = .1;
			break;
		case -1:
			this->xSpeed = .1;
			this->ySpeed = -.1;
			break;
		default:
			this->xSpeed = .1;
			break;
		}
	}
	else {
		switch (partVal) {
		case 1:
			this->xSpeed = -.1;
			this->ySpeed = .1;
			break;
		case 0:
			this->xSpeed = -.1;
			break;
		case -1:
			this->xSpeed = -.1;
			this->ySpeed = -.1;
			break;
		default:
			this->xSpeed = -.1;
			break;
		}
	}
}

void Ball::updatePosition() {
	this->xPosition += xSpeed;
	this->yPosition += ySpeed;
}

int Ball::getRadius() {
	return this->radius;
}
