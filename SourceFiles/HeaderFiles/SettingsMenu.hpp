#pragma once
#include <SFML/Graphics.hpp>

#define SETTINGS_OPTIONS 2

class Settings {
private:
    sf::Font font;
    sf::Text texts[SETTINGS_OPTIONS*2+1];
    sf::Text soundTitle,speedTitle;
    sf::Text exit;
    sf::Texture backGroundTexture;
    sf::RectangleShape backGround;
    int selectedItem{1},selectedSpeed{1},selectedSound{3};

public:
    Settings(float width, float length);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void drawWindow(sf::RenderWindow &window);
    //return 0 = Fast Speed , return 1 = Slow Speed , return 2 = Sound On , return 4 = Sound Off
    int getPressedItem() { return selectedItem; }

};