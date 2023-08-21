#include "UiCommandReader.h"

void UiCommandReader::SetStep(sf::RenderWindow* window) {
	sf::Event ev_step;
	char char_step;
	window->pollEvent(ev_step);
	if (ev_step.type == sf::Event::KeyPressed and ev_step.key.code <= 25 and ev_step.key.code >= 0) {
		char_step = char(97 + ev_step.key.code);
		std::cout << "CODE: " << ev_step.key.code << std::endl;
		this->step = input_commands->GetAction(char_step);
		std::cout << "Tupe: " << this->step << std::endl;
	}
	else this->step = NOTHING;
}
