#include "SaveExeption.h"

std::string SaveExeption::getMessage() const {
    return "Uploading error in: " + message;
}