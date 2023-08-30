#include "Mediator.h"
#include <iostream>

#include "CommandReader.h"
#include "Controller.h"
#include "CmdCommandReader.h"
#include "UiCommandReader.h"


//template <typename T> 
//void changeMode(T) {
//    T->SetLevels();
//    T->SetOutput();
//    InfoLog* logout_info = new InfoLog(T->GetOutputs(), T->GetLevels());
//    T->SetSize();
//    Controller ctrl(T, logout_info);
//    ctrl.Move();
//}

void Mediator::Start() {
    char res;
    std::cout << "Select the command input mode:" << std::endl;
    std::cout << "1: CMD" << std::endl;
    std::cout << "2: UI" << std::endl;
    std::cin >> res;
    switch (res) {
        case '1':
        {
            CmdCommandReader* comreader = new CmdCommandReader();
            //changeMode(comreader);
            comreader->SetLevels();
            comreader->SetOutput();
            comreader->SetDifficulty();
            InfoLog* logout_info = new InfoLog(comreader->GetOutputs(), comreader->GetLevels());
            comreader->SetSize();
            Controller ctrl(comreader, logout_info, comreader->GetDifficulty());
            ctrl.FieldGanerate();
            ctrl.Move();
            break;
        }
        case '2':
        {
            UiCommandReader* comreader = new UiCommandReader();
            //changeMode(comreader);
            comreader->SetLevels();
            comreader->SetOutput();
            comreader->SetDifficulty();
            InfoLog* logout_info = new InfoLog(comreader->GetOutputs(), comreader->GetLevels());
            comreader->SetSize();
            Controller ctrl(comreader, logout_info, comreader->GetDifficulty());
            ctrl.FieldGanerate();
            ctrl.Move();
            break;
        }
        default:
        {
            UiCommandReader* comreader = new UiCommandReader();
            //changeMode(comreader);
            comreader->SetLevels();
            comreader->SetOutput();
            comreader->SetDifficulty();
            InfoLog* logout_info = new InfoLog(comreader->GetOutputs(), comreader->GetLevels());
            comreader->SetSize();
            Controller ctrl(comreader, logout_info, comreader->GetDifficulty());
            ctrl.FieldGanerate();
            ctrl.Move();
            break;
        }
    }

}