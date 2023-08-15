#pragma once
#include "AbstractEventFactory.h"
#include "BankEvent.h"

class BankFactory : public AbstractEventFactory
{
public:
	Event* CreateEvent() override;
};

