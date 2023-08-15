#pragma once
#include "FieldView.h"
#include "CommandReader.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Controller 
{
private:
	Field* field;
	FieldView fieldw;
	Player* player;
	CommandReader* comread;
	

public:
	Controller();
	Controller(CommandReader*);
	void Move();
};