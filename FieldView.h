#pragma once
#include "Field.h"

class FieldView : public Field 
{
private:
    using Field::Field;
public:
    void Print();
};