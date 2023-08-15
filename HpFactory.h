#pragma once
#include "AbstractEventFactory.h"
#include "HpEvent.h"

class HpFactory : public AbstractEventFactory
{
public:
	Event* CreateEvent() override;
};
