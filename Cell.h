#pragma once
#include "Player.h"
#include "Event.h"

class Cell {
private:
    bool active; //���������
    bool wall; //����������
    Event* event; //��������� ������������ ������ �� ��������

public:
    //Cell(int, int);
    Cell(bool active = false, bool wall = false);
    void SetActive(bool);
    void SetWall(bool);
    // ��� ������ ����������� ������ ������������ �� ��, ��� ����� ������� �� ������.
    bool GetActive(); //�� ������ �� �����? - ��������
    bool GetWall();
    // ��� ������ ����������� ������, ����������� �������� �������. (�� ���� ������ � ���� ���� ����� ����������� ��������)
    void ChangeActive();
    void ChangeWall();
};