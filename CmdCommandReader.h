#pragma once
#include "CommandReader.h"

class CmdCommandReader : public CommandReader
{
public:
	void SetStep(sf::RenderWindow*) final;
};

