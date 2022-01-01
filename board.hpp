#pragma once
#include <array>
#include "object.hpp"
#define B_SIZE 10

class Board {
private:
    std::array<std::array<Obj, B_SIZE>, B_SIZE> stateMap = { Obj::Empty };
    int boardLength = B_SIZE;
public:
    Board(std::vector<Obj> objects) {
        Initializer<int> initializer;
        unsigned int index = 0;
        for (auto object : objects) {
            auto RandList = initializer.getRandomList(0, B_SIZE, 2);
            if (placeObject(object,sf::Vector2i(RandList[0], RandList[1])));
        }
    }
    bool placeObject(Obj objectName, sf::Vector2i headPostion, int length = 1);
    bool isOccupied(sf::Vector2i position);
    bool placeSnake(sf::Vector2i position);
    bool placeStone(sf::Vector2i position, int length);
    bool placeFruit(sf::Vector2i position);
    void emptySquare(sf::Vector2i position);
    int getLength();
};

