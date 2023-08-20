#include "Player.h"
#include <iostream>

Player::Player() {
	health = 100;
	bank = 0;
	armor = 0;
	end = false;
}

Player::Player(int health, int bank, int armor){
	this->health = health;
	this->bank = bank;
	this->armor = armor;
	this->end = false;
}

Player::Player(const Player& copy) : health(copy.health), bank(copy.bank), armor(copy.armor), end(end) {
}

Player& Player::operator=(const Player& other) {
	// провер€ем на самоприсваивание
	if (this == &other)
		return *this;
	// перезаписываем
	health = other.health;
	bank = other.bank;
	armor = other.armor;
	end = other.end;
	return *this;
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
		//std::cout << "Ѕанк заполнен максимально!" << std::endl;
		bank = 3;
	}
}

void Player::SetHealth(int h) {
	health = h;
	if (health > 100)
	{
		//std::cout << "«доровье максимально!" << std::endl;
		health = 100;
	}
}

void Player::SetArmor(int a) {
	armor = a;
	if (armor > 100)
	{
		//std::cout << "«ащита максимальна!" << std::endl;
		armor = 100;
	}
	if (armor < 0)
	{
		//std::cout << "Armor have been used!" << std::endl;
		armor = 0;
	}
}


void Player::SetEnd(bool e) {
	end = e;
}