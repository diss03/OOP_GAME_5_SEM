#pragma once
#include "PlayerEvent.h"

class HpEvent :public PlayerEvent
{
	void execute(void* ptr) override;
};

