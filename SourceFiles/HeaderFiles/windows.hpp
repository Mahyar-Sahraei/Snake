#pragma once
#include <SFML/Graphics.hpp>
#include "board.hpp"

namespace win {
	void mainMenu(sf::RenderWindow& window);
	void startGame(sf::RenderWindow& window, Board& board);
	void endGame(sf::RenderWindow& window);
}