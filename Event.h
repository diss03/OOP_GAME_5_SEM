#pragma once
#include "iostream"

class Event 
{ 
public:
    virtual void execute() = 0;
    virtual ~Event() {};
};
