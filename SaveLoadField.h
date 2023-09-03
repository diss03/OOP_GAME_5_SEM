#pragma once
#include "Field.h"
#include "Player.h"
#include "Cell.h"
#include "InfoLog.h"
#include "FieldView.h"
#include "fstream"
#include "EventCreator.h"
#include "Hashing.h"

#include "Subject.h"

class SaveLoadField : Hashing
{
public:
    void saveField(Field*);
    Field* loadField(Player*, InfoLog*);
};