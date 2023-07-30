#pragma once
class Event 
{ 
public:
    virtual void foo() = 0;

    virtual ~Event();
};
