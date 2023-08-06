#pragma once
#include "PlayerEvent.h"

class DamageEvent :public PlayerEvent
{
	void execute(void* ptr) override;
};

