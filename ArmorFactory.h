#pragma once
#include "AbstractEventFactory.h"
#include "ArmorEvent.h"

class ArmorFactory : public AbstractEventFactory {
public:
	Event* CreateEvent() override;
};

