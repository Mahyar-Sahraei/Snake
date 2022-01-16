#include "HeaderFiles/snake.hpp"
#include "HeaderFiles/board.hpp"
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/windows.hpp"

void win::mainMenu(sf::RenderWindow &window) {
    Menu menu(window.getSize().x, window.getSize().y);
    menu.drawWindow(window);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased)
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        menu.moveUpWithKeyboard();
                        break;
                    case sf::Keyboard::Down:
                        menu.moveDownWhiteKeyboard();
                        break;
                    case sf::Keyboard::Return:
                        switch (menu.getPressedItem()) {
                            case 0:
                                startGame(window);
                                break;
                            case 1:
                                window.close();
                                break;
                        }
                        break;
                }
        }
        window.clear(sf::Color::Black);
        menu.drawWindow(window);
        window.display();
    }
}

void win::startGame(sf::RenderWindow &window) {
    Board board;
    Initializer initializer; 
	std::pair<sf::Vector2f, sf::Vector2f> snakesPos = 
		initializer.initiate(board.getStateMap());
	Snake snake1(Obj::Snake1, snakesPos.first);
	Snake snake2(Obj::Snake2, snakesPos.second);
	Tiles map;
    Dir tmpSnake1Dir = snake1.direction, tmpSnake2Dir = snake2.direction;
	map.load(board.getStateMap());
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
                case sf::Keyboard::Up:
					if (snake1.direction != Dir::Down) tmpSnake1Dir = Dir::Up;
					break;
				case sf::Keyboard::Right:
					if (snake1.direction != Dir::Left) tmpSnake1Dir = Dir::Right;
					break;
				case sf::Keyboard::Down:
					if (snake1.direction != Dir::Up) tmpSnake1Dir = Dir::Down;
					break;
				case sf::Keyboard::Left:
					if (snake1.direction != Dir::Right) tmpSnake1Dir = Dir::Left;
					break; 
				case sf::Keyboard::W:
					if (snake2.direction != Dir::Down) tmpSnake2Dir = Dir::Up;
					break;
				case sf::Keyboard::D:
					if (snake2.direction != Dir::Left)tmpSnake2Dir = Dir::Right;
					break;
				case sf::Keyboard::S:
					if (snake2.direction != Dir::Up)tmpSnake2Dir = Dir::Down;
					break;
				case sf::Keyboard::A:
					if (snake2.direction != Dir::Right)tmpSnake2Dir = Dir::Left;
					break;
				}
			}
		}
		snake1.move(board, tmpSnake1Dir);
		snake2.move(board, tmpSnake2Dir);
		if (!snake1.isAlive() || !snake2.isAlive()) {
            endGame(window);
            break;
        }
		board.reset();
		board.putSnake(snake1.body, snake1.getType());
		board.putSnake(snake2.body, snake2.getType());
        for (int i = board.getFruitCount(); i < 2; i++) board.putFruit();
		map.load(board.getStateMap());
		window.clear(sf::Color::Black);
		window.draw(map);
		window.display();
	}

}

void win::endGame(sf::RenderWindow &window) {
    gameOverMenu menu(window.getSize().x,window.getSize().y);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased)
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        menu.moveUpWithKeyboard();
                        break;
                    case sf::Keyboard::Down:
                        menu.moveDownWhiteKeyboard();
                        break;
                    case sf::Keyboard::Return:
                        switch (menu.getPressedItem()) {
                            case 0:
                                startGame(window);
                                break;
                            case 1:
                                window.close();
                                break;
                        }
                        break;
                }
        }
        window.clear(sf::Color::Black);
        menu.drawWindow(window);
        window.display();
    }
}