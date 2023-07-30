#include "CommandReader.h"
#include <iostream>

CommandReader::CommandReader() {}

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

void CommandReader::InputStep() {
    std::cout << "Tap on move buttons" << std::endl;
    std::cin >> step;
}

int CommandReader::GetHeight() {
    return height;
}

int CommandReader::GetWidth() {
    return width;
}

char CommandReader::GetStep() {
    return step;
}