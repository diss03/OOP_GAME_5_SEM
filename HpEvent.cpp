#include "HpEvent.h"

HpEvent::HpEvent(Player* player) {
	this->player = player;
}

void HpEvent::execute(InfoLog* text) {
	player->SetHealth(player->GetHealth() + 10);
	Message message(GAME, "player picked up a heal point", text);
	Notify(message);
}