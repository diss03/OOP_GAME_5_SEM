#pragma once
#include "PlayerEvent.h"

class DamageEvent :public PlayerEvent
{
public:
	DamageEvent(Player*);
	void execute() override;
};

