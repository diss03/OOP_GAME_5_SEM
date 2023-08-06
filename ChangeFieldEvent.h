#pragma once
#include "FieldEvent.h"
class ChangeFieldEvent :public FieldEvent
{
	void execute(void* ptr) override;
};

