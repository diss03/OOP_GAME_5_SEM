#pragma once
#include "Message.h"
#include "Logger.h"

class Observer {
public:
    virtual void update(Message& message) = 0;
    virtual ~Observer() {};
};