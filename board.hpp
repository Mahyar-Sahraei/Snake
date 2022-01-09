#pragma once
#include <array>
#include "initializer.hpp"
#include "object.hpp"
#define B_SIZE 10
using std::vector;

class Board {
public:
    vector<vector<Obj>> stateMap = vector<vector<Obj>>(B_SIZE, vector<Obj>(B_SIZE));
    Board(std::vector<Obj> objects = {});
    bool placeObject(Obj objectName, sf::Vector2i headPostion, int length = 1);
    bool isOccupied(sf::Vector2i position);
    bool placeSnake(sf::Vector2i position);
    bool placeStone(sf::Vector2i position, int length);
    bool placeFruit(sf::Vector2i position);
    bool emptySquare(sf::Vector2i position);
};

