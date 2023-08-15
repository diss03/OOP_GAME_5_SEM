#pragma once
#include "FieldEvent.h"
class ChangeFieldEvent :public FieldEvent
{
public:
	ChangeFieldEvent(Field*);
	void execute() override;
};

