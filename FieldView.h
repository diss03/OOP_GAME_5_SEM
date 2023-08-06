#pragma once
#include "Field.h"

class FieldView : public Field
{
private:
    
public:
    void Print();
    using Field::Field; // Field::Field(...) is now visible as FieldView::Field(char)//
};