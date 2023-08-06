#include "Controller.h"
#include "iostream"
#include <cstdio>

Controller::Controller() {}

Controller::Controller(CommandReader comread) : comread(comread) {
    FieldView fieldw(comread.GetHeight(), comread.GetWidth());
    this->field = fieldw; //используем коснтруктор поля через наследование, и конструктор перемещения
}

// ńîçäŕĺě ýęçĺěďë˙đ ęëŕńńŕ ďîëĺ č óćĺ ń íčě đŕáîňŕĺě, čěĺ˙ ďđč ńĺáĺ ýęçĺěďë˙đ ęëŕńńŕ ęîěěŕíä-đčäĺđ čç ěýéíŕ//

void Controller::Move() {
    field.Print();
    while (!end) {
        comread.InputStep();
        //Move(comread.GetStep());
        switch (comread.GetStep())
        {
        case 'w':
            system("cls");
            field.MoveUp();
            field.Print();
            break;

        case 's':
            system("cls");
            field.MoveDown();
            field.Print();
            break;

        case 'd':
            system("cls");
            field.MoveRight();
            field.Print();
            break;

        case 'a':
            system("cls");
            field.MoveLeft();
            field.Print();
            break;

        default:
            std::cout << "Incorrect command!" << std::endl;
            SetEnd(true);
            break;

        }

    }
    std::cout << "game over!" << std::endl;
}