#include "board.hpp"
#include "initializer.hpp"

bool Board::isOccupied(sf::Vector2i position) {
	return stateMap[position.x][position.y] == Obj::Empty;
}

bool Board::placeObject(Obj objectName, sf::Vector2i headPostion, int length) {
	switch (objectName)
	{
	case Obj::Empty:
		emptySquare(headPostion);
		break;
	case Obj::Stone:
		placeStone(headPostion, length);
		break;
	case Obj::Fruit:
		placeFruit(headPostion);
		break;
	case Obj::Snake:
		placeSnake(headPostion);
		break;
	default:
		break;
	}
}

int Board::getLength() {
	return boardLength;
}

void Board::emptySquare(sf::Vector2i position) {
	stateMap[position.x][position.y] = Obj::Empty;
}

bool Board::placeStone(sf::Vector2i position, int length) {
	int placedCount = 0;
	Initializer<int> dirInit; 
	dirInit.getRandomList(1, 2);
	for (int i = 0; i < length; i++) {
		if (!isOccupied(position)) {
			stateMap[position.x][position.y] = Obj::Stone;
			placedCount++;
		}
	}
	if (placedCount == 0) return false;
	return true;
}

bool Board::placeFruit(sf::Vector2i position) {
	if (!isOccupied(position)) {
		stateMap[position.x][position.y] = Obj::Fruit;
		return true;
	}
	return false;
}

bool Board::placeSnake(sf::Vector2i position) {
	if (!isOccupied(position)) {
		stateMap[position.x][position.y] = Obj::Snake;
		return true;
	}
	return false;
}
