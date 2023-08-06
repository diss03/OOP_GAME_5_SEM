#pragma once
#include "Event.h"
#include "Field.h"

class FieldEvent : Event
{
	void execute(void* ptr) = 0;
};

