#pragma once
#include "object.hpp"

struct Body {
    sf::Vector2f head;
    Body *next;
};

class Snake :
    public Object
{
private:
    bool alive = true;
    int snakeLength = 1;
    Body body;
    sf::Vector2f direction;
    Obj name = Obj::Snake;
public:
    Snake(sf::Vector2f position) :
        Object(position) {

    }
    bool isAlive();
    void move(Body *body);
    void setDirection();
};

