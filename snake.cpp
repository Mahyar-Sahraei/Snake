#include "snake.hpp"

bool Snake::isAlive() {
	return alive;
}

void Snake::move(Body *body) {
	body->head += direction;
	Body* nextPart;
	while (nextPart = body->next) {

	}
}