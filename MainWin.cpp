#include <SFML/Graphics.hpp>
#include "Tiles.hpp"

int main() {
	sf::RenderWindow mainWin(sf::VideoMode(B_SIZE * T_SIZE, B_SIZE * T_SIZE), "Snake!");
	mainWin.setFramerateLimit(1);
	Tiles map;
	Board board;
	int k = 3;
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
		board.stateMap[k][k] = Obj::Empty;
		k++;
		board.stateMap[k][k] = Obj::Snake;
	}
}