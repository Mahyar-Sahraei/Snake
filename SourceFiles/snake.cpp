#include "HeaderFiles/snake.hpp"

Snake::Snake(Obj type, sf::Vector2f position) : Object(type) {
	this->body.head = position;
}

bool Snake::isAlive() {
	return alive;
}

void Snake::move(Body *body) {
	body->head += direction;
	Body* nextPart;
	while (nextPart = body->next) {

	}
}

void Snake::increaseSnakeLength() {
    snakeLength++;
}