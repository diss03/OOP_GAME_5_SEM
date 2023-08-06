#pragma once
class Player 
{
private:
    int bank; //хранение от 0 до 3 монет
    int health; //до 100 очков
    int armor; //до 100 очков
    bool end;
public:
    Player(int, int, int);

    int GetBank();
    int GetHealth();
    int GetArmor();
    bool GetEnd();

    void SetBank(int);
    void SetHealth(int);
    void SetArmor(int);
    void SetEnd(bool);
};