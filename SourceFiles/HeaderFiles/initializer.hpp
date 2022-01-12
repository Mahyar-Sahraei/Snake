#pragma once
#include <random>
#include <cstdarg>
#include <vector>
#include "object.hpp"
#include "board.hpp"
#define B_SIZE 15

typedef std::vector<std::vector<Obj>> MAP;

class Initializer
{
private:
    void placeObject(std::vector<Obj> objects, MAP& stateMap) {
        for (auto object : objects) {
        auto randPos = getRandomList(0, B_SIZE, 2);
            switch (object) {
            case Obj::Stone:
                placeStone(stateMap, randPos);
                break;
            case Obj::Fruit:
                placeFruit(stateMap, randPos);
                break;
            case Obj::Snake:
                placeSnake(stateMap, randPos);
                break;
            default:
                break;
            }
        }
    }
    bool isEmpty(MAP& stateMap, std::vector<int> position) {
        return stateMap[position[0]][position[1]] == Obj::Empty;
    }
    void placeSnake(MAP& stateMap, std::vector<int> position) {
        while (!isEmpty(stateMap, position)) {
            position = getRandomList(0, B_SIZE, 2);
        }
        stateMap[position[0]][position[1]] = Obj::Snake;
    }
    void placeStone(MAP& stateMap, std::vector<int> position) {
        bool placedStones = false;
        int length =getRandomList(3, 5)[0];
        int direction = getRandomList(1, 3)[0];
        for (int i = 0; i < length; i++) {
            if (isEmpty(stateMap, position)) {
                stateMap[position[0]][position[1]] = Obj::Stone;
                placedStones = true;
                direction == 1 ? position[0]++ : position[1]++;
                if (position[0] >= B_SIZE || position[1] >= B_SIZE) break;
            }
        }
        if (!placedStones)
            return placeStone(stateMap, getRandomList(0, B_SIZE, 2));
    }
    void placeFruit(MAP& stateMap, std::vector<int> position) {
        while (!isEmpty(stateMap, position)) {
            position = getRandomList(0, B_SIZE, 2);
        }
        stateMap[position[0]][position[1]] = Obj::Fruit;
    }
public:
    void initiate(MAP& stateMap) {
        placeObject({ Obj::Snake, Obj::Snake,
            Obj::Stone, Obj::Stone, Obj::Fruit }, stateMap);
    };
	std::vector<int> getRandomList(int min, int max, int count = 1);
};