#include "GameObserver.h"

GameObserver::GameObserver(Subject* obj) {
    obj->Attach(this);
}

void GameObserver::update(Message& message) {
    if (message.GetType() == GAME) {
        Logger logger(message.GetInfo());
        logger.Print(message);
    }
}