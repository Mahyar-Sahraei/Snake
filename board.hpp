#pragma once
#include <array>
#include "object.hpp"
#define B_SIZE 10

class Board {
private:
    std::array<bool, B_SIZE> state = { false };
public:
    Board(std::vector<Object> objects) {
        for (auto object : objects) {
            placeObject(object, true);
        }
    }
    void placeObject(Object, bool);
    bool getState(sf::Vector2i);
};

