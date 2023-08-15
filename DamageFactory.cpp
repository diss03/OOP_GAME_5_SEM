#include "DamageFactory.h"

Event* DamageFactory::CreateEvent() {
    return new DamageEvent;
}