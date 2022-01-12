#pragma once
#include "object.hpp"

struct Body {
    sf::Vector2f head;
    Body* next;
    Body* prev;
};

class Snake : public Object{
private:
    bool alive = true;
    int snakeLength = 1;
    Body body;
    sf::Vector2f direction;
    Obj type = Obj::Snake1;
public:
    Snake(Obj type, sf::Vector2f position);
    bool isAlive();
    void move(Body *body);
    void increaseSnakeLength();
};
