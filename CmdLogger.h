#pragma once
#include "Output.h"
#include <string>
#include <iostream>

class CmdLogger : public Output 
{
public:
    CmdLogger() = default;
    void Print(Message& message) override;
};