#include <SFML/Graphics.hpp>
#include "HeaderFiles/board.hpp"
#include "HeaderFiles/initializer.hpp"
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/snake.hpp"
#include "HeaderFiles/windows.hpp"
#include "HeaderFiles/SettingsMenu.hpp"

int main() {
	sf::RenderWindow mainWin(sf::VideoMode(B_SIZE * T_SIZE, B_SIZE * T_SIZE), "Snake!");
    Settings settings(mainWin.getSize().x,mainWin.getSize().y, "menuFont.ttf");
    Sounds sounds;
    win::mainMenu(mainWin, settings, sounds);
	return 0;
}