#include "FileLogger.h"

FileLogger::FileLogger(std::string name) 
{
    file.open(name, std::ios_base::out | std::ios_base::app);
}

void FileLogger::Print(Message& message) 
{
    if (file.is_open())
        file << message;
}

FileLogger::~FileLogger() {
    file.close();
}