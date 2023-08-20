#pragma once
#include "PlayerEvent.h"
class WinEvent: public PlayerEvent
{
public:
	WinEvent(Player*);
	void execute(InfoLog*) override;
};


