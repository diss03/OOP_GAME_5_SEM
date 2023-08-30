#include "ChangeFieldEvent.h"


ChangeFieldEvent::ChangeFieldEvent(Field* _field) {
	this->field = _field;
    
}

void ChangeFieldEvent::execute(InfoLog* text) {
	field->InitCells();
	field->updateEvents(); //надо связать с генератором поля
	Message message(GAME, "fiel has been changed", text);
	Notify(message);
}