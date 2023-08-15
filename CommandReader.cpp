#include "CommandReader.h"
#include <iostream>
#include <SFML/Graphics.hpp>

CommandReader::CommandReader() {}

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

void CommandReader::InputHeight() {
    std::cout << "Input field's height: ";
    std::cin >> height;
    if (height <= 0) {
        std::cout << "Incorrect height. Try again: ";
        InputHeight();
    }
}

void CommandReader::InputWidth() {
    std::cout << "Input field's width: ";
    std::cin >> width;
    if (width <= 0) {
        std::cout << "Incorrect width. Try again: ";
        InputWidth();
    }
}

void CommandReader::InputStep(sf::RenderWindow* window) {
    //std::cout << "Tap on move buttons" << std::endl;
    window->pollEvent(step);
}

int CommandReader::GetHeight() {
    return height;
}

int CommandReader::GetWidth() {
    return width;
}

sf::Event CommandReader::GetStep() {
    return  step;
}