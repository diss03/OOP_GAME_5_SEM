#include "ArmorFactory.h"

Event* ArmorFactory::CreateEvent() {
    return new ArmorEvent;
}