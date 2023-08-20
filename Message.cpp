#include "Message.h"

Message::Message(LEVEL level, const std::string& message, InfoLog* info) {
    this->message = message;
    this->level = level;
    this->info = info;
    switch (level) {
    case GAME:
        this->prefix = "GAME: ";
        break;
    case ERROR:
        this->prefix = "ERROR: ";
        break;
    case STATUS:
        this->prefix = "STATUS: ";
        break;
    }
}

std::string Message::GetMessage() {
    return this->message;
}

InfoLog* Message::GetInfo() {
    return this->info;
}

LEVEL Message::GetType() {
    return this->level;
}

std::ostream& operator<<(std::ostream& out, Message& message) {
    out << message.GetPrefix() << message.GetMessage() << std::endl;
    return out;
}

std::string Message::GetPrefix() {
    return this->prefix;
}