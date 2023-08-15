#pragma once
#include "AbstractEventFactory.h"
#include "ChangeFieldEvent.h"

class ChangeFieldFactory :public AbstractEventFactory
{
public:
	Event* CreateEvent() override;
};

