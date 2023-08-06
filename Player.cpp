#include "Player.h"
#include <iostream>

Player::Player(int health = 100, int bank = 0, int armor = 0) : health(health), bank(bank), armor(armor) {
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

bool Player::GetEnd() {
	return end;
}

void Player::SetBank(int b) {
	bank = b;
	if (bank > 3)
	{
		std::cout << "Банк заполнен максимально!" << std::endl;
		bank = 3;
	}
}

void Player::SetHealth(int h) {
	health = h;
	if (health > 100)
	{
		std::cout << "Здоровье максимально!" << std::endl;
		health = 100;
	}
}

void Player::SetArmor(int a) {
	armor = a;
	if (armor > 100)
	{
		std::cout << "Защита максимальна!" << std::endl;
		armor = 100;
	}
}


void Player::SetEnd(bool e) {
	end = end;
}