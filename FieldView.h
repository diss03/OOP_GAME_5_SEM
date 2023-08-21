#pragma once
#include "Player.h"
#include "Field.h"
#include "Enums.h"
#include <SFML/Graphics.hpp>

class FieldView
{
private:
    int window_hight;
    int window_width;
    sf::Vector2f cell_size;
    
public:
    FieldView();
    FieldView(int, int);
    void Print(Field*, Player*, sf::RenderWindow*, std::vector<sf::Sprite>);
};