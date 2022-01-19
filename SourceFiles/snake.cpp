#include "HeaderFiles/snake.hpp"

Snake::Snake(Obj type, sf::Vector2f position) {
	this->type = type;
	if (type == Obj::Snake1) this->headType = Obj::Snake1Head;
	else this->headType = Obj::Snake2Head;
	this->body.resize(1);
	body[0] = head = position;
}

bool Snake::isAlive() {
	return alive;
}

void Snake::move(Board board, Dir direction) {
	this->direction = direction;
	if (direction == Dir::Stop) return;
	sf::Vector2f newPos = moveInDirection(body[length - 1], direction);
	Obj collObj = board.getObj(newPos);
	if (collObj == Obj::Fruit) {
		body.push_back(newPos);
		length++;
	}
	else if (collObj == Obj::Empty) {
		body.push_back(newPos);
		body.erase(body.begin());
	}
	else {
		alive = false;
	}
	head = body[length - 1];
}

Snake::~Snake(){
	body.erase(body.begin(), body.end());
}