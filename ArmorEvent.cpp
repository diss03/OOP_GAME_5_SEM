#include "ArmorEvent.h"
#include "iostream"

void ArmorEvent::execute(void* ptr)
{
    Player* player = (Player*)ptr;
    player->SetArmor(player->GetArmor() + 10);
    std::cout << "picked up armor" << std::endl;
}


