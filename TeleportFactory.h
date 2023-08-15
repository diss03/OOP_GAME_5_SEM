#pragma once
#include "AbstractEventFactory.h"
#include "TeleportEvent.h"

class TeleportFactory : public AbstractEventFactory
{
public:
	Event* CreateEvent() override;
};


