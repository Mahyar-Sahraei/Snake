#pragma once
#include <array>
#include "initializer.hpp"
#include "object.hpp"
#define B_SIZE 15
using std::vector;

class Board {
public:
    vector<vector<Obj>> stateMap = vector<vector<Obj>>(B_SIZE, vector<Obj>(B_SIZE));
    Board(std::vector<Object> objects = {});
    bool placeObject(Obj objectName, sf::Vector2i headPostion);
    bool isEmpty(sf::Vector2i position);
    bool placeSnake(sf::Vector2i position);
    bool placeStone(sf::Vector2i position);
    bool placeFruit(sf::Vector2i position);
    bool emptySquare(sf::Vector2i position);
};

