#pragma once

class LogOutInfo;

#include <ostream>
#include <string>
#include "Enums.h"
#include "InfoLog.h"

class Message {
public:
    Message(LEVEL, const std::string&, InfoLog*);

    std::string GetMessage();

    InfoLog* GetInfo();

    LEVEL GetType();

    friend std::ostream& operator<<(std::ostream&, Message&);

    std::string GetPrefix();

private:
    LEVEL level;
    std::string message;
    InfoLog* info;
    std::string prefix;
};