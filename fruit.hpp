#pragma once
#include "object.hpp"

class fruit : public Object {
	bool isEaten = false;
    sf::Texture texture;
	Obj name = Obj::Fruit;

public:

    void appleEat();
    void changPosition(sf::Vector2f);
    void setTexture();
};

