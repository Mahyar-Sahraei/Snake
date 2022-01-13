#include "HeaderFiles/windows.hpp"

void win::mainMenu(sf::RenderWindow &window, sf::Event event) {
    Menu menu(window.getSize().x,window.getSize().y);
    Board board;
    menu.drawWindow(window);
    if (event.type == sf::Event::KeyReleased)
        switch (event.key.code) {
            case sf::Keyboard::Up:
                menu.moveUpWithKeyboard();
                break;
            case sf::Keyboard::Down:
                menu.moveDownWhiteKeyboard();
                break;
            case sf::Keyboard::Return:
                switch (menu.getPressedItem()) {
                    case 0:
                        startGame(window,board);
                        break;
                    case 1:
                        window.close();
                        break;
                }
                break;
        }
}

void win::startGame(sf::RenderWindow &window, Board &board) {
    //if (game ended)
        endGame(window,board);
}

void win::endGame(sf::RenderWindow &window, Board &board) {
    gameOverMenu menu(window.getSize().x,window.getSize().y);
    sf::Event event;
    if (event.type == sf::Event::KeyReleased)
        switch (event.key.code) {
            case sf::Keyboard::Up:
                menu.moveUpWithKeyboard();
                break;
            case sf::Keyboard::Down:
                menu.moveDownWhiteKeyboard();
                break;
            case sf::Keyboard::Return:
                switch (menu.getPressedItem()) {
                    case 0:
                        startGame(window,board);
                        break;
                    case 1:
                        window.close();
                        break;
                }
                break;
        }
}