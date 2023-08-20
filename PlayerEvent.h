#pragma once
#include "Event.h"
#include "Player.h"

class PlayerEvent: public Event
{
public:
	void execute(InfoLog*) = 0;
protected:
	Player* player;
};

