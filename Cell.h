#pragma once
#include "Player.h"
#include "Event.h"

class Cell {
private:
    bool active; //���������
    bool wall; //����������
    Event* event; //��������� ������������ ������ �� ��������
    bool reaction;

public:
    Cell();
    Cell(bool active, bool wall);
    void SetActive(bool);
    void SetWall(bool);
    void SetReaction(bool);
    void SetPlayersEvents(Event*);
    // ��� ������ ����������� ������ ������������ �� ��, ��� ����� ������� �� ������.
    bool GetActive(); //�� ������ �� �����? - ��������
    bool GetWall();
    bool GetReaction();
    // ��� ������ ����������� ������, ����������� �������� �������. (�� ���� ������ � ���� ���� ����� ����������� ��������)
    void ChangeActive();
    void ChangeWall();
    void ChangeReaction();
};