#pragma once
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "Menu.hpp"
#include "SettingsMenu.hpp"

namespace win {
    void mainMenu(sf::RenderWindow& window, Settings &settings);
    void settingGame(sf::RenderWindow& window, Settings &settings);
    void startGame(sf::RenderWindow& window, Settings &settings);
    void endGame(sf::RenderWindow& window, std::string result, Settings &settings);
}