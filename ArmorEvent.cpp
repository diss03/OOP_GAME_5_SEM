#include "ArmorEvent.h"
#include "iostream"

ArmorEvent::ArmorEvent(Player* player) {
    this->player = player;
}

void ArmorEvent::execute(InfoLog* text)
{
    player->SetArmor(player->GetArmor() + 10);
    Message message(GAME, "picked up an armor point", text);
    Notify(message);
}


