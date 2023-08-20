#pragma once
#include "PlayerEvent.h"

class ArmorEvent :public PlayerEvent
{
public:
	ArmorEvent(Player*);
	void execute(InfoLog*) override;
};

