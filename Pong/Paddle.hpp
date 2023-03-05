#include <iostream>
#include <SFML/Graphics.hpp>

class Paddle {
public:
	// Constructors
	Paddle(int xPosition, int yPosition, sf::Color color);

	// Getters
	int getXPosition();
	int getYPosition();
	sf::Color getColor();

	// Setters
	void changeXPosition(int xPosition);
	void changeYPosition(int yPosition);
	void updatePosition(bool up);

private:
	int xPosition;
	int yPosition;
	int paddleSpeed;
	sf::Color color;

	void restrictPaddlePosition();
};