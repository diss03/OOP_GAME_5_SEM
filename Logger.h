#pragma once
#include "InfoLog.h"
#include "Message.h"
#include <vector>
#include "Output.h"

class Logger {
public:
    Logger(InfoLog* info);
    void Print(Message& message);

private:
    std::vector<Output*> outs;
    std::vector<LEVEL> levels;
};
