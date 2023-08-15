#pragma once
#include "AbstractEventFactory.h"
#include "DamageEvent.h"

class DamageFactory : public AbstractEventFactory
{
public:
	Event* CreateEvent() override;
};
