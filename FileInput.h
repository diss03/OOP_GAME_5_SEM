#pragma once
#include "Assigments.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class FileInput : public Assigments
{
public:
    FileInput(std::string filename);

    void SetCommands() override;

    ~FileInput() override;

private:
    std::ifstream file;
};