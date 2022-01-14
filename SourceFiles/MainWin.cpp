#include <SFML/Graphics.hpp>
#include "HeaderFiles/board.hpp"
#include "HeaderFiles/initializer.hpp"
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/snake.hpp"

int main() {
	sf::RenderWindow mainWin(sf::VideoMode(B_SIZE * T_SIZE, B_SIZE * T_SIZE), "Snake!");
	mainWin.setFramerateLimit(4);
	Board board;
	Initializer initializer; 
	std::pair<sf::Vector2f, sf::Vector2f> snakesPos = 
		initializer.initiate(board.getStateMap());
	Snake snake1(Obj::Snake1, snakesPos.first);
	Snake snake2(Obj::Snake2, snakesPos.second);
	Tiles map;
	Dir s1 = Dir::Stop, s2 = Dir::Stop;
	map.load(board.getStateMap());
	while (mainWin.isOpen()) {
		sf::Event event;
		while (mainWin.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mainWin.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) { 
				case sf::Keyboard::W:
					if (s2 != Dir::Down) s2 = Dir::Up;
					break;
				case sf::Keyboard::D:
					if (s2 != Dir::Left)s2 = Dir::Right;
					break;
				case sf::Keyboard::S:
					if (s2 != Dir::Up)s2 = Dir::Down;
					break;
				case sf::Keyboard::A:
					if (s2 != Dir::Right)s2 = Dir::Left;
					break;
				}
			}
		}
		snake1.move(board, s1);
		snake2.move(board, s2);
		if (!snake1.isAlive() || !snake2.isAlive()) break;
		board.clear();
		board.putSnake(snake1.body, snake1.getType());
		board.putSnake(snake2.body, snake2.getType());
		map.load(board.getStateMap());
		mainWin.clear(sf::Color::Black);
		mainWin.draw(map);
		mainWin.display();
	}
	return 0;
}