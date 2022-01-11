#pragma once
#include <SFML/Graphics.hpp>

#define NUMBER_OF_ITEMS 2

class Menu {
private:
    sf::Font font;
    sf::Text text[NUMBER_OF_ITEMS];
    int selectedItem{0};

public:
    Menu(float width, float length);
    void moveUpWhiteKeyboard();
    void moveDownWhiteKeyboard();
    void drawWindow(sf::RenderWindow &window);
};