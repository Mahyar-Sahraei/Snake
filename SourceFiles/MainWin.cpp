#include <SFML/Graphics.hpp>
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/snake.hpp"
#include "HeaderFiles/stone.hpp"
#include "HeaderFiles/fruit.hpp"

int main() {
	sf::RenderWindow mainWin(sf::VideoMode(B_SIZE * T_SIZE, B_SIZE * T_SIZE), "Snake!");
	mainWin.setFramerateLimit(1);
	Snake snake1, snake2;
	Stone stone;
	Fruit fruit;
	Board board({ snake1, snake2, stone, fruit });
	Tiles map;
	map.load(board.stateMap);
	while (mainWin.isOpen()) {
		sf::Event event;
		while (mainWin.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mainWin.close();
			}
		}
		map.load(board.stateMap);
		mainWin.clear(sf::Color::Black);
		mainWin.draw(map);
		mainWin.display();
	}
}