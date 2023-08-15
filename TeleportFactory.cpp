#include "TeleportFactory.h"

Event* TeleportFactory::CreateEvent() {
    return new TeleportEvent;
}