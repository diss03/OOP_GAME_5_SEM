#include "BankEvent.h"
#include "iostream"

BankEvent::BankEvent(Player* player) {
	this->player = player;
}


void BankEvent::execute(InfoLog* text) {
	player->SetBank(player->GetBank() + 1);
	Message message(GAME, "picked up a coin", text);
	Notify(message);
}