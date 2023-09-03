#include "LoadExeption.h"

std::string  LoadExeption::getMessage() const {
    return "Uploading error in: " + message;
}