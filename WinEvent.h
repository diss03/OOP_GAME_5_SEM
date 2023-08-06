#pragma once
#include "PlayerEvent.h"
class WinEvent: public PlayerEvent
{
	void execute(void* ptr) override;
};

