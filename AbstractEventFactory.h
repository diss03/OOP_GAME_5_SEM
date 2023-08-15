#pragma once
#include "Event.h"

class AbstractEventFactory
{
public:
	virtual Event* CreateEvent() = 0;
	//virtual ~AbstractEventFactory();
};

