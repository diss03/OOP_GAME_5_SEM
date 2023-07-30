#include "Player.h"
#include <iostream>

Player::Player(int health = 3, int bank = 0, int armor = 0) : health(health), bank(bank), armor(armor) {
}

int Player::GetBank() {
	return bank;
}

int Player::GetHealth() {
	return health;
}

int Player::GetArmor() {
	return armor;
}

void Player::SetBank(int b) {
	bank = b;
}

void Player::SetHealth(int h) {
	health = h;
}

void Player::SetArmor(int a) {
	armor = a;
}