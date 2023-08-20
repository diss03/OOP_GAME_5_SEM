#pragma once
#include "PlayerEvent.h"

class BankEvent :public PlayerEvent
{
public:
	BankEvent(Player*);
	void execute(InfoLog*) override;
};

