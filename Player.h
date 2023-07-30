#pragma once
class Player 
{
private:
    int bank; //хранение от 0 до 3 монет
    int health;
    int armor;
public:
    Player(int, int, int);

    int GetBank();
    int GetHealth();
    int GetArmor();

    void SetBank(int);
    void SetHealth(int);
    void SetArmor(int);
};