#include "HeaderFiles/initializer.hpp"
#include "HeaderFiles/snake.hpp"

Snake::Snake() : Object(Obj::Snake) {
	Initializer initializer;
	auto rand = initializer.getRandomList(0, B_SIZE, 2);
	this->body.head = sf::Vector2f(rand[0], rand[1]);
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