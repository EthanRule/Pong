#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Ball {
public:
	Ball(int direction);

private:
	double ySpeed;
	double xSpeed;
	int speed;
	int radius;
};