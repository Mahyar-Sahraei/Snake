#pragma once
#include <SFML/Graphics.hpp>

enum class Obj { Empty = 0, Stone, Fruit, Snake1, Snake2 };

class Object {
private:
	Obj type;
public:
	Object(Obj type);
	Obj getType();
};