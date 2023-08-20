#pragma once
#include "Subject.h"
#include "Observer.h"
class ErrorObserver :public Observer 
{
public:
    ErrorObserver(Subject* obj);
    void update(Message& message) override;
};