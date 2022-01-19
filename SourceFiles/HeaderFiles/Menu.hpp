#pragma once
#include <SFML/Graphics.hpp>

#define NUMBER_OF_ITEMS 2

class Menu {
protected:
    sf::Font font;
    sf::Text text[NUMBER_OF_ITEMS];
    sf::Text title;
    sf::RectangleShape backGround;
    sf::Texture backGroundTexture;
    int selectedItem{0};

public:
    Menu(float width, float length, std::string background, std::string font, std::string title,
        std::string firstButton, std::string secondButton);
    void moveUpWithKeyboard();
    void moveDownWhiteKeyboard();
    void drawWindow(sf::RenderWindow &window);
    int getPressedItem() { return selectedItem; }
};