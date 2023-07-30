#pragma once
class CommandReader
{
private:
	int height;
	int width;
	char step;

public:
	CommandReader();

	void InputHeight();
	void InputWidth();
	void InputStep();

	int GetHeight();
	int GetWidth();
	char GetStep();
};

