#include "HeaderFiles/client.hpp"

Client::Client(std::string ip, unsigned int port){
    this->ip = ip;
    this->port = port;
}

bool Client::init(){
    if (client.connect(ip, port) != sf::Socket::Done) return false;
    return true;
}

bool Client::sendRequest(char command){
    return client.send(&command, 1) == sf::Socket::Done;
}

bool Client::sendBoard(Board& board){
    char data[B_SIZE][B_SIZE];
    for (int i = 0; i < B_SIZE; i++){
        for (int j = 0; j < B_SIZE; j++){
            switch (board.getStateMap()[i][j]) {
            case Obj::Fruit:
                data[i][j] = 'f';
                break;
            case Obj::Stone:
                data[i][j] = 's';
                break;
            case Obj::Snake1:
                data[i][j] = '1';
                break;
            case Obj::Snake2:
                data[i][j] = '2';
                break;
            case Obj::Snake1Head:
                data[i][j] = '3';
                break;
            case Obj::Snake2Head:
                data[i][j] = '4';
                break;
            default:
                break;
            }
        }
    }
    sendRequest('s');
    return client.send(data, B_SIZE * B_SIZE) == sf::Socket::Done;
}

void Client::getBoard(Board& board){
    char data[B_SIZE * B_SIZE];
    auto map = board.getStateMap();
    std::size_t received;
    sendRequest('g');
    client.receive(data, B_SIZE * B_SIZE, received);
    for (int i = 0; i < B_SIZE; i++){
        for (int j = 0; j < B_SIZE; j++){
            switch (data[B_SIZE * i + j]) {
            case 'f':
                map[i][j] = Obj::Fruit;
                break;
            case 's':
                map[i][j] = Obj::Stone;
                break;
            case '1':
                map[i][j] = Obj::Snake1;
                break;
            case '2':
                map[i][j] = Obj::Snake2;
                break;
            case '3':
                map[i][j] = Obj::Snake1Head;
                break;
            case '4':
                map[i][j] = Obj::Snake2Head;
                break;
            default:
                break;
            }
        }
    }
}

bool Client::getAliveStatus(){
    char alive;
    std::size_t received;
    sendRequest('l');
    client.receive(&alive, 1, received);
    if (alive == 'y') return true;
    return false;
}

bool Client::sevdAliveStatus(bool isAlive){
    char alive;
    isAlive ? alive = 'y' : alive = 'n';
    sendRequest('d');
    return client.send(&alive, 1) == sf::Socket::Done;
}