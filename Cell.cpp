#include <iostream>
#include "Cell.h"

Cell::Cell() {
    this->active = false;
    this->wall = false;
}

Cell::Cell(bool active, bool wall) {
    this->active = active;
    this->wall = wall;
}

bool Cell::GetActive() {
    return active;
}

bool Cell::GetWall() {
    return wall;
}

bool Cell::GetReaction() {
    return reaction;
}

void Cell::SetActive(bool a) {
    active = a;
}

void Cell::SetWall(bool w) {
    wall = w;
}

void Cell::SetReaction(bool r) {
    reaction = r;
}

void Cell::SetPlayersEvents(Event* event) {
    if (this->event == nullptr)
        this->event = event;
}

void Cell::ChangeActive() {
    active ? active = false : active = true;
}

void Cell::ChangeWall() {
    wall ? wall = false : wall = true;
}

void Cell::ChangeReaction() {
    reaction ? reaction = false : reaction = true;
}