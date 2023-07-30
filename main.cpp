#include <iostream>
#include "Controller.h"
#include "Controller.h"

int main() {
    CommandReader comreader;
    comreader.InputHeight();
    comreader.InputWidth();
    Controller ctrl(comreader);
    ctrl.Move();
}