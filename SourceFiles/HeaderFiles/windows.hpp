#pragma once
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "Menu.hpp"
#include "gameOverMenu.hpp"

namespace win {
    void mainMenu(sf::RenderWindow& window);
    void startGame(sf::RenderWindow& window);
    void endGame(sf::RenderWindow& window);
}