#pragma once
#include "Cell.h"
#include <vector>
class Field
{
private:
    int height;
    int width;
    std::vector< std::vector<Cell>> cells;
    int x;
    int y;

public:
    Field();
    Field(int, int);
    Field(const Field&);
    Field& operator=(const Field& copy);
    Field(Field&&);
    ~Field();

    void SetX(int);
    void SetY(int);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    //void PrintField();
    void InitCells(int, int);

    int GetHeight();
    int GetWidth();
    int GetX();
    int GetY();
    std::vector<std::vector<Cell>>* GetField();

};