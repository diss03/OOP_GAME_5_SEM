#pragma once
#include "PlayerEvent.h"

class HpEvent :public PlayerEvent
{
public:
	HpEvent(Player*);
	void execute() override;
};

