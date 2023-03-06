#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Ball {
public:
	Ball(int xPosition, int yPosition, int radius);

	double getXPosition();
	double getYPosition();
	double getXSpeed();
	double getYSpeed();
	void setYSpeed();
	void setXSpeed();
	int getRadius();

	void setXPosition(double xPosition);
	void setYPosition(double yPosition);

	void determineLocation(bool left, double part);
	void updatePosition();


private:
	double yPosition;
	double xPosition;
	double xSpeed;
	double ySpeed;
	int radius;
};