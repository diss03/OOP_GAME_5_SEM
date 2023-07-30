#include <iostream>
#include "Cell.h"

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

void Cell::SetActive(bool a) {
    active = a;
}

void Cell::SetWall(bool w) {
    wall = w;
}

void Cell::ChangeActive() {
    this->active ? this->active = false : this->active = true;
}

void Cell::ChangeWall() {
    this->wall ? this->wall = false : this->active = true;
}