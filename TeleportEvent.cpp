#include "TeleportEvent.h"
#include "vector"
#include "Cell.h"
#include <random>

void TeleportEvent::execute(void* ptr) {
	Field* field = (Field*)ptr;
	std::vector<std::vector<Cell>>* cells = field->GetField();
	std::vector<int> numbers = {};
	int number;
	for (int i = 0; i < field->GetHeight(); i++) {
		for (int j = 0; j < field->GetWidth(); j++) {
			if ((*cells)[i][j].GetWall()) {
				number = i * field->GetWidth() + j;
				numbers.push_back(number);
			}
		}
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, numbers.size()); //равномерное распределение с включением границ


	//проверить: не перепутал ли x и y !!!
	int index = dist(gen);
	int x = index / field->GetWidth();
	int y = index % field->GetWidth();
	field->SetX(x);
	field->SetY(y);
	(*cells)[x][y].SetActive(true);

	std::cout << "Player has been teleported!" << std::endl;
}