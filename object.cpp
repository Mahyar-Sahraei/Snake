#include "object.hpp"

Object::Object(sf::Vector2f position) {
	this->position = position;
}

sf::Vector2f Object::getPosition() {
	return position;
}

void Object::setPosition(sf::Vector2f newPosition) {
	position = newPosition;
}