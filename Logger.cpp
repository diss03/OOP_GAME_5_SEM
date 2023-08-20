#include "Logger.h"
#include "Enums.h"
#include "FileLogger.h"
#include "CmdLogger.h"


Logger::Logger(InfoLog* info) {
    for (auto elem : info->GetOutputs()) {
        switch (elem) {
        case FILEOUT:
            outs.push_back(new FileLogger("logging.txt"));
            break;
        case CMD:
            outs.push_back(new CmdLogger);
            break;
        }
    }
    this->levels = info->GetLevels();
}

void Logger::Print(Message& message) {
    for (auto elem1 : outs) {
        for (auto elem2 : levels) {
            if (message.GetType() == elem2) {
                elem1->Print(message);
            }
        }
    }
}