#include "HeaderFiles/SettingsMenu.hpp"

Settings::Settings(float width, float length, std::string font) {
    backGround.setSize(sf::Vector2f(width, length));
    if (!backGroundTexture.loadFromFile("settingsMenuBackground.png")) {
        //error
    }
    backGround.setTexture(&backGroundTexture);

    if (!this->font.loadFromFile(font)) {
        //error
    }
    sf::Vector2f textPosition;
    sf::Color titleColor(50, 50, 50);

    speedTitle.setFillColor(titleColor);
    speedTitle.setFont(this->font);
    textPosition = sf::Vector2f(240, 160);
    speedTitle.setPosition(textPosition);
    speedTitle.setString("Speed");
    speedTitle.setCharacterSize(60);

    soundTitle.setFillColor(titleColor);
    soundTitle.setFont(this->font);
    textPosition = sf::Vector2f(365, 450);
    soundTitle.setPosition(textPosition);
    soundTitle.setString("Sound");
    soundTitle.setCharacterSize(50);

    texts[0].setFillColor(sf::Color::Black);
    texts[0].setFont(this->font);
    textPosition = sf::Vector2f(500, 350);
    texts[0].setPosition(textPosition);
    texts[0].setString("Exit");
    texts[0].setCharacterSize(45);

    texts[1].setFillColor(sf::Color::Red);
    texts[1].setFont(this->font);
    textPosition = sf::Vector2f(280, 250);
    texts[1].setPosition(textPosition);
    texts[1].setString("Fast");
    texts[1].setCharacterSize(40);

    texts[2].setFillColor(sf::Color::Black);
    texts[2].setFont(this->font);
    textPosition = sf::Vector2f(280, 300);
    texts[2].setPosition(textPosition);
    texts[2].setString("Slow");
    texts[2].setCharacterSize(45);

    texts[3].setFillColor(sf::Color::Blue);
    texts[3].setFont(this->font);
    textPosition = sf::Vector2f(405, 520);
    texts[3].setPosition(textPosition);
    texts[3].setString("On");
    texts[3].setCharacterSize(30);

    texts[4].setFillColor(sf::Color::Black);
    texts[4].setFont(this->font);
    textPosition = sf::Vector2f(400, 560);
    texts[4].setPosition(textPosition);
    texts[4].setString("Off");
    texts[4].setCharacterSize(30);

}

void Settings::moveUp() {
    if (selectedItem == 0)
        return;

    selectedItem--;
    int lastItem = selectedItem + 1;
    if (selectedItem < 1) {
        lastItem = 1;
        selectedItem = 4;
    }

    if (lastItem == selectedSpeed || lastItem == selectedSound) {
        texts[lastItem].setFillColor(sf::Color::Blue);
        texts[selectedItem].setFillColor(sf::Color::Red);
    } else {
        texts[lastItem].setFillColor(sf::Color::Black);
        texts[selectedItem].setFillColor(sf::Color::Red);
    }
}

void Settings::moveDown() {
    if (selectedItem == 0)
        return;

    selectedItem++;
    int lastItem = selectedItem - 1;
    if (selectedItem > 4) {
        lastItem = 4;
        selectedItem = 1;
    }

    if (lastItem == selectedSpeed || lastItem == selectedSound) {
        texts[lastItem].setFillColor(sf::Color::Blue);
        texts[selectedItem].setFillColor(sf::Color::Red);
    } else {
        texts[lastItem].setFillColor(sf::Color::Black);
        texts[selectedItem].setFillColor(sf::Color::Red);
    }
}

void Settings::moveRight() {
    if (selectedItem == selectedSound || selectedItem == selectedSpeed) {
        texts[selectedItem].setFillColor(sf::Color::Blue);
    } else {
        texts[selectedItem].setFillColor(sf::Color::Black);
    }
    selectedItem = 0;
    texts[selectedItem].setFillColor(sf::Color::Red);
}

void Settings::moveLeft() {
    texts[selectedItem].setFillColor(sf::Color::Black);
    selectedItem = 1;
    texts[selectedItem].setFillColor(sf::Color::Red);
}

void Settings::selectFastSpeed() {
    if (selectedSpeed == 2) {
        texts[2].setFillColor(sf::Color::Black);
        selectedSpeed = 1;
        texts[1].setFillColor(sf::Color::Yellow);
    }
}

void Settings::selectSlowSpeed() {
    if (selectedSpeed == 1) {
        texts[1].setFillColor(sf::Color::Black);
        selectedSpeed = 2;
        texts[2].setFillColor(sf::Color::Yellow);
    }
}

void Settings::selectSoundOn() {
    if (selectedSound == 4) {
        texts[4].setFillColor(sf::Color::Black);
        selectedSound = 3;
        texts[3].setFillColor(sf::Color::Yellow);
    }
}

void Settings::selectSoundOff() {
    if (selectedSound == 3) {
        texts[3].setFillColor(sf::Color::Black);
        selectedSound = 4;
        texts[4].setFillColor(sf::Color::Yellow);
    }
}

void Settings::setFPS(int fps) {
    settingData.fps = fps;
}

void Settings::toggleMusic(bool isOn) {
    settingData.isMusicPlaying = isOn;
}

int Settings::getFps() {
    return settingData.fps;
}

bool Settings::isMusicOn() {
    return settingData.isMusicPlaying;
}

void Settings::drawWindow(sf::RenderWindow &window) {
    window.draw(backGround);
    window.draw(speedTitle);
    window.draw(soundTitle);
    for (int i = 0; i < SETTINGS_OPTIONS * 2 + 1; ++i) {
        window.draw(texts[i]);
    }
}
