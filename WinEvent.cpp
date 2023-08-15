#include "WinEvent.h"
#include "iostream"

WinEvent::WinEvent(Player* player) {
	this->player = player;
}


void WinEvent::execute() {
	if (player->GetBank() >= 3 and player->GetHealth() > 0) {
		std::cout << "U WIN!!!" << std::endl;
		player->SetEnd(true);
	}
}