#pragma once
#include <map>
#include "Enums.h"
#include <vector>


class Assigments
{
public:
    virtual void SetCommands() = 0;
    ASSIGMENTS GetAction(char);
    void CheckAssigment();
    virtual ~Assigments() = default;

protected:
    std::map<ASSIGMENTS, char> current_moves = {
            {ASSIGMENTS::UP,    '\0'},
            {ASSIGMENTS::DOWN,  '\0'},
            {ASSIGMENTS::LEFT,  '\0'},
            {ASSIGMENTS::RIGHT, '\0'},
            {ASSIGMENTS::EXIT,  '\0'},
            {ASSIGMENTS::SAVE, '\0'},
            {ASSIGMENTS::LOAD, '\0'},
    };

    const std::map<ASSIGMENTS, char> default_moves = {
            {ASSIGMENTS::UP,    'w'},
            {ASSIGMENTS::DOWN,  's'},
            {ASSIGMENTS::LEFT,  'a'},
            {ASSIGMENTS::RIGHT, 'd'},
            {ASSIGMENTS::EXIT,  'z'},
            {ASSIGMENTS::SAVE, 'x'},
            {ASSIGMENTS::LOAD, 'c'},
    };
};