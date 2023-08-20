#pragma once
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include "Subject.h"
#include "ErrorObserver.h"
#include "GameObserver.h"
#include "StatusObserver.h"


class CommandReader : public Subject
{
private:
	int height;
	int width;
	
	sf::Event step;

	InfoLog* info;
	std::vector <OUTPUT> outputs;
	std::vector <LEVEL> levels;

public:
	CommandReader();

	void SetSize();
	void InputHeight();
	void InputWidth();
	void InputStep(sf::RenderWindow*);

	void SetOutput();
	void SetLevels();

	int GetHeight();
	int GetWidth();

	sf::Event GetStep();

	std::vector <OUTPUT> GetOutputs();
	std::vector <LEVEL> GetLevels();
};

