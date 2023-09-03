#pragma once
#include <string>

class CommonExeption
{
public:
    CommonExeption(std::string message) : message{ message } {}
    virtual std::string getMessage() const
    {
        return message;
    }

protected:
    std::string message;
};
