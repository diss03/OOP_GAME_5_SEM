#pragma once
#include "Message.h"
class Message;

class Output 
{
public:
    virtual void Print(Message& message) = 0;
    virtual ~Output() = default;
};