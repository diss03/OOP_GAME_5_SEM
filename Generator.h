#pragma once
#include "Field.h"

class Generator {
public:
    //virtual Field* generate(int, int, InfoLog*, Player*) = 0;
    virtual Field* generate(int height = 10, int width = 10, Player* player = nullptr, InfoLog* log_info = nullptr) = 0;

  };
