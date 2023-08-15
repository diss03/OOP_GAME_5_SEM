#include "HpEvent.h"

HpEvent::HpEvent(Player* player) {
	this->player = player;
}

void HpEvent::execute() {
	player->SetHealth(player->GetHealth() + 10);
	std::cout << "Player was healed!" << std::endl;
}