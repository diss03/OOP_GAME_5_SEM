#include "ArmorEvent.h"
#include "iostream"

ArmorEvent::ArmorEvent(Player* player) {
    this->player = player;
}

void ArmorEvent::execute()
{
    player->SetArmor(player->GetArmor() + 10);
    std::cout << "picked up armor" << std::endl;
}


