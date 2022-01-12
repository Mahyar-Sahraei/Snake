#pragma once
#include <random>
#include <cstdarg>
#include <vector>
#include "object.hpp"
#include "board.hpp"
#define B_SIZE 15

typedef std::vector<std::vector<Obj>> MAP;
typedef std::pair<sf::Vector2f, sf::Vector2f> SNAKES_POS;

class Initializer
{
private:
    SNAKES_POS placeObject(std::vector<Obj> objects, MAP& stateMap) {
        SNAKES_POS snakesPos;
        for (auto object : objects) {
        auto randPos = getRandomList(0, B_SIZE, 2);
            switch (object) {
            case Obj::Stone:
                placeStone(stateMap, randPos);
                break;
            case Obj::Fruit:
                placeFruit(stateMap, randPos);
                break;
            case Obj::Snake1:
                snakesPos.first = placeSnake(stateMap, randPos, Obj::Snake1);
                break;
            case Obj::Snake2:
                snakesPos.second = placeSnake(stateMap, randPos, Obj::Snake2);
                break;
            default:
                break;
            }
        }
        return snakesPos;
    }
    bool isEmpty(MAP& stateMap, std::vector<int> position) {
        return stateMap[position[0]][position[1]] == Obj::Empty;
    }
    sf::Vector2f placeSnake(MAP& stateMap, std::vector<int> position, Obj which) {
        while (!isEmpty(stateMap, position)) {
            position = getRandomList(0, B_SIZE, 2);
        }
        stateMap[position[0]][position[1]] = which;
        return sf::Vector2f(position[0], position[1]);
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
     SNAKES_POS initiate(MAP& stateMap) {
        return placeObject({ Obj::Snake2, Obj::Snake2,
            Obj::Stone, Obj::Stone, Obj::Fruit }, stateMap);
    };
	std::vector<int> getRandomList(int min, int max, int count = 1);
};