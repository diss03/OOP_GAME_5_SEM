#include "ChangeFieldEvent.h"


void ChangeFieldEvent::execute(void* ptr) {
	Field* field = (Field*)ptr;
	field->InitCells(field->GetHeight(), field->GetWidth());
	std::cout << "Field has been changed!" << std::endl;
}