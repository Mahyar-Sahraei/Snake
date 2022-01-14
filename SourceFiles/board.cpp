#include "HeaderFiles/board.hpp"
#include "HeaderFiles/initializer.hpp"

MAP& Board::getStateMap() {
	return stateMap;
}

Obj Board::getObj(sf::Vector2f position) {
	return stateMap[position.x][position.y];
}

void Board::putObj(Obj object, sf::Vector2f position) {
	stateMap[position.x][position.y] = object;
}

void Board::putSnake(std::vector<sf::Vector2f> body, Obj which) {
	for (auto position : body) {
		putObj(which, position);
	}
}

void Board::clear() {
	for (size_t i = 0; i < B_SIZE; i++) {
		for (size_t j = 0; j < B_SIZE; j++)
		{
			if (stateMap[i][j] == Obj::Snake1 || stateMap[i][j] == Obj::Snake2){
				stateMap[i][j] = Obj::Empty;
			}
		}
	}
}