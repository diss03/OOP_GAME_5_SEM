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

#include "FieldGenerator.h"
#include "Armor.h"
#include "Bank.h"
#include "ChangeField.h"
#include "Damage.h"
#include "FiledBase.h"
#include "Hp.h"
#include "Teleport.h"

#include "SaveLoadField.h"
#include "SaveLoadPlayer.h"


class Controller : public Subject
{
private:
	Field* field;
	FieldView fieldw;
	Player* player;
	CommandReader* comread;
	InfoLog* log_info;
	ASSIGMENTS step;
	DIFFICULTY difficulty;

	SaveLoadField* save_load_field;
	SaveLoadPlayer* save_load_player;

	//Field* copy_field;
	//Player* copy_player;

public:
	//Controller() = default;
	Controller(CommandReader*, InfoLog*, DIFFICULTY);

	void FieldGanerate();
	void Move();
};