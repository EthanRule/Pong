#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Ball {
public:
	Ball(int speed, int radius);

private:
	vector<double> ballSpeedPosition;

	int radius;
};