#pragma once
#include "iostream"
#include "InfoLog.h"
#include "Subject.h"
#include "ErrorObserver.h"
#include "GameObserver.h"
#include "StatusObserver.h"

class Event : public Subject
{ 
public:
    virtual void execute(InfoLog*) = 0;
    virtual ~Event() {};
};
