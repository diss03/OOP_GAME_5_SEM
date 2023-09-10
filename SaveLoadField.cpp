#include "SaveLoadField.h"

void SaveLoadField::saveField(Field* field) {

    file_input.open(filename, std::ios_base::app);

    if (!file_input.is_open()) {
        throw FileExeption("could not open file " + filename);
    }

    file_input << field->GetHeight() << '\n';
    file_input << field->GetWidth() << '\n';
    file_input << field->GetX() << '\n';
    file_input << field->GetY() << '\n';

    std::vector<std::vector<Cell>>* array = field->GetField();


    for (int i = 0; i < field->GetHeight(); i++) {
        for (int j = 0; j < field->GetWidth(); j++) {
            if ((*array)[i][j].GetActive() == true) 
                file_input << "ACTIVE ";
            
            else if ((*array)[i][j].GetObject() == Cell::WALL) 
                file_input << "WALL ";
            
            else if ((*array)[i][j].GetObject() == Cell::COMMON) 
                file_input << "COMMON ";
            
            else if ((*array)[i][j].GetObject() == Cell::ARMOR)
                file_input << "ARMOR ";
            
            else if ((*array)[i][j].GetObject() == Cell::BANK) 
                file_input << "BANK ";
            
            else if ((*array)[i][j].GetObject() == Cell::CHANGEFIELD) 
                file_input << "CHANGEFIELD ";
            
            else if ((*array)[i][j].GetObject() == Cell::DAMAGE)
                file_input << "DAMAGE ";

            else if ((*array)[i][j].GetObject() == Cell::HP) 
                file_input << "HP ";
            
            else if ((*array)[i][j].GetObject() == Cell::TELEPORT)
                file_input << "TELEPORT ";
            
            else if ((*array)[i][j].GetObject() == Cell::WIN)
                file_input << "WIN ";
            
        }
        file_input << std::endl;
    }
    file_input.close();
    makeHash();

}

Field* SaveLoadField::loadField(Player* player, InfoLog* log_info) {

    file_output.open(filename, std::fstream::in);
    if (!file_output.is_open()) {
        throw FileExeption("could not open file " + filename);
    }

    int width, height, x, y;
    std::string cell;

    char c;
    file_output >> c;
    while (c != '$') { //пропуск информации об игроке
        file_output >> c;
        if (file_output.eof() || file_output.fail()) {
            file_output.close();
            throw LoadExeption("file " + filename + " has invalid data!");
        }
    }

    file_output >> height;
    file_output >> width;
    file_output >> x;
    file_output >> y;

    if (height <= 0 or width <= 0 or x > (height-1) or y > (width-1) or x < 0 or y < 0) {
        file_output.close();
        throw LoadExeption("invalid filed data if file " + filename + "!");
    }
    if (checkHashMatching() == false) {
        file_output.close();
        throw LoadExeption("file " + filename + " have been changed!");
    }

    Field* new_field = new Field(height, width, player, log_info);
    EventCreator ev_creator(new_field, player);
    std::vector<std::vector<Cell>>* cells = new_field->GetField();
    new_field->SetX(x);
    new_field->SetY(y);
    (*cells)[0][0].SetActive(false);

    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            file_output >> cell;
            if (cell == "ACTIVE") {
                //(*array)[i][j].SetPlayersEvents();
                (*cells)[i][j].SetActive(true);
                (*cells)[i][j].SetObject(Cell::COMMON);
            }
            else if (cell == "WALL") {
                (*cells)[i][j].SetObject(Cell::WALL);
            }
            else if (cell == "ARMOR") {
                (*cells)[i][j].SetPlayersEvents(ev_creator.CreateArmorEventEvent());
                (*cells)[i][j].SetObject(Cell::ARMOR);
            }
            else if (cell == "BANK") {
                (*cells)[i][j].SetPlayersEvents(ev_creator.CreateBankEvent());
                (*cells)[i][j].SetObject(Cell::BANK);
            }
            else if (cell == "CHANGEFIELD") {
                (*cells)[i][j].SetPlayersEvents(ev_creator.CreateChangeFieldEvent());
                (*cells)[i][j].SetObject(Cell::CHANGEFIELD);
            }
            else if (cell == "DAMAGE") {
                (*cells)[i][j].SetPlayersEvents(ev_creator.CreateDamageEvent());
                (*cells)[i][j].SetObject(Cell::DAMAGE);
            }
            else if (cell == "HP") {
                (*cells)[i][j].SetPlayersEvents(ev_creator.CreateHpEvent());
                (*cells)[i][j].SetObject(Cell::HP);
            }
            else if (cell == "TELEPORT") {
                (*cells)[i][j].SetPlayersEvents(ev_creator.CreateTeleportEvent());
                (*cells)[i][j].SetObject(Cell::TELEPORT);
            }
            else if (cell == "WIN") {
                (*cells)[i][j].SetPlayersEvents(ev_creator.CreateWinEvent());
                (*cells)[i][j].SetObject(Cell::WIN);
            }
            else {
                (*cells)[i][j].SetObject(Cell::COMMON);
            }
        }
    }
    file_output.close();
    return new_field;
}
