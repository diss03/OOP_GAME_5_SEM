#include "BankEvent.h"
#include "iostream"

BankEvent::BankEvent(Player* player) {
	this->player = player;
}


void BankEvent::execute() {
	player->SetBank(player->GetBank() + 1);
}