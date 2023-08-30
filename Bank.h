#pragma once
#include "Field.h"
#include "Player.h"
#include "EventCreator.h"
#include "Enums.h"

#include "random"


template<DIFFICULTY T>
class Bank
{
public:
    void operator()(EventCreator& ev_cr) {
        //EventCreator ev_creator(field, player);
        Field* field = ev_cr.Get_Field();
        //Player* player = ev_cr.Get_Player();
        std::vector<std::vector<Cell>>* cells = field->GetField();
        int height = field->GetHeight();
        int width = field->GetWidth();
        int count = 0;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, width + height);

        while (count < 3) {
            for (int i{}; i < height; i++) {
                for (int j{}; j < width; j++) {
                    if (dist(rd) == 1) {
                        if ((*cells)[i][j].GetObject() == Cell::COMMON && !(*cells)[i][j].GetActive()) {
                            (*cells)[i][j].SetPlayersEvents(ev_cr.CreateBankEvent());
                            (*cells)[i][j].SetObject(Cell::BANK);
                            count++;
                        }
                    }
                    if (count == 3)
                        return;
                }
            }
        }
    }
};

