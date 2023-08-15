#include <iostream>
#include "Controller.h"
#include "CommandReader.h"

int main() {
    CommandReader comreader;
    comreader.SetSize();
    Controller ctrl(&comreader);
    ctrl.Move();
}