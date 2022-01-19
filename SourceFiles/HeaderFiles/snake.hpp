#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "board.hpp"

enum class Dir {
    Stop, Right, Down, Left, Up
};

class Snake{
private:
    bool alive = true;
    int length = 1;
    Obj type = Obj::Snake1;
    Obj headType = Obj::Snake1Head;
    sf::Vector2f moveInDirection(sf::Vector2f position, Dir direction) {
        switch (direction) {
        case Dir::Up:
            if (position.x == 0) position.x = B_SIZE - 1;
            else position.x--;
            break;
        case Dir::Right:
            if (position.y == B_SIZE - 1) position.y = 0;
            else position.y++;
            break;
        case Dir::Down:
            if (position.x == B_SIZE - 1) position.x = 0;
            else position.x++;
            break;
        case Dir::Left:
            if (position.y == 0) position.y = B_SIZE - 1;
            else position.y--;
            break;
        default:
            break;
        }
        return position;
    }
public:
    std::vector<sf::Vector2f> body;
    Dir direction = Dir::Stop;
    Snake(Obj type, sf::Vector2f position);
    sf::Vector2f head;
    bool isAlive();
    void move(Board board, Dir direction);
    ~Snake();
};
