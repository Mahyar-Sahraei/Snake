#include "HeaderFiles/initializer.hpp"
#include "HeaderFiles/stone.hpp"

Stone::Stone() : Object(Obj::Stone) {
	Initializer initializer;
	auto rand = initializer.getRandomList(0, B_SIZE, 2);
	this->body.head = sf::Vector2f(rand[0], rand[1]);
}