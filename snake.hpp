#pragma once
#include "object.hpp"

class Snake :
    public Object
{
private:
    bool isAlive = true;
    int snakeLength = 1;
    sf::Vector2f headPosition;
    sf::Vector2f headDirection;
public:
    Snake(sf::Vector2f position, sf::VertexArray shape) :
        Object(position, shape) {}

};

