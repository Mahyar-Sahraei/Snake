#include "HeaderFiles/gameOverMenu.hpp"

gameOverMenu::gameOverMenu(float width, float length) {
    backGround.setSize(sf::Vector2f(width, length));
    if (!backGroundTexture.loadFromFile("gameOverBackGround.png")) {
        //error
    }
    backGround.setTexture(&backGroundTexture);

    if (!font.loadFromFile("gameOverFont.ttf")) {
        //error
    }

    text[0].setFillColor(sf::Color::Red);
    text[0].setFont(font);
    text[0].setPosition(sf::Vector2f(width / 2 - 80, length / (NUMBER_OF_ITEMS + 2) * 1 - 10));
    text[0].setString("Start");
    text[0].setCharacterSize(70);

    text[1].setFillColor(sf::Color::Yellow);
    text[1].setFont(font);
    text[1].setPosition(sf::Vector2f(width / 2 - 55, length / (NUMBER_OF_ITEMS + 2) * 2 + 80));
    text[1].setString("Exit");
    text[1].setCharacterSize(70);
}

void gameOverMenu::moveUpWithKeyboard() {
    if (selectedItem > 0) {
        text[selectedItem].setFillColor(sf::Color::Yellow);
        selectedItem--;
        text[selectedItem].setFillColor(sf::Color::Red);
    } else {
        text[selectedItem].setFillColor(sf::Color::Yellow);
        selectedItem++;
        text[selectedItem].setFillColor(sf::Color::Red);
    }
}

void gameOverMenu::moveDownWhiteKeyboard() {
    if (selectedItem < NUMBER_OF_ITEMS - 1) {
        text[selectedItem].setFillColor(sf::Color::Yellow);
        selectedItem++;
        text[selectedItem].setFillColor(sf::Color::Red);
    } else {
        text[selectedItem].setFillColor(sf::Color::Yellow);
        selectedItem--;
        text[selectedItem].setFillColor(sf::Color::Red);
    }
}

void gameOverMenu::drawWindow(sf::RenderWindow &window) {
    window.draw(backGround);
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i) {
        window.draw(text[i]);
    }
}