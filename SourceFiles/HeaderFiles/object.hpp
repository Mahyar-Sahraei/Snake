#pragma once
#include <SFML/Graphics.hpp>

struct Body {
	sf::Vector2f head;
	Body* next;
};

enum class Obj { Empty = 0, Stone, Fruit, Snake };

class Object {
private:
	Obj type;
public:
	Object(Obj type);
	Obj getType();
};