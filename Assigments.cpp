#include "Assigments.h"
#include <iostream>

void Assigments::CheckAssigment() {
    //повторение и нульсимвол
    for (auto elem : current_moves) {
        if (elem.second == '\0') {
            current_moves = default_moves;
            return;
        }
    }

    for (auto elem1 : current_moves) {
        for (auto elem2 : current_moves) {
            if (elem1.second == elem2.second && elem1.first != elem2.first) {
                current_moves = default_moves;
                return;
            }
        }
    }
}

ASSIGMENTS Assigments::GetAction(char move)
{
    for (auto i : current_moves) 
    {
        if (i.second == move)
            return i.first;
    }
    return NOTHING;
}