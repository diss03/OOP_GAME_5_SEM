#pragma once
class Player 
{
private:
    int bank; //�������� �� 0 �� 3 �����
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