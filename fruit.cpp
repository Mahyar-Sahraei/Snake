#include "fruit.hpp"

void fruit::appleEat() {
    isEaten= true;
}

void fruit::changPosition(sf::Vector2f newPosition) {
    position=newPosition;
}

void fruit::setTexture() {
    if (!texture.loadFromFile("data/fruit.png")){
        //error
    }
}