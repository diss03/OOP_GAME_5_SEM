#pragma once
#include "FieldView.h"
#include "CommandReader.h"

class Controller 
{
private:
	bool end;
	FieldView field;
	CommandReader comread;
public:
	Controller();
	Controller(CommandReader);
	void Move();
	void Start();

	void SetEnd(bool e) {
		end = e;
	}

	bool GetEnd() {
		return end;
	}
};