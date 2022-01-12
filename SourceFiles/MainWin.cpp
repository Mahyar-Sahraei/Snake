#include <SFML/Graphics.hpp>
#include "HeaderFiles/board.hpp"
#include "HeaderFiles/initializer.hpp"
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/snake.hpp"

int main() {
	sf::RenderWindow mainWin(sf::VideoMode(B_SIZE * T_SIZE, B_SIZE * T_SIZE), "Snake!");
	mainWin.setFramerateLimit(1);
	Board board;
	Initializer initializer; 
	std::pair<sf::Vector2f, sf::Vector2f> snakesPos = 
		initializer.initiate(board.getStateMap());
	Snake snake1(Obj::Snake1, snakesPos.first);
	Snake snake2(Obj::Snake2, snakesPos.second);
	Tiles map;
	map.load(board.getStateMap());
	while (mainWin.isOpen()) {
		sf::Event event;
		while (mainWin.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mainWin.close();
			}
		}
		map.load(board.getStateMap());
		mainWin.clear(sf::Color::Black);
		mainWin.draw(map);
		mainWin.display();
	}
}