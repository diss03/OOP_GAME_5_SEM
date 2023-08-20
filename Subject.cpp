#include "Subject.h"

void Subject::Attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::Detach(Observer* observer) {
    std::remove(observers.begin(), observers.end(), observer);
}

void Subject::Notify(Message& messsage) {
    for (auto elem : observers) {
        elem->update(messsage);
    }
}