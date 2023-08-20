#pragma once
#include "Cell.h"
#include "Player.h"
#include <vector>
#include <string>

#include "InfoLog.h"
#include "Subject.h"
#include "ErrorObserver.h"
#include "GameObserver.h"
#include "StatusObserver.h"

class Field : public Subject
{
private:
    int height;
    int width;
    std::vector< std::vector<Cell>> cells;
    int x;
    int y;
    Player* player;
    InfoLog* log_info;
    std::string log_text;

public:
    Field();
    Field(int, int, Player*, InfoLog*);
    Field(const Field&);
    Field& operator=(const Field&);
    Field(Field&&);
    ~Field();

    void SetX(int);
    void SetY(int);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    void InitCells(int, int);

    int GetHeight();
    int GetWidth();
    int GetX();
    int GetY();
    std::vector<std::vector<Cell>>* GetField();

    void updateEvents();

};