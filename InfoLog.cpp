#include "InfoLog.h"

InfoLog::InfoLog(std::vector <OUTPUT> outputs, std::vector <LEVEL> levels) {
    this->outputs = outputs;
    this->levels = levels;
}

std::vector <LEVEL> InfoLog::GetLevels() {
    return this->levels;
}

std::vector <OUTPUT> InfoLog::GetOutputs() {
    return this->outputs;
}