#pragma once
#include "PlayerEvent.h"

class BankEvent :public PlayerEvent
{
	void execute(void* ptr) override;
};

