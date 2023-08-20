#pragma once
#include "Subject.h"
#include "Observer.h"
class GameObserver :public Observer 
{
public:
    GameObserver(Subject* obj);
    void update(Message& message) override;
};