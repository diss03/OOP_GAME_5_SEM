#pragma once
#include "Field.h"
#include "Player.h"
#include "Event.h"
#include "ArmorEvent.h"
#include "BankEvent.h"
#include "ChangeFieldEvent.h"
#include "HpEvent.h"
#include "DamageEvent.h"
#include "TeleportEvent.h"
#include "WinEvent.h"

class EventCreator
{
private:
    Field* field;
    Player* player;

public:
    EventCreator(Field*, Player*);
    Event* CreateArmorEventEvent();
    Event* CreateHpEvent();
    Event* CreateBankEvent();
    Event* CreateChangeFieldEvent();
    Event* CreateDamageEvent();
    Event* CreateTeleportEvent();
    Event* CreateWinEvent();
};

