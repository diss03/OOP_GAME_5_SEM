#pragma once
#include "CommonExeption.h"

class SaveExeption : public CommonExeption
{
public:
    using CommonExeption::CommonExeption;
    std::string getMessage() const final;
};