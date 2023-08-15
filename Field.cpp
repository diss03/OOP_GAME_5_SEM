#include "Field.h"
#include "EventCreator.h"
#include "Cell.h"
#include "Player.h"
#include "Controller.h"
#include "FieldView.h"
#include <random>
#include <iostream>
#include <typeinfo>


void Field::SetX(int a) {   
    x = a;
}

void Field::SetY(int a) {
    y = a;
}

void Field::InitCells(int height, int width) {
    //первый варик
    //cells.resize(height); // pointers on lines
    //for (int i = 0; i < height; i++) {
    //    for (int j = 0; j < width; j++) { // lines
    //        Cell c(false, false);
    //        cells[i].push_back(c); // increase size of line by 1 cell
    //    }
    //}
    //--------------------------------------------------------
    //второй варик
    //for (int i = 0; i < height; i++) 
    //{
    //    cells.push_back(std::vector<Cell>(width));
    //    for (int j = 0; j < width; j++) 
    //    {
    //        this->cells[i][j] = Cell(false, false);
    //    }
    //}
    //--------------------------------------------------------
    //третий варик
    this->cells = std::vector < std::vector < Cell >>(height, std::vector<Cell>(width));
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            this->cells.at(y).at(x) = Cell();
        }
    }
    //--------------------------------------------------------
    SetX(0);
    SetY(0);
    cells[this->x][this->y].SetActive(true);
    cells[this->x][this->y].SetObject(Cell::COMMON);
    updateEvents();
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

Field::Field(int height, int width, Player* player) {
    this->height = height;
    this->width = width;
    this->player = player;
    InitCells(height, width);

    std::cout << "The overloaded constructor created a playing field with the size: ";
    std::cout << width << " x " << height << std::endl;
    std::cout << "the player is located at the coords: " << x << ", " << y << std::endl;
}

// конструктор копирования(объект создается и копируется)
Field::Field(const Field& copy) : height(copy.height), width(copy.width), x(copy.x), y(copy.y), player(copy.player) {
    for (int i = 0; i < height; i++) {
        cells.push_back(std::vector<Cell>());
        for (int j = 0; j < width; j++) {
            cells[i].push_back(copy.cells[i][j]);
        }
    }
}

// оператор присваивания (объект уже существуеет)
Field& Field::operator=(const Field& other) {
    // проверяем на самоприсваивание
    if (this == &other)
    {
        return *this;
    }

    // освобождаем память
    if (&this->cells != nullptr) {
        for (int i = 0; i < height; i++) cells[i].clear(); //Invalidates any references, pointers, or iterators referring to contained elements.
        cells.clear();
    }

    // перезаписываем
    height = other.height;
    width = other.width;
    x = other.x;
    y = other.y;
    player = other.player;

    cells.resize(height); // pointers on lines
    //for (int i = 0; i < height; i++) 
    //{
    //    for (int j = 0; j < width; j++) 
    //    { // lines
    //        Cell c(false, false);
    //        cells[i].push_back(c); // increase size of line by 1 cell
    //    }
    //}

    for (int i = 0; i < height; i++)
        cells[i].assign(other.cells[i].begin(), other.cells[i].end());

    // возвращаем ссылку на перезаписанный объект
    return *this;
}

//коструктор перемещения  
//Field::Field(Field&& other) : cells(other.cells)  
//{
//    std::swap(height, other.height);
//    std::swap(width, other.width);
//    std::swap(x, other.x);
//    std::swap(y, other.y);
//    for (int i = 0; i < height; i++) 
//    {
//        for (int j = 0; j < width; j++) 
//        {
//            std::swap(cells[i][j], other.cells[i][j]);
//        }
//    }
//}
Field::Field(Field&& other)
  : height(other.height),
    width(other.width),
    x(other.x),
    y(other.y),
    player(other.player)
{
    x = y = width = height = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::swap(cells[i][j], other.cells[i][j]);
        }
        other.cells[i].clear();
    }
    other.cells.clear();
}

void Field::MoveLeft() {
    cells[x][y].SetActive(false);
    y = (y - 1 + width) % width;
    if (cells[x][y].GetObject() != Cell::WALL) {
        if (cells[x][y].GetObject() != Cell::TELEPORT) {
            SetY(y);
            cells[x][y].SetActive(true);
        }
        if (cells[x][y].GetObject() != Cell::WIN)
            cells[x][y].SetObject(Cell::COMMON);
        cells[x][y].UseEvent();


    }
    else {
        y = (y + 1 + width) % width;
        std::cout << "Wall" << std::endl;
        SetY(y);
        cells[x][y].SetActive(true);
    }
}

void Field::MoveRight() {
    cells[x][y].SetActive(false); //ðàçìåð ïîëÿ ïðè çàäàíèè ñ÷èòàåì ñ 1
    y = (y + 1) % width;         //êîîðäèíàòû îòñ÷èòûâàþòñÿ ñ 0 (òîãäà ïî ìîäóëþ õîðîøî áåðåòñÿ)
    if (cells[x][y].GetObject() != Cell::WALL)
    { 
        if (cells[x][y].GetObject() != Cell::TELEPORT) {
            SetY(y);
            cells[x][y].SetActive(true);
        }
        if (cells[x][y].GetObject() != Cell::WIN)
            cells[x][y].SetObject(Cell::COMMON);
        cells[x][y].UseEvent();

    }
    else 
    {
        y = (y - 1 + width) % width;
        std::cout << "Wall" << std::endl;
        SetY(y);
        cells[x][y].SetActive(true);
    }
}

void Field::MoveUp() {
    cells[x][y].SetActive(false);
    x = (x - 1 + height) % height;
    if (cells[x][y].GetObject() != Cell::WALL)
    {
        if (cells[x][y].GetObject() != Cell::TELEPORT) {
            SetX(x);
            cells[x][y].SetActive(true);
        }
        if (cells[x][y].GetObject() != Cell::WIN)
            cells[x][y].SetObject(Cell::COMMON);
        cells[x][y].UseEvent();

    }
    else 
    {
        x = (x + 1 + height) % height;
        std::cout << "Wall" << std::endl;
        SetX(x);
        cells[x][y].SetActive(true);
    }
}

void Field::MoveDown() {
    cells[x][y].SetActive(false);
    x = (x + 1) % height;
    if (cells[x][y].GetObject()!=Cell::WALL) 
    { //ïðîâåðêà íà âîçìîæíîñòü õîäà
        if (cells[x][y].GetObject() != Cell::TELEPORT) {
            SetX(x);
            cells[x][y].SetActive(true);
        }
        if (cells[x][y].GetObject() != Cell::WIN)
            cells[x][y].SetObject(Cell::COMMON);
        cells[x][y].UseEvent();//для полевых ивентов аргументом должна быть ссылка на поле!!!

    }
    else 
    {
        x = (x - 1 + height) % height;
        std::cout << "Wall" << std::endl;
        SetX(x);
        cells[x][y].SetActive(true);
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

void Field::updateEvents() {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    EventCreator ev_creator(this, player);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> height_dist(0, height-1);
    std::uniform_int_distribution<> width_dist(0, width-1);
    int make_win_flag = 0;
    while (!make_win_flag) {
        int i = height_dist(gen);
        int j = width_dist(gen);
        cells[i][j].SetPlayersEvents(ev_creator.CreateWinEvent());
        cells[i][j].SetObject(Cell::WIN);
        make_win_flag++;
    }


    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (!cells[i][j].GetWall() && !cells[i][j].GetActive() && cells[i][j].GetObject() != Cell::WIN){
                
                std::uniform_int_distribution<> dist(1, 12);
                switch (dist(gen)) {
                    case 1:
                        cells[i][j].SetPlayersEvents(ev_creator.CreateArmorEventEvent());
                        cells[i][j].SetObject(Cell::ARMOR);
                        break;

                    case 2:
                        cells[i][j].SetPlayersEvents(ev_creator.CreateBankEvent());
                        cells[i][j].SetObject(Cell::BANK);
                        break;

                    case 3:
                        cells[i][j].SetPlayersEvents(ev_creator.CreateChangeFieldEvent());
                        cells[i][j].SetObject(Cell::CHANGEFIELD);
                        break;

                    case 4:
                        cells[i][j].SetPlayersEvents(ev_creator.CreateDamageEvent());
                        cells[i][j].SetObject(Cell::DAMAGE);
                        break;

                    case 5:
                        cells[i][j].SetPlayersEvents(ev_creator.CreateHpEvent());
                        cells[i][j].SetObject(Cell::HP);
                        break;

                    case 6:
                        cells[i][j].SetPlayersEvents(ev_creator.CreateTeleportEvent());
                        cells[i][j].SetObject(Cell::TELEPORT);
                        break;

                    case 7:
                        cells[i][j].SetObject(Cell::WALL);
                        break;

                    default:
                        break;
                }
            }
        }
    }
}