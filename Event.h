#pragma once
#include "iostream"

class Event 
{ 
public:
    virtual void execute(void* ptr) = 0;

    virtual ~Event();
};
