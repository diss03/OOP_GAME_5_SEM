#pragma once
#include "FieldView.h"
#include "CommandReader.h"
#include "Player.h"

#include "Enums.h"
#include "InfoLog.h"
#include "Subject.h"
#include "GameObserver.h"
#include "StatusObserver.h"

#include <SFML/Graphics.hpp>

class Controller : public Subject
{
private:
	Field* field;
	FieldView fieldw;
	Player* player;
	CommandReader* comread;
	InfoLog* log_info;
	ASSIGMENTS step;
	

public:
	Controller() = default;
	Controller(CommandReader*, InfoLog*);
	void Move();
};