#pragma once
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "Menu.hpp"
#include "SettingsMenu.hpp"
#include "Sounds.hpp"

namespace win {
    void mainMenu(sf::RenderWindow& window, Settings &settings,Sounds &sounds);
    void settingGame(sf::RenderWindow& window, Settings &settings,Sounds &sounds,int whichMenu);
    void startGame(sf::RenderWindow& window, Settings &settings,Sounds &sounds);
    void endGame(sf::RenderWindow& window, std::string result, Settings &settings,Sounds &sounds);
}