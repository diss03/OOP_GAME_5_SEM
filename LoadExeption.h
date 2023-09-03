#pragma once
#include "CommonExeption.h"

class LoadExeption : public CommonExeption
{
public:
    using CommonExeption::CommonExeption;
    std::string getMessage() const final;
};