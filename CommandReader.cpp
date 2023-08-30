#include "CommandReader.h"
#include <iostream>
#include <SFML/Graphics.hpp>


CommandReader::CommandReader() {
    this->width = 10;
    this->step = NOTHING;
    this->info = nullptr;
    this->height = 10;
    this->difficulty = EASY;

    new ErrorObserver(this);
    this->input_commands = new FileInput("assigments.txt");
    input_commands->SetCommands();
}

void CommandReader::SetSize() {
    std::cout << "Do you want to set a field size?\n";
    std::cout << "Y - Yes\n";
    std::cout << "N - No\n";
    char res;
    std::cin >> res;
    if (res != 'Y' and res != 'y') {
        this->width = 10;
        this->height = 10;
        return;
    }
    InputHeight();
    InputWidth();
}

//void CommandReader::SetDifficulty() {
//    std::cout << "Choose game difficalty?\n";
//    std::cout << "Easy - 1\n";
//    std::cout << "Hard - 2\n";
//    char res;
//    std::cin >> res;
//    if (res == 1) {
//        this->difficulty = EASY;
//        return;
//    }
//    else if (res == 2) {
//        this->difficulty = HARD;
//        return;
//    }
//    else this->difficulty = EASY;
//}

void CommandReader::InputHeight() {
    std::cout << "Input field's height: ";
    std::cin >> height;
    if (height <= 0) {

        Message message(ERROR, "incorrect height input", this->info);
        Notify(message);

        std::cout << "Incorrect height. Try again: ";
        InputHeight();
    }
}

void CommandReader::InputWidth() {
    std::cout << "Input field's width: ";
    std::cin >> width;
    if (width <= 0) {

        Message message(ERROR, "incorrect width input", this->info);
        Notify(message);

        std::cout << "Incorrect width. Try again: ";
        InputWidth();
    }
}

//void CommandReader::InputStep(sf::RenderWindow* window) {
//    //std::cout << "Tap on move buttons" << std::endl;
//    window->pollEvent(step);
//}

int CommandReader::GetHeight() {
    return height;
}

int CommandReader::GetWidth() {
    return width;
}

//sf::Event CommandReader::GetStep() {
//    return  step;
//}

ASSIGMENTS CommandReader::GetStep() {
    return  step;
}

void CommandReader::SetOutput() {
    char res;
    std::cout << "Input output way: \n";
    std::cout << "1: File\n";
    std::cout << "2: CMD\n";
    std::cout << "3: Both\n";
    std::cin >> res;
    switch (res) {
    case '1':
        this->outputs.push_back(OUTPUT::FILEOUT);
        break;
    case '2':
        this->outputs.push_back(OUTPUT::CMD);
        break;
    case '3':
        this->outputs.push_back(OUTPUT::FILEOUT);
        this->outputs.push_back(OUTPUT::CMD);
        break;
    default:
        this->outputs.push_back(OUTPUT::FILEOUT);
        this->outputs.push_back(OUTPUT::CMD);
        break;
    }
}

void CommandReader::SetLevels() {
    char res;
    std::cout << "Input logging leveles: \n";
    std::cout << "1: Game\n";
    std::cout << "2: Status\n";
    std::cout << "3: Errors\n";
    std::cout << "4: All\n";
    std::cin >> res;
    switch (res) {
    case '1':
        this->levels.push_back(LEVEL::GAME);
        break;
    case '2':
        this->levels.push_back(LEVEL::STATUS);
        break;
    case '3':
        this->levels.push_back(LEVEL::ERROR);
        break;
    case '4':
        this->levels.push_back(LEVEL::GAME);
        this->levels.push_back(LEVEL::STATUS);
        this->levels.push_back(LEVEL::ERROR);
        break;
    default:
        this->levels.push_back(LEVEL::GAME);
        this->levels.push_back(LEVEL::STATUS);
        this->levels.push_back(LEVEL::ERROR);
        break;
    }
}

std::vector <OUTPUT> CommandReader::GetOutputs() {
    return this->outputs;
}

std::vector <LEVEL> CommandReader::GetLevels() {
    return this->levels;
}

void CommandReader::SetDifficulty() {
    char res;
    std::cout << "Set difficulty: \n";
    std::cout << "1: easy\n";
    std::cout << "2: hard\n";
    std::cin >> res;
    switch (res) {
    case '1':
        this->difficulty = EASY;
        break;
    case '2':
        this->difficulty = HARD;
        break;
    default:
        this->difficulty = EASY;
        break;
    }
}

DIFFICULTY CommandReader::GetDifficulty() {
    return this->difficulty;
}