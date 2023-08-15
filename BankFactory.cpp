#include "BankFactory.h"

Event* BankFactory::CreateEvent() {
    return new BankEvent;
}