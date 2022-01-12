#pragma once
#include <SFML/Graphics.hpp>

#define NUMBER_OF_ITEMS 2

class Menu {
private:
    sf::Font font;
    sf::Text text[NUMBER_OF_ITEMS];
    sf::RectangleShape backGround;
    sf::Texture backGroundTexture;
    int selectedItem{0};

public:
    Menu(float width, float length);
    void moveUpWithKeyboard();
    void moveDownWhiteKeyboard();
    void drawWindow(sf::RenderWindow &window);
    int getPressedItem() { return selectedItem; } //if returned 0 start the game, else if returned 1, exit;
};