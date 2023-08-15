#include "EventCreator.h"
EventCreator::EventCreator(Field* field, Player* player) {
	this->field = field;
	this->player = player;
}

Event* EventCreator::CreateArmorEventEvent() {
	return new ArmorEvent(player);
}

Event* EventCreator::CreateHpEvent() {
	return new HpEvent(player);
}

Event* EventCreator::CreateBankEvent() {
	return new BankEvent(player);
}

Event* EventCreator::CreateChangeFieldEvent() {
	return new ChangeFieldEvent(field);
}

Event* EventCreator::CreateDamageEvent() {
	return new DamageEvent(player);
}

Event* EventCreator::CreateTeleportEvent() {
	return new TeleportEvent(field);
}

Event* EventCreator::CreateWinEvent() {
	return new WinEvent(player);
}