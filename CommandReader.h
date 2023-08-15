#pragma once
#include <SFML/Graphics.hpp>
class CommandReader
{
private:
	int height;
	int width;
	sf::Event step;

public:
	CommandReader();

	void SetSize();
	void InputHeight();
	void InputWidth();
	void InputStep(sf::RenderWindow*);

	int GetHeight();
	int GetWidth();
	sf::Event GetStep();
};

