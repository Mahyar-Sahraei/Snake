#include "board.hpp"
#include "initializer.hpp"

Board::Board(std::vector<Obj> objects) {
	Initializer initializer;
	unsigned int index = 0;
	for (auto object : objects) {
		auto RandList = initializer.getRandomList(0, B_SIZE, 2);
		if (placeObject(object, sf::Vector2i(RandList[0], RandList[1])));
	}
}

bool Board::placeObject(Obj objectName, sf::Vector2i headPostion, int length) {
	switch (objectName)
	{
	case Obj::Empty:
		return emptySquare(headPostion);
		break;
	case Obj::Stone:
		return placeStone(headPostion, length);
		break;
	case Obj::Fruit:
		return placeFruit(headPostion);
		break;
	case Obj::Snake:
		return placeSnake(headPostion);
		break;
	default:
		break;
	}
}

bool Board::isOccupied(sf::Vector2i position) {
	return stateMap[position.x][position.y] == Obj::Empty;
}

bool Board::emptySquare(sf::Vector2i position) {
	stateMap[position.x][position.y] = Obj::Empty;
	return true;
}

bool Board::placeStone(sf::Vector2i position, int length) {
	int placedStones = 0;
	Initializer initializer;
	auto direction = initializer.getRandomList(1, 4)[0];
	for (int i = 0; i < length; i++) {
		if (!isOccupied(position)) {
			stateMap[position.x][position.y] = Obj::Stone;
			placedStones++;
		}
	}
	if (placedStones == 0) return false;
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
