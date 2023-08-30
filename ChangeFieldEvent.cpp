#include "ChangeFieldEvent.h"


ChangeFieldEvent::ChangeFieldEvent(Field* _field) {
	this->field = _field;
    
}

void ChangeFieldEvent::execute(InfoLog* text) {
	field->InitCells();
	field->updateEvents(); //���� ������� � ����������� ����
	Message message(GAME, "fiel has been changed", text);
	Notify(message);
}