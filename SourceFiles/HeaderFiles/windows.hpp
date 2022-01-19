#pragma once
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "Menu.hpp"

namespace win {
    void mainMenu(sf::RenderWindow& window);
    void settingGame(sf::RenderWindow& window);
    void startGame(sf::RenderWindow& window);
    void endGame(sf::RenderWindow& window, std::string result);
}