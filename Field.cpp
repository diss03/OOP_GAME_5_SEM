#include "Field.h"
#include "Cell.h"
#include "Player.h"
#include "Controller.h"
#include "FieldView.h"
#include <iostream>


void Field::SetX(int a) {   
    x = a;
}

void Field::SetY(int a) {
    y = a;
}

void Field::InitCells(int height, int width) {
    //cells.resize(height); // pointers on lines
    //for (int i = 0; i < height; i++) {
    //    for (int j = 0; j < width; j++) { // lines
    //        Cell c(false, false);
    //        cells[i].push_back(c); // increase size of line by 1 cell
    //    }
    //}
    for (int i = 0; i < height; i++) {
        cells.push_back(std::vector<Cell>(width));
        for (int j = 0; j < width; j++) {
            cells[i][j] = Cell(false, false);
        }
    }
    SetX(0);
    SetY(0);
    cells[this->x][this->y].SetActive(true);
}

//expliced let to avoid implicit conversion

Field::~Field() {
    for (int i = 0; i < height; i++) { cells[i].clear(); }
    cells.clear();
}

Field::Field() {
    this->height = 8;
    this->width = 8;
    InitCells(height, width);
}

Field::Field(int height, int width) {
    this->height = height;
    this->width = width;

    InitCells(height, width);

    std::cout << "The overloaded constructor created a playing field with the size: ";
    std::cout << width << " x " << height << std::endl;
    std::cout << "the player is located at the coords: " << x << ", " << y << std::endl;
}

//êîíñòðóêòîð ãëóáîêîãî êîïèðîâàíèÿ (îáúåêò ñîçäàåòñÿ è êîïèðóåòñÿ)
Field::Field(const Field& copy) : height(copy.height), width(copy.width), x(copy.x), y(copy.y) {
    for (int i = 0; i < height; i++) {
        cells.push_back(std::vector<Cell>());
        for (int j = 0; j < width; j++) {
            cells[i].push_back(copy.cells[i][j]);
        }
    }
}

//îïåðàòîð ïðèñâàèâàíèÿ (îáúåêò óæå ñóùåñòâóååò)
Field& Field::operator=(const Field& other) {
    // ïðîâåðÿåì íà ñàìîïðèñâàèâàíèå
    if (this == &other)
    {
        return *this;
    }

    // îñâîáîæäàåì ïàìÿòü
    for (int i = 0; i < height; i++) { cells[i].clear(); } //Invalidates any references, pointers, or iterators referring to contained elements.
    cells.clear();

    // ïåðåçàïèñûâàåì
    height = other.height;
    width = other.width;
    x = other.x;
    y = other.y;

    cells.resize(height); // pointers on lines
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) { // lines
            Cell c(false, false);
            cells[i].push_back(c); // increase size of line by 1 cell
        }
    }

    for (int i = 0; i < height; i++) {
        cells[i].assign(other.cells[i].begin(), other.cells[i].end());
    }

    // âîçâðàùàåì ññûëêó íà ïåðåçàïèñàííûé îáúåêò

    return *this;
}

//êîñòðóêòîð ïåðåìåùåíèÿ  
//Field::Field(Field&& other) : cells(other.cells) {
//    std::swap(height, other.height);
//    std::swap(width, other.width);
//    std::swap(x, other.x);
//    std::swap(y, other.y);
//    for (int i = 0; i < height; i++) {
//        for (int j = 0; j < width; j++) {
//            std::swap(cells[i][j], other.cells[i][j]);
//        }
//    }
//}

void Field::MoveLeft() {
    cells[x][y].SetActive(false);
    y = (y - 1 + width) % width;
    if (!cells[x][y].GetWall()) { //проверка на возможность хода
        SetY(y);
        cells[x][y].SetActive(true);
    }
    else {
        y = (y + 1 - width) % width;
        std::cout << "Wall" << std::endl;
    }
}

void Field::MoveRight() {
    cells[x][y].SetActive(false); //ðàçìåð ïîëÿ ïðè çàäàíèè ñ÷èòàåì ñ 1
    y = (y + 1) % width;         //êîîðäèíàòû îòñ÷èòûâàþòñÿ ñ 0 (òîãäà ïî ìîäóëþ õîðîøî áåðåòñÿ)
    if (!cells[x][y].GetWall()) { //ïðîâåðêà íà âîçìîæíîñòü õîäà
        SetY(y);
        cells[x][y].SetActive(true);
    }
    else {
        y = (y - 1 + width) % width;
        std::cout << "Wall" << std::endl;
    }
}

void Field::MoveUp() {
    cells[x][y].SetActive(false);
    x = (x - 1 + height) % height;
    if (!cells[x][y].GetWall()) { //ïðîâåðêà íà âîçìîæíîñòü õîäà
        SetX(x);
        cells[x][y].SetActive(true);
    }
    else {
        x = (x + 1 - height) % height;
        std::cout << "Wall" << std::endl;
    }
}

void Field::MoveDown() {
    cells[x][y].SetActive(false);
    x = (x + 1) % height;
    if (!cells[x][y].GetWall()) { //ïðîâåðêà íà âîçìîæíîñòü õîäà
        SetX(x);
        cells[x][y].SetActive(true);
    }
    else {
        x = (x - 1) % height;
        std::cout << "Wall" << std::endl;
    }
}

int Field::GetHeight() {
    return height;
}

int Field::GetWidth() {
    return width;
}

int Field::GetX() {
    return x;
}

int Field::GetY() {
    return y;
}

std::vector<std::vector<Cell>>* Field::GetField() {
    return &cells;
}