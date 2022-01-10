#pragma once
#include "object.hpp"

class Snake : public Object{
private:
    bool alive = true;
    int snakeLength = 1;
    Body body;
    sf::Vector2f direction;
    Obj type;
public:
    Snake();
    bool isAlive();
    void move(Body *body);
    void increaseSnakeLength();
};

