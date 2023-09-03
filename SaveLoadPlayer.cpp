#include "SaveLoadPlayer.h"
#include "iostream"

void SaveLoadPlayer::savePlayer(Player* player) {

    file_input.open(filename, std::ios_base::out | std::ios_base::trunc);

    if (!file_input.is_open()) {
        throw FileExeption("ñould not open file " + filename);
    }

    file_input << player->GetHealth() << '\n';
    file_input << player->GetBank() << '\n';
    file_input << player->GetArmor() << '\n';

    file_input << '$' << '\n';
    file_input.close();
}

Player* SaveLoadPlayer::loadPlayer(Player* player) {

    file_output.open(filename, std::ios_base::in);
    if (!file_output.is_open()) {
        throw FileExeption("ñould not open file" + filename);
    }

    if (file_output.peek() == EOF) {
        file_output.close();
        throw LoadExeption("file " + filename + "is empty!");
    }

    int hp, bank, armor;
    file_output >> hp;
    file_output >> bank;
    file_output >> armor;


    if (hp <= 0 or hp > 100 or bank < 0 or bank > 3 or armor < 0 or armor > 100) {
        file_output.close();
        throw LoadExeption("incorrect player's data!");
    }

    player->SetHealth(hp);
    player->SetBank(bank);
    player->SetArmor(armor);

    file_output.close();
    return player;
}