#pragma once
#include "HeaderFiles/snake.hpp"
#include "HeaderFiles/board.hpp"
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/windows.hpp"

void win::mainMenu(sf::RenderWindow &window, sf::Event event) {
    Menu menu(window.getSize().x,window.getSize().y);
    Board board;
    menu.drawWindow(window);
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
                        startGame(window,board);
                        break;
                    case 1:
                        window.close();
                        break;
                }
                break;
        }
}

void win::startGame(sf::RenderWindow &window, Board &board) {
    //start main menu here, if user pressed start then exit the function
    Initializer initializer; 
	std::pair<sf::Vector2f, sf::Vector2f> snakesPos = 
		initializer.initiate(board.getStateMap());
	Snake snake1(Obj::Snake1, snakesPos.first);
	Snake snake2(Obj::Snake2, snakesPos.second);
	Tiles map;
	Dir s1 = Dir::Stop, s2 = Dir::Stop;
	map.load(board.getStateMap());
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
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
                case sf::Keyboard::Up:
					if (s1 != Dir::Down) s1 = Dir::Up;
					break;
				case sf::Keyboard::Right:
					if (s1 != Dir::Left) s1 = Dir::Right;
					break;
				case sf::Keyboard::Down:
					if (s1 != Dir::Up) s1 = Dir::Down;
					break;
				case sf::Keyboard::Left:
					if (s1 != Dir::Right) s1 = Dir::Left;
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
		window.clear(sf::Color::Black);
		window.draw(map);
		window.display();
	}
    endGame(window, board);
}

void win::endGame(sf::RenderWindow &window, Board &board) {
    gameOverMenu menu(window.getSize().x,window.getSize().y);
    sf::Event event;
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
                        startGame(window,board);
                        break;
                    case 1:
                        window.close();
                        break;
                }
                break;
        }
}