#pragma once
#include "Enums.h"
#include <vector>
#include <string>

class InfoLog 
{
public:
    InfoLog(std::vector <OUTPUT>, std::vector <LEVEL>);
    std::vector <LEVEL> GetLevels();
    std::vector <OUTPUT> GetOutputs();

private:
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
};