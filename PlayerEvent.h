#pragma once
#include "Event.h"
#include "Player.h"

class PlayerEvent: public Event
{
	void execute(void* ptr) = 0;
};

