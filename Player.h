#pragma once
class Player 
{
private:
    int bank; //хранение от 0 до 3 монет
    int health; //до 100 очков
    int armor; //до 100 очков
    bool end; //true - конец игры
public:
    Player();
    Player(int, int, int);
    // конструктор копирования(объект создается и копируется)
    Player(const Player&);
    Player& operator=(const Player&);

    int GetBank();
    int GetHealth();
    int GetArmor();
    bool GetEnd();

    void SetBank(int);
    void SetHealth(int);
    void SetArmor(int);
    void SetEnd(bool);
};