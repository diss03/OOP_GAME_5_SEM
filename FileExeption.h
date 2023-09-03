#pragma once
#include "CommonExeption.h"

class FileExeption : public CommonExeption
{
public:
    using CommonExeption::CommonExeption;
    std::string getMessage() const final;
};

