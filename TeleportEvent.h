#pragma once
#include "FieldEvent.h"

class TeleportEvent :public FieldEvent
{
	void execute(void* ptr) override;
};

