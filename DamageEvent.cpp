#include "DamageEvent.h"

DamageEvent::DamageEvent(Player* player) {
	this->player = player;
}

void DamageEvent::execute(InfoLog* text) {
	if (player->GetArmor() >= 20)
		player->SetArmor(player->GetArmor() - 20);
	else 
		player->SetHealth(player->GetHealth() - 20);
	Message message(GAME, "player was kicked", text);
	Notify(message);
}