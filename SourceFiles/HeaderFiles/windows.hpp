#pragma once
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "Menu.hpp"
#include "gameOverMenu.hpp"

namespace win {
    void mainMenu(sf::RenderWindow& window, sf::Event event);
    void startGame(sf::RenderWindow& window, Board& board);
    void endGame(sf::RenderWindow& window, Board &board);
}