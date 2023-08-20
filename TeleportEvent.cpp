#include "TeleportEvent.h"
#include "vector"
#include "Cell.h"
#include <random>

TeleportEvent::TeleportEvent(Field* field) {
	this->field = field;
}


void TeleportEvent::execute(InfoLog* text) {
	std::vector<std::vector<Cell>>* cells = field->GetField();

	int x = field->GetX();
	int y = field->GetY();
	(*cells)[x][y].SetActive(false);

	distrubution:
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist_x(0, field->GetHeight() - 1); //равномерное распределение с включением границ
	std::uniform_int_distribution<> dist_y(0, field->GetWidth() - 1);

	int i = dist_x(gen);
	int j = dist_y(gen);
	if ((*cells)[i][j].GetObject() == Cell::WALL)
		goto distrubution;
	field->SetX(i);
	field->SetY(j);
	(*cells)[i][j].SetActive(true);
	if ((*cells)[i][j].GetObject() != Cell::WIN)
		(*cells)[i][j].SetObject(Cell::COMMON);
	(*cells)[i][j].UseEvent(text);

	Message message(GAME, "player has been teleported", text);
	Notify(message);
}