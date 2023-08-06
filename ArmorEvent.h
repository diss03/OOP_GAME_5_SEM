#pragma once
#include "PlayerEvent.h"

class ArmorEvent :public PlayerEvent
{
	void execute(void* ptr) override;
};

