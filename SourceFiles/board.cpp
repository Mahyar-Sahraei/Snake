#include "HeaderFiles/board.hpp"
#include "HeaderFiles/initializer.hpp"

MAP& Board::getStateMap() {
	return stateMap;
}

Obj Board::getObj(sf::Vector2f position) {
	return stateMap[position.x][position.y];
}

Obj Board::getObj(std::vector<int> position){
	return stateMap[position[0]][position[1]];
}

int Board::getFruitCount(){
	return fruitCount;
}

void Board::putObj(Obj object, sf::Vector2f position) {
	stateMap[position.x][position.y] = object;
}

void Board::putObj(Obj object, std::vector<int> position){
	stateMap[position[0]][position[1]] = object;
}

void Board::putSnake(std::vector<sf::Vector2f> body, Obj which) {
	int i = 0, length = body.size();
	for (; i < length - 1; i++) {
		putObj(which, body[i]);
	}
	if(which == Obj::Snake1) putObj(Obj::Snake1Head, body[i]);
	else putObj(Obj::Snake2Head, body[i]);
}

void Board::putFruit(){
	Initializer initializer;
	int attempts = 0;
	while (attempts < 100){
		auto position = initializer.getRandomList(0, B_SIZE - 1, 2);
		if (getObj(position) == Obj::Empty){
			putObj(Obj::Fruit, position);
			break;
		}
		attempts++;
	}
}

void Board::reset() {
	fruitCount = 0;
	for (size_t i = 0; i < B_SIZE; i++) {
		for (size_t j = 0; j < B_SIZE; j++)
		{
			Obj* tile = &stateMap[i][j];
			if (*tile == Obj::Snake1 || *tile == Obj::Snake2 || *tile == Obj::Snake1Head || *tile == Obj::Snake2Head){
				*tile = Obj::Empty;
			}
			else if (stateMap[i][j] == Obj::Fruit){
				fruitCount++;
			}
		}
	}
}

Board::~Board(){
	for (auto row : stateMap)
		row.erase(row.begin(), row.end());
}