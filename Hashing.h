#pragma once
#include "fstream"
#include <iostream>

#include "FileExeption.h"
#include "CommonExeption.h"
#include "LoadExeption.h"
#include "SaveExeption.h"

class Hashing
{
public:
    void makeHash();
    bool checkHashMatching();

protected:
    std::ofstream file_input;
    std::ifstream file_output;
    std::string filename = "saving.txt";
};
