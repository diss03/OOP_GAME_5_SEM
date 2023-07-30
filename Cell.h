#pragma once
#include "Player.h"
#include "Event.h"

class Cell {
private:
    bool active; //состояние
    bool wall; //препятсвие
    Event* event; //экземпляр абстрактного класса не разрешен

public:
    //Cell(int, int);
    Cell(bool active = false, bool wall = false);
    void SetActive(bool);
    void SetWall(bool);
    // Для клетки реализованы методы реагирования на то, что игрок перешел на клетку.
    bool GetActive(); //на клетке ли игрок? - проверка
    bool GetWall();
    // Для клетки реализованы методы, позволяющие заменять событие. (То есть клетка в ходе игры может динамически меняться)
    void ChangeActive();
    void ChangeWall();
};