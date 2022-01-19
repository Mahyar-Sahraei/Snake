#include <string>
#include "HeaderFiles/Menu.hpp"

Menu::Menu(float width, float length, std::string background, std::string font, 
    std::string title, std::string firstButton, std::string secondButton) {
    backGround.setSize(sf::Vector2f (width,length));
    if (!backGroundTexture.loadFromFile(background)) {
        //error
    }
    backGround.setTexture(&backGroundTexture);

    if (!this->font.loadFromFile(font)) {
        //error
    }

    text[0].setFillColor(sf::Color::Red);
    text[0].setFont(this->font);
    sf::Vector2f textPosition(width / 2 - firstButton.length() * 16, 
        length / (NUMBER_OF_ITEMS + 2) * 1.7);
    text[0].setPosition(textPosition);
    text[0].setString(firstButton);
    text[0].setCharacterSize(70);

    text[1].setFillColor(sf::Color::White);
    text[1].setFont(this->font);
    textPosition = sf::Vector2f(width / 2 - secondButton.length() * 16,
                                length / (NUMBER_OF_ITEMS + 2) * 2.4);
    text[1].setPosition(textPosition);
    text[1].setString("Settings");
    text[1].setCharacterSize(70);

    text[2].setFillColor(sf::Color::White);
    text[2].setFont(this->font);
    textPosition = sf::Vector2f(width / 2 - secondButton.length() * 16,
                                length / (NUMBER_OF_ITEMS + 2) * 3.1);
    text[2].setPosition(textPosition);
    text[2].setString(secondButton);
    text[2].setCharacterSize(70);

    this->title.setFillColor(sf::Color::Black);
    this->title.setFont(this->font);
    textPosition = sf::Vector2f(width / 2 - title.length() * 16, 
        length / (NUMBER_OF_ITEMS + 2) - 100);
    this->title.setPosition(textPosition);
    this->title.setString(title);
    this->title.setCharacterSize(80);
}

void Menu::moveUpWithKeyboard() {
    if (selectedItem > 0) {
        text[selectedItem].setFillColor(sf::Color::White);
        selectedItem--;
        text[selectedItem].setFillColor(sf::Color::Red);
    } else {
        text[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        text[selectedItem].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDownWhiteKeyboard() {
    if (selectedItem < NUMBER_OF_ITEMS-1) {
        text[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        text[selectedItem].setFillColor(sf::Color::Red);
    } else {
        text[selectedItem].setFillColor(sf::Color::White);
        selectedItem--;
        text[selectedItem].setFillColor(sf::Color::Red);
    }
}

void Menu::drawWindow(sf::RenderWindow &window) {
    window.draw(backGround);
    window.draw(title);
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i) {
        window.draw(text[i]);
    }
}