#pragma once
#include "Field.h"
#include "Player.h"
#include "EventCreator.h"
#include "Enums.h"

#include "random"


template<DIFFICULTY T>
class Hp
{
public:
    void operator()(EventCreator& ev_cr) {
        //EventCreator ev_creator(field, player);
        Field* field = ev_cr.Get_Field();
        //Player* player = ev_cr.Get_Player();
        std::vector<std::vector<Cell>>* cells = field->GetField();
        int height = field->GetHeight();
        int width = field->GetWidth();

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, width + height - (width + height) % (T * 5));

        for (int i{}; i < height; i++) {
            for (int j{}; j < width; j++) {
                if (dist(rd) == 1) {
                    if ((*cells)[i][j].GetObject() == Cell::COMMON && !(*cells)[i][j].GetActive()) {
                        (*cells)[i][j].SetPlayersEvents(ev_cr.CreateHpEvent());
                        (*cells)[i][j].SetObject(Cell::HP);
                    }
                }
            }
        }
    }
};

