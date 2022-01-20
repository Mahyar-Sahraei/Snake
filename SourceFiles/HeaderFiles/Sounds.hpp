#pragma once
#include <SFML/Audio.hpp>

class Sounds {
private:
    sf::Music menuMusic,gameMusic,gameOverMusic;
public:
    Sounds();
    void playMenuMusic();
    void pauseMenuMusic();
    void playGameMusic();
    void pauseGameMusic();
    void playGameOverMusic();
    void pauseGameOverMusic();
};