#include "StatusObserver.h"

StatusObserver::StatusObserver(Subject* obj) {
    obj->Attach(this);
}

void StatusObserver::update(Message& message) {
    if (message.GetType() == STATUS) {
        Logger logger(message.GetInfo());
        logger.Print(message);
    }
}