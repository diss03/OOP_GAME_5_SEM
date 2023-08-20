#pragma once
#include "Observer.h"
#include "Message.h"
#include <vector>
#include <algorithm>


class Subject 
{
public:
    void Attach(Observer* observer);

    void Detach(Observer* observer);

    void Notify(Message& message);
private:
    std::vector<Observer*> observers;
};