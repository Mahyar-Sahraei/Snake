#include "HeaderFiles/board.hpp"
#include "HeaderFiles/initializer.hpp"

Board::Board(std::vector<Object> objects) {
	Initializer initializer;
	for (auto object : objects) {
		while (true) {
			auto rand = initializer.getRandomList(0, B_SIZE - 1, 2);
			if (placeObject(object.getType(), sf::Vector2i(rand[0], rand[1]))) {
				break;
			}
		}
	}
}

bool Board::placeObject(Obj objectName, sf::Vector2i headPostion) {
	switch (objectName)
	{
	case Obj::Empty:
		return emptySquare(headPostion);
		break;
	case Obj::Stone:
		return placeStone(headPostion);
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

bool Board::isEmpty(sf::Vector2i position) {
	return stateMap[position.x][position.y] == Obj::Empty;
}

bool Board::emptySquare(sf::Vector2i position) {
	stateMap[position.x][position.y] = Obj::Empty;
	return true;
}

bool Board::placeStone(sf::Vector2i position) {
	int placedStones = 0;
	Initializer initializer;
	int length = initializer.getRandomList(3, 5)[0];
	int direction = initializer.getRandomList(1, 3)[0];
	for (int i = 0; i < length; i++) {
		if (isEmpty(position)) {
			stateMap[position.x][position.y] = Obj::Stone;
			placedStones++;
			direction == 1 ? position.x++ : position.y++;
			if (position.x >= B_SIZE || position.y >= B_SIZE) break;
		}
	}
	if (placedStones == 0) return false;
	return true;
}

bool Board::placeFruit(sf::Vector2i position) {
	if (isEmpty(position)) {
		stateMap[position.x][position.y] = Obj::Fruit;
		return true;
	}
	return false;
}

bool Board::placeSnake(sf::Vector2i position) {
	if (isEmpty(position)) {
		stateMap[position.x][position.y] = Obj::Snake;
		return true;
	}
	return false;
}
