#pragma once
#include "FieldEvent.h"

class TeleportEvent :public FieldEvent
{
public:
	TeleportEvent(Field*);
	void execute(InfoLog*) override;
};

