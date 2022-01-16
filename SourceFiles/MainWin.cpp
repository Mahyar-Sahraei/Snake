#include <SFML/Graphics.hpp>
#include "HeaderFiles/board.hpp"
#include "HeaderFiles/initializer.hpp"
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/snake.hpp"
#include "HeaderFiles/windows.hpp"

int main() {
	sf::RenderWindow mainWin(sf::VideoMode(B_SIZE * T_SIZE, B_SIZE * T_SIZE), "Snake!");
	mainWin.setFramerateLimit(4);
	Board board;
	win::startGame(mainWin, board);
	return 0;
}