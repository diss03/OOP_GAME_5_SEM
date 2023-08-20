#include "WinEvent.h"
#include "iostream"

WinEvent::WinEvent(Player* player) {
	this->player = player;
}


void WinEvent::execute(InfoLog* text) {
	if (player->GetBank() >= 3 and player->GetHealth() > 0) {
		player->SetEnd(true);

		Message message(GAME, "the win event was completed", text);
		Notify(message);
	}
}