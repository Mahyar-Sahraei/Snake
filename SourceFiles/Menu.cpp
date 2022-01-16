#include "HeaderFiles/Menu.hpp"

Menu::Menu(float width, float length) {
    backGround.setSize(sf::Vector2f (width,length));
    if (!backGroundTexture.loadFromFile("menuBackGround.png")) {
        //error
    }
    backGround.setTexture(&backGroundTexture);

    if (!font.loadFromFile("menuFont.ttf")) {
        //error
    }

    text[0].setColor(sf::Color::Red);
    text[0].setFont(font);
    text[0].setPosition(sf::Vector2f(width / 2 -70, length / (NUMBER_OF_ITEMS +2) * 1));
    text[0].setString("Start");
    text[0].setCharacterSize(60);

    text[1].setColor(sf::Color::White);
    text[1].setFont(font);
    text[1].setPosition(sf::Vector2f(width / 2 -50, length / (NUMBER_OF_ITEMS +2) * 2));
    text[1].setString("Exit");
    text[1].setCharacterSize(60);
}

void Menu::moveUpWithKeyboard() {
    if (selectedItem > 0) {
        text[selectedItem].setColor(sf::Color::White);
        selectedItem--;
        text[selectedItem].setColor(sf::Color::Red);
    } else {
        text[selectedItem].setColor(sf::Color::White);
        selectedItem++;
        text[selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::moveDownWhiteKeyboard() {
    if (selectedItem < NUMBER_OF_ITEMS-1) {
        text[selectedItem].setColor(sf::Color::White);
        selectedItem++;
        text[selectedItem].setColor(sf::Color::Red);
    } else {
        text[selectedItem].setColor(sf::Color::White);
        selectedItem--;
        text[selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::drawWindow(sf::RenderWindow &window) {
    window.draw(backGround);
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i) {
        window.draw(text[i]);
    }
}