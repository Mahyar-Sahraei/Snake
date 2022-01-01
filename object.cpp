#include "object.hpp"

sf::Vector2f Object::getPosition() {
	return position;
}
void Object::setPosition(sf::Vector2f newPosition) {
	position = newPosition;
	render();
}
void Object::move(sf::Vector2f motiontVector) {
	position += motiontVector;
	render;
}