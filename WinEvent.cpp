#include "WinEvent.h"
#include "iostream"

void WinEvent::execute(void* ptr) {
	Player* player = (Player*)ptr;
	if (player->GetBank() >= 3 and player->GetHealth() > 0) {
		std::cout << "U WIN!!!" << std::endl;
	}
}