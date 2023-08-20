#pragma once
#include "Output.h"
#include <fstream>
#include <string>

class FileLogger :public Output 
{
private:
    std::ofstream file;

public:
    FileLogger(std::string name);
    void Print(Message& message) override;
    ~FileLogger();
};