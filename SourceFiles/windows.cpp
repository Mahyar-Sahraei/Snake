#include "HeaderFiles/snake.hpp"
#include "HeaderFiles/board.hpp"
#include "HeaderFiles/Tiles.hpp"
#include "HeaderFiles/windows.hpp"
#include "HeaderFiles/Sounds.hpp"
#include "HeaderFiles/SettingsMenu.hpp"

void win::mainMenu(sf::RenderWindow &window, Settings &settings,Sounds &sounds) {
    Menu menu(window.getSize().x, window.getSize().y, 
        "menuBackGround.png", "menuFont.ttf", "Snake!", "Start", "Exit", 0);
    menu.drawWindow(window);
    sounds.playMenuMusic();
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
                                sounds.pauseMenuMusic();
                                return startGame(window, settings, sounds);
                                break;
                            case 1:
                                settingGame(window,settings,sounds,0);
                                break;
                            case 2:
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

void win::settingGame(sf::RenderWindow &window, Settings &settings,Sounds &sounds,int whichMenu) {
    //Settings settings(window.getSize().x,window.getSize().y);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased)
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        settings.moveUp();
                        break;
                    case sf::Keyboard::Down:
                        settings.moveDown();
                        break;
                    case sf::Keyboard::Right:
                        settings.moveRight();
                        break;
                    case sf::Keyboard::Left:
                        settings.moveLeft();
                        break;
                    case sf::Keyboard::Return:
                        switch (settings.getPressedItem()) {
                            case 0:
                                settings.moveLeft();
                                return;
                                break;
                            case 1:
                                settings.setFPS(4);
                                settings.selectFastSpeed();
                                break;
                            case 2:
                                settings.setFPS(2);
                                settings.selectSlowSpeed();
                                break;
                            case 3:
                                settings.toggleMusic(true);
                                break;
                            case 4:
                                settings.toggleMusic(false);
                                break;
                        }
                        break;
                }
        }
        window.clear(sf::Color::Black);
        settings.drawWindow(window);
        window.display();
    }
}

void win::startGame(sf::RenderWindow &window, Settings &settings,Sounds &sounds) {
    Board board;
    Initializer initializer; 
	std::pair<sf::Vector2f, sf::Vector2f> snakesPos = 
		initializer.initiate(board.getStateMap());
	Snake snake1(Obj::Snake1, snakesPos.first);
	Snake snake2(Obj::Snake2, snakesPos.second);
	Tiles map;
    Dir tmpSnake1Dir = snake1.direction, tmpSnake2Dir = snake2.direction;
	map.load(board.getStateMap());
    if (settings.isMusicOn())
        sounds.playGameMusic();
    window.setFramerateLimit(settings.getFps());

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
        if (tmpSnake1Dir != Dir::Stop && tmpSnake2Dir != Dir::Stop) {
		    snake1.move(board, tmpSnake1Dir);
		    snake2.move(board, tmpSnake2Dir);
        }
		if (!snake1.isAlive() && !snake2.isAlive() || snake1.head == snake2.head) {
            sounds.pauseGameMusic();
            return endGame(window, "Draw.",settings,sounds);
        }
        else if (!snake1.isAlive()){
            sounds.pauseGameMusic();
            return endGame(window, "Player 2 won!",settings,sounds);
        }
        else if (!snake2.isAlive()) {
            sounds.pauseGameMusic();
            return endGame(window, "Player 1 won!",settings,sounds);
        }
		board.reset();
		board.putSnake(snake1.body, Obj::Snake1);
		board.putSnake(snake2.body, Obj::Snake2);
        for (int i = board.getFruitCount(); i < 2; i++) board.putFruit();
		map.load(board.getStateMap());
		window.clear(sf::Color::Black);
		window.draw(map);
		window.display();
	}
}

void win::endGame(sf::RenderWindow &window, std::string result, Settings &settings, Sounds& sound) {
    window.setFramerateLimit(15);
    Menu menu(window.getSize().x, window.getSize().y, 
        "gameOverBackGround.png", "menuFont.ttf", result, "Restart", "Exit" , 200);
    Sounds sounds;
    sounds.playGameOverMusic();
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
                                sounds.pauseGameOverMusic();
                                return startGame(window,settings,sounds);
                                break;
                            case 1:
                                settingGame(window,settings,sounds,1);
                                break;
                            case 2:
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