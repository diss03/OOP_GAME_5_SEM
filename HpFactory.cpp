#include "HpFactory.h"

Event* HpFactory::CreateEvent() {
    return new HpEvent;
}