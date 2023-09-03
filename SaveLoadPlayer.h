#pragma once
#include "Player.h"
#include "fstream"
#include "Hashing.h"

class SaveLoadPlayer : Hashing
{
public:
    void savePlayer(Player*);
    Player* loadPlayer(Player*);
};

