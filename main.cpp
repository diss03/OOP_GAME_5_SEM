#include <iostream>
#include "Controller.h"
#include "CommandReader.h"

int main() {
    CommandReader comreader;
    comreader.SetLevels();
    comreader.SetOutput();
    
    InfoLog* logout_info = new InfoLog(comreader.GetOutputs(), comreader.GetLevels());

    comreader.SetSize();

    Controller ctrl(&comreader, logout_info);
    ctrl.Move();
}