#pragma once
#include <random>
#include <chrono>
#include <vector>
#include "object.hpp"
#include "board.hpp"
#define B_SIZE 15

typedef std::vector<std::vector<Obj>> MAP;
typedef std::pair<sf::Vector2f, sf::Vector2f> SNAKES_POS;

class Initializer {
private:
    SNAKES_POS placeObject(std::vector<Obj> objects, MAP& stateMap) {
        SNAKES_POS snakesPos;
        for (auto object : objects) {
            switch (object) {
            case Obj::Stone:
                placeStone(stateMap);
                break;
            case Obj::Fruit:
                placeFruit(stateMap);
                break;
            case Obj::Snake1:
                snakesPos.first = placeSnake(stateMap, Obj::Snake1);
                break;
            case Obj::Snake2:
                snakesPos.second = placeSnake(stateMap, Obj::Snake2);
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
    sf::Vector2f randStoneLocation(int areaCode){
        Initializer init;
        sf::Vector2f stonePos;
        switch (areaCode) {
        case 1:
            stonePos.x = init.getRandomList(0, 3)[0];
            stonePos.y = init.getRandomList(0, 3)[0];
            break;
        case 2:
            stonePos.x = init.getRandomList(9, 12)[0];
            stonePos.y = init.getRandomList(0, 3)[0];
            break;
        case 3:
            stonePos.x = init.getRandomList(0, 3)[0];
            stonePos.y = init.getRandomList(9, 12)[0];
            break;
        case 4:
            stonePos.x = init.getRandomList(9, 12)[0];
            stonePos.y = init.getRandomList(9, 12)[0];
            break;
            default:
            break;
        }
        return stonePos;
    }
    sf::Vector2f placeSnake(MAP& stateMap, Obj which) {
        auto position = getRandomList(0, B_SIZE - 1, 2);
        while (!isEmpty(stateMap, position)) {
            position = getRandomList(0, B_SIZE - 1, 2);
        }
        stateMap[position[0]][position[1]] = which;
        return sf::Vector2f(position[0], position[1]);
    }
    void placeStone(MAP& stateMap) {
        int areaCode = getRandomList(1, 4)[0];
        sf::Vector2f stonePos1 = randStoneLocation(areaCode), 
                stonePos2 = randStoneLocation(5 - areaCode);
        for (int i = 0 ; i < 3; i++){
            stateMap[stonePos1.x][stonePos1.y] = Obj::Stone;
            stateMap[stonePos2.x][stonePos2.y] = Obj::Stone;
            stonePos1.x++;
            stonePos2.y++;
        }
    }
    void placeFruit(MAP& stateMap) {
        auto position = getRandomList(0, B_SIZE - 1, 2);
        while (!isEmpty(stateMap, position)) {
            position = getRandomList(0, B_SIZE - 1, 2);
        }
        stateMap[position[0]][position[1]] = Obj::Fruit;
    }
public:
     SNAKES_POS initiate(MAP& stateMap) {
        return placeObject({ Obj::Stone, Obj::Snake1, Obj::Snake2,
            Obj::Fruit, Obj::Fruit }, stateMap);
    };
	std::vector<int> getRandomList(int min, int max, int count = 1);
};