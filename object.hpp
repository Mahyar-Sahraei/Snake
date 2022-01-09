#pragma once
#include <SFML/Graphics.hpp>

enum class Obj { Empty = 0, Stone, Fruit, Snake };

class Object {
protected:
	sf::Vector2f position;
public:
	Object(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	void move(sf::Vector2f);
};
