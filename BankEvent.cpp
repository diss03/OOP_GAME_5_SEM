#include "BankEvent.h"
#include "iostream"

void BankEvent::execute(void *ptr) {
	Player* player = (Player*) ptr;
	player->SetBank(player->GetBank() + 1);
}