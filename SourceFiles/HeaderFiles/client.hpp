#include <SFML/Network.hpp>
#include "board.hpp"
#include "snake.hpp"

class Client{
    std::string ip;
    unsigned int port;
    sf::TcpSocket client;
public:
    Client(std::string ip, unsigned int port);
    bool init();
    bool sendRequest(char command);
    bool sendBoard(Board& board);
    void getBoard(Board& board);
    bool sendSnake(Snake& snake);
    bool getAliveStatus();
    bool sevdAliveStatus(bool isAlive);
};

/******** REQUESTS MANUAL **********
 * s: sendBoard
 * g: getBoard
 * n: sendSnake
 * l: sendAliveStatus
 * d: getAliveStatus
************************************/