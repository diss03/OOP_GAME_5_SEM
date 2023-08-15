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
    // ƒл€ клетки реализованы методы реагировани€ на то, что игрок перешел на клетку.
    bool GetActive(); //на клетке ли игрок? - проверка
    bool GetWall();
    //bool GetReaction();//осталось ли событие или нет
    Event* GetEvent();
    OBJECTS GetObject();
    //Event* GetEventType();
    // ƒл€ клетки реализованы методы, позвол€ющие замен€ть событие. (“о есть клетка в ходе игры может динамически мен€тьс€)
    void ChangeActive();
    void ChangeWall();
    //void ChangeReaction();
    void UseEvent();
    //~Cell();
    ~Cell() = default;

   
private:
    bool active; //состо€ние
    bool wall; //преп€тсвие
    Event* event; //экземпл€р абстрактного класса не разрешен
    //bool reaction;
    OBJECTS object;
};