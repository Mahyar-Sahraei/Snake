#pragma once
#include <SFML/Graphics.hpp>

#define SETTINGS_OPTIONS 2

struct SettingData{
    bool isMusicPlaying{true};
    int fps{4};
};

class Settings {
private:
    sf::Font font;
    sf::Text texts[SETTINGS_OPTIONS * 2 + 1];
    sf::Text soundTitle,speedTitle;
    sf::Text exit;
    sf::Texture backGroundTexture;
    sf::RectangleShape backGround;
    int selectedItem{1},selectedSpeed{1},selectedSound{3};
    SettingData settingData;

public:
    Settings(float width, float length, std::string font);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void selectFastSpeed();
    void selectSlowSpeed();
    void selectSoundOn();
    void selectSoundOff();
    void drawWindow(sf::RenderWindow &window);
    void setFPS(int fps);
    void toggleMusic(bool isOn);
    int getFps();
    bool isMusicOn();
    //return 0 = Fast Speed , return 1 = Slow Speed , return 2 = Sound On , return 4 = Sound Off
    int getPressedItem() { return selectedItem; }
};