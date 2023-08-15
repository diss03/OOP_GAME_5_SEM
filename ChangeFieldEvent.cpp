#include "ChangeFieldEvent.h"


ChangeFieldEvent::ChangeFieldEvent(Field* _field) {
	this->field = _field;
    
}

void ChangeFieldEvent::execute() {
	field->InitCells(field->GetHeight(), field->GetWidth());
	std::cout << "Field has been changed!" << std::endl;
}