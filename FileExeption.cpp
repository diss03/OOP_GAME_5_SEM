#include "FileExeption.h"

std::string  FileExeption::getMessage() const {
    return "File error: " + message;
}