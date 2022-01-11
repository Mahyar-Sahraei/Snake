#include <SFML/Graphics.hpp>
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/snake.hpp"
#include "HeaderFiles/stone.hpp"
#include "HeaderFiles/fruit.hpp"
#include "Menu.hpp"

int main() {
    sf::RenderWindow mainWin(sf::VideoMode(B_SIZE * T_SIZE, B_SIZE * T_SIZE), "Snake!");
    mainWin.setFramerateLimit(1);
    Menu menu(mainWin.getSize().x, mainWin.getSize().y);
    Snake snake1, snake2;
    Stone stone;
    Fruit fruit;
    Board board({snake1, snake2, stone, fruit});
    Tiles map;
    map.load(board.stateMap);
    while (mainWin.isOpen()) {
        sf::Event event;
        while (mainWin.pollEvent(event)) {
            sf::Event event;
            while (mainWin.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        mainWin.close();
                        break;

                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Escape:
                                mainWin.close();
                                break;

                            case sf::Keyboard::Up:
                                menu.moveUpWithKeyboard();
                                break;

                            case sf::Keyboard::Down:
                                menu.moveDownWhiteKeyboard();
                                break;

                            case sf::Keyboard::Return:
                                switch (menu.getPressedItem()) {
                                    case 0:
                                        //start game
                                        break;
                                    case 1:
                                        mainWin.close();
                                        break;
                                }
                                break;
                        }
                        break;
                }
            }
            map.load(board.stateMap);
            mainWin.clear(sf::Color::Black);
            mainWin.draw(map);
            mainWin.display();
        }
    }
}
