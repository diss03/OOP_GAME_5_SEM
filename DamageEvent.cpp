#include "DamageEvent.h"


void DamageEvent::execute(void* ptr) {
	Player* player = (Player*)ptr;
	player->SetHealth(player->GetHealth() - 10);
	std::cout << "Player was kicked!" << std::endl;
}