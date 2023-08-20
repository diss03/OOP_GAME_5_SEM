#pragma once
#include "Event.h"
#include "Field.h"

class FieldEvent :public Event
{
public:
	void execute(InfoLog*) = 0;
protected:
	Field* field;
};

