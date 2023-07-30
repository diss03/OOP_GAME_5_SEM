#include <iostream>
#include <SFML/Graphics.hpp>
#include "FieldView.h"

void FieldView::Print() 
{
    //sf::RenderWindow window(sf::VideoMode(800, 600), "OOP_GAME");
    std::vector<std::vector<Cell>>* cells = Field::GetField();
    std::cout << "\n";
    for (int i = 0; i < Field::GetHeight(); i++) 
    {
        std::cout << '\n';
        for (int j = 0; j < Field::GetWidth(); j++) {
            if ((*cells)[i][j].GetActive()) {
                std::cout << "X" << " ";
            }
            else if ((*cells)[i][j].GetWall()) {
                std::cout << "#" << " ";
            }
            else { std::cout << "." << " "; }

        }
    }
    std::cout << '\n';
}