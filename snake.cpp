#include "snake.hpp"

void Snake::snakeDied() {
    isAlive = false;
}

void Snake::increaseSnakeBodyLength() {
    snakeLength++;
}

void Snake::changHeadPosition(sf::Vector2f newHeadPosition) {
    headPosition = newHeadPosition;
}

void Snake::changHeadDirection(sf::Vector2f newHeadDirection) {
    headPosition = newHeadDirection;
}

void Snake::setTexture() {
    if (!texture.loadFromFile("data/snake.png")) {
        //error
    }
}