#pragma once
#include "Player.h"
#include "Event.h"

class Cell {
private:
    bool active; //состояние
    bool wall; //препятсвие
    Event* event; //экземпляр абстрактного класса не разрешен
    bool reaction;

public:
    Cell();
    Cell(bool active, bool wall);
    void SetActive(bool);
    void SetWall(bool);
    void SetReaction(bool);
    void SetPlayersEvents(Event*);
    // Для клетки реализованы методы реагирования на то, что игрок перешел на клетку.
    bool GetActive(); //на клетке ли игрок? - проверка
    bool GetWall();
    bool GetReaction();
    // Для клетки реализованы методы, позволяющие заменять событие. (То есть клетка в ходе игры может динамически меняться)
    void ChangeActive();
    void ChangeWall();
    void ChangeReaction();
};