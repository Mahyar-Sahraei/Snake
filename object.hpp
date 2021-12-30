#pragma once
#include <SFML/Graphics.hpp>

class Object
{
protected:
	sf::Vector2f position;
	sf::VertexArray shape;
public:
	void render();
	Object(sf::Vector2f position, sf::VertexArray shape) {
		this->position = position;
		this->shape = shape;
		render();
	}
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	void move(sf::Vector2f);
};

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
