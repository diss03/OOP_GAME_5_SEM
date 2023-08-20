#include "ChangeFieldEvent.h"


ChangeFieldEvent::ChangeFieldEvent(Field* _field) {
	this->field = _field;
    
}

void ChangeFieldEvent::execute(InfoLog* text) {
	field->InitCells(field->GetHeight(), field->GetWidth());
	Message message(GAME, "fiel has been changed", text);
	Notify(message);
}