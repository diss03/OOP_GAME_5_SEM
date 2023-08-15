#pragma once
class Player 
{
private:
    int bank; //�������� �� 0 �� 3 �����
    int health; //�� 100 �����
    int armor; //�� 100 �����
    bool end; //true - ����� ����
public:
    Player();
    Player(int, int, int);
    // ����������� �����������(������ ��������� � ����������)
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