#include "Menu.hpp"

Menu::Menu(float width, float length) {
    if (!font.loadFromFile("font.ttf")) {
        //error
    }

    text[0].setColor(sf::Color::Red);
    text[0].setFont(font);
    text[0].setPosition(sf::Vector2f(width / 2, length / (NUMBER_OF_ITEMS + 1) * 1));
    text[0].setString("Start");

    text[1].setColor(sf::Color::White);
    text[1].setFont(font);
    text[1].setPosition(sf::Vector2f(width / 2, length / (NUMBER_OF_ITEMS + 1) * 2));
    text[1].setString("Exit");
}

void Menu::moveUpWhiteKeyboard() {
    if (selectedItem > 0) {
        text[selectedItem].setColor(sf::Color::White);
        selectedItem--;
        text[selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::moveDownWhiteKeyboard() {
    if (selectedItem < NUMBER_OF_ITEMS) {
        text[selectedItem].setColor(sf::Color::White);
        selectedItem++;
        text[selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::drawWindow(sf::RenderWindow &window) {
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i) {
        window.draw(text[i]);
    }
}