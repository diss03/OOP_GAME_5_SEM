#include <iostream>
#include "FieldView.h"

FieldView::FieldView() {
    window_hight = 800;
    window_width = 800;
}

FieldView::FieldView(int height, int width) {
    window_hight = height;
    window_width = width;
}

void FieldView::Print(Field* field, Player* player, sf::RenderWindow* window, std::vector<sf::Sprite> sprites)
{
    std::vector<std::vector<Cell>>* cells = field->GetField();
    cell_size.x = window_hight / field->GetHeight();
    cell_size.y = window_width / field->GetWidth();
    window->clear();

    std::cout << "\n";
    std::cout << "coins: " << player->GetBank() <<std::endl;
    std::cout << "health: " << player->GetHealth() <<std::endl;
    std::cout << "armor: " << player->GetArmor() <<std::endl;

    for (int i = 0; i < field->GetHeight(); i++)
    {
        std::cout << '\n';
        for (int j = 0; j < field->GetWidth(); j++)
        {
            if ((*cells)[i][j].GetActive()) {
                sprites[0].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[0]);
                std::cout << "X" << " ";
            }
            else if ((*cells)[i][j].GetObject() == Cell::COMMON) {
                sprites[1].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[1]);
                std::cout << "." << " ";
            }

            else if ((*cells)[i][j].GetObject() == Cell::WALL) {
                sprites[6].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[6]);
                std::cout << "#" << " ";
            }
            else if ((*cells)[i][j].GetObject() == Cell::ARMOR) {
                sprites[2].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[2]);
                std::cout << "$" << " ";
            }
            else if ((*cells)[i][j].GetObject() == Cell::BANK) {
                sprites[3].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[3]);
                std::cout << "C" << " ";
            }
            else if ((*cells)[i][j].GetObject() == Cell::CHANGEFIELD) {
                sprites[9].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[9]);
                std::cout << "%" << " ";
            }
            else if ((*cells)[i][j].GetObject() == Cell::DAMAGE) {
                sprites[4].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[4]);
                std::cout << "-" << " ";
            }
            else if ((*cells)[i][j].GetObject() == Cell::HP) {
                sprites[5].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[5]);
                std::cout << "+" << " ";
            }
            else if ((*cells)[i][j].GetObject() == Cell::TELEPORT) {
                sprites[8].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[8]);
                std::cout << "T" << " ";
            }
            else if ((*cells)[i][j].GetObject() == Cell::WIN) {
                sprites[7].setPosition(0. + j * cell_size.y, 0. + i * cell_size.x);
                window->draw(sprites[7]);
                std::cout << "@" << " ";
            }
        }
    }
    window->display();
    std::cout << '\n';
}