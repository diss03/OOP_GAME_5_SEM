#pragma once
#include "CommandReader.h"

class UiCommandReader : public CommandReader
{
	void SetStep(sf::RenderWindow*) final;
};