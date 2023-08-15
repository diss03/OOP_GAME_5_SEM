#pragma once
#include "Player.h"
#include "Event.h"


class Cell {

public:
    enum OBJECTS {
        COMMON = 1,
        ARMOR,
        BANK,
        CHANGEFIELD,
        DAMAGE,
        HP,
        TELEPORT,
        WIN,
        WALL
    };
    Cell();
    Cell(bool active, bool wall);
    void SetActive(bool);
    void SetWall(bool);
    //void SetReaction(bool);
    void SetPlayersEvents(Event*);
    void SetObject(OBJECTS);
    // ��� ������ ����������� ������ ������������ �� ��, ��� ����� ������� �� ������.
    bool GetActive(); //�� ������ �� �����? - ��������
    bool GetWall();
    //bool GetReaction();//�������� �� ������� ��� ���
    Event* GetEvent();
    OBJECTS GetObject();
    //Event* GetEventType();
    // ��� ������ ����������� ������, ����������� �������� �������. (�� ���� ������ � ���� ���� ����� ����������� ��������)
    void ChangeActive();
    void ChangeWall();
    //void ChangeReaction();
    void UseEvent();
    //~Cell();
    ~Cell() = default;

   
private:
    bool active; //���������
    bool wall; //����������
    Event* event; //��������� ������������ ������ �� ��������
    //bool reaction;
    OBJECTS object;
};