#include "ErrorObserver.h"


ErrorObserver::ErrorObserver(Subject* obj) {
    obj->Attach(this);
}

void ErrorObserver::update(Message& message) {
    if (message.GetType() == ERROR) {
        Logger logger(message.GetInfo());
        logger.Print(message);
    }
}