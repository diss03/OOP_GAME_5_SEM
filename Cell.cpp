#include <iostream>
#include "Cell.h"

Cell::Cell() {
    this->active = false;
    this->wall = false;
    this->event = nullptr;
    this->object = COMMON;
}

Cell::Cell(bool active, bool wall) {
    this->active = active;
    this->wall = wall;
    this->event = nullptr;
    this->object = COMMON;
}

bool Cell::GetActive() {
    return active;
}

bool Cell::GetWall() {
    return wall;
}

//bool Cell::GetReaction() {
//    return reaction;
//}

Event* Cell::GetEvent() {
    return event;
}


Cell::OBJECTS Cell::GetObject() {
    return object;
}

void Cell::SetActive(bool a) {
    active = a;
}

void Cell::SetWall(bool w) {
    wall = w;
}

//void Cell::SetReaction(bool r) {
//    reaction = r;
//}

void Cell::SetPlayersEvents(Event* event) {
    //if (this->event == nullptr)
        this->event = event;
        if (this->event) {
            new GameObserver(this->event);
        }
}

void Cell::SetObject(OBJECTS obj) {
    object = obj;
}

//void Cell::SetEvent(EVENTS obj) {
//    object = obj;
//}

void Cell::ChangeActive() {
    active ? active = false : active = true;
}

void Cell::ChangeWall() {
    wall ? wall = false : wall = true;
}

//void Cell::ChangeReaction() {
//    reaction ? reaction = false : reaction = true;
//}

void Cell::UseEvent(InfoLog* log_info) {
    if (event != nullptr) {
        event->execute(log_info);
        if (object != Cell::WIN)
            event = nullptr;
    }
}



//Event* Cell::GetEventType() {
//    return event;
//}

//Cell::~Cell() {
//    active = false;
//    wall = false; //преп€тсвие
//    event = nullptr; //экземпл€р абстрактного класса не разрешен
//    //bool reaction;
//    object = COMMON;
//}