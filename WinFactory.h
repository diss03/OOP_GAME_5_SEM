#pragma once
#include "AbstractEventFactory.h"
#include "WinEvent.h"

class WinFactory : public AbstractEventFactory
{
public:
	Event* CreateEvent() override;
};

