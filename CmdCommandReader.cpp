#include "CmdCommandReader.h"


void CmdCommandReader::SetStep(sf::RenderWindow*) {
	char char_step;
	std::cout << "Input commmand char" << std::endl;
	std::cin >> char_step;
	this->step = input_commands->GetAction(char_step);
}