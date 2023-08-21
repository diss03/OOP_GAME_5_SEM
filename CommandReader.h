#pragma once
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include "Subject.h"
#include "ErrorObserver.h"
#include "GameObserver.h"
#include "StatusObserver.h"

#include "Assigments.h"
#include "FileInput.h"


class CommandReader : public Subject
{
protected:
	int height;
	int width;
	
	//sf::Event step;
	ASSIGMENTS step;

	InfoLog* info;
	std::vector <OUTPUT> outputs;
	std::vector <LEVEL> levels;

	FileInput* input_commands;

public:
	CommandReader();

	void SetSize();
	void InputHeight();
	void InputWidth();
	//void InputStep(sf::RenderWindow*);
	virtual void SetStep(sf::RenderWindow*) = 0;

	void SetOutput();
	void SetLevels();

	int GetHeight();
	int GetWidth();

	ASSIGMENTS GetStep();
	//sf::Event GetStep();

	std::vector <OUTPUT> GetOutputs();
	std::vector <LEVEL> GetLevels();

	
};

