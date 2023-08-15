#include "WinFactory.h"

Event* WinFactory::CreateEvent() {
    return new WinEvent;
}