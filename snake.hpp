#pragma once
#include "object.hpp"

class Snake : public Object {
private:
    bool isAlive = true;
    int snakeLength = 1;
    sf::Vector2f headPosition;
    sf::Vector2f headDirection;
    sf::Texture texture;
    Obj name = Obj::Snake;

public:
    Snake(sf::Vector2f position, sf::VertexArray shape) :
            Object(position, shape) {}

    void snakeDied();
    void increaseSnakeBodyLength();
    void changHeadPosition(sf::Vector2f);
    void changHeadDirection(sf::Vector2f);
    void setTexture();
};

