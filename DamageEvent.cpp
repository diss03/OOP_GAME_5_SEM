#include "DamageEvent.h"

DamageEvent::DamageEvent(Player* player) {
	this->player = player;
}

void DamageEvent::execute() {
	if (player->GetArmor() >= 20)
		player->SetArmor(player->GetArmor() - 20);
	else 
		player->SetHealth(player->GetHealth() - 20);
	std::cout << "Player was kicked!" << std::endl;
}