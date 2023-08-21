#include "FileInput.h"

FileInput::FileInput(std::string filename) {
    file.open(filename, std::ios_base::in);
    if (!file.is_open()) {
        current_moves = default_moves;
        return;
    }
}

FileInput::~FileInput() {
    file.close();
}

void FileInput::SetCommands() {
    std::string str;
    while (getline(file, str)) {
        std::string tmp;
        char CHAR = '\0';

        std::istringstream stream(str);
        stream >> tmp >> CHAR;

        if (tmp == "RIGHT" && CHAR != '\0') {
            current_moves[RIGHT] = CHAR;
        }
        if (tmp == "LEFT" && CHAR != '\0') {
            current_moves[LEFT] = CHAR;
        }
        if (tmp == "UP" && CHAR != '\0') {
            current_moves[UP] = CHAR;
        }
        if (tmp == "DOWN" && CHAR != '\0') {
            current_moves[DOWN] = CHAR;
        }
        if (tmp == "EXIT" && CHAR != '\0') {
            current_moves[EXIT] = CHAR;
        }
    }
    for (auto i : current_moves)
        std::cout << i.first << " " << i.second << std::endl;  

    CheckAssigment();
}