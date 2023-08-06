#include "HpEvent.h"


void HpEvent::execute(void* ptr) {
	Player* player = (Player*)ptr;
	player->SetHealth(player->GetHealth() + 10);
	std::cout << "Player was healed!" << std::endl;
}