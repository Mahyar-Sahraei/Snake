#include "HeaderFiles/fruit.hpp"

Fruit::Fruit() : Object(Obj::Fruit) {
    return;
}

void Fruit::changePlace() {

}

bool Fruit::getEaten() {
    return isEaten;
}

void Fruit::setEaten() {
    isEaten= true;
}