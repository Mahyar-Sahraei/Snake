#pragma once
#include "initializer.hpp"
#include "object.hpp"
#define B_SIZE 15
typedef std::vector<std::vector<Obj>> MAP;

class Board {
private:
    MAP stateMap = MAP(B_SIZE, std::vector<Obj>(B_SIZE));
    int fruitCount = 2;
public:
    MAP& getStateMap();
    Obj getObj(sf::Vector2f position);
    Obj getObj(std::vector<int> position);
    int getFruitCount();
    void putObj(Obj object, sf::Vector2f position);
    void putObj(Obj object, std::vector<int> position);
    void putSnake(std::vector<sf::Vector2f> body, Obj which);
    void putFruit();
    void reset();
};