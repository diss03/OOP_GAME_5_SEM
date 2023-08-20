#pragma once
#include "Subject.h"
#include "Observer.h"
class StatusObserver : public Observer 
{
public:

    StatusObserver(Subject* obj);
    void update(Message& message) override;
};