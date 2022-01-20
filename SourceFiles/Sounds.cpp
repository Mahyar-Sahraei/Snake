#include "HeaderFiles/Sounds.hpp"

Sounds::Sounds() {
    if (!menuMusic.openFromFile("Resources/menuMusic.ogg")) {
        //error
    }
    if (!gameMusic.openFromFile("Resources/gameMusic.ogg")) {
        //error
    }
    if (!gameOverMusic.openFromFile("Resources/gameOverMusic.ogg")) {
        //error
    }
    menuMusic.setLoop(true);
    gameMusic.setLoop(true);
    gameOverMusic.setLoop(true);
}

void Sounds::playMenuMusic() {
    menuMusic.play();
    menuMusic.setVolume(20);
}

void Sounds::pauseMenuMusic() {
    menuMusic.pause();
}

void Sounds::playGameMusic() {
    gameMusic.play();
}

void Sounds::pauseGameMusic() {
    gameMusic.pause();
}

void Sounds::playGameOverMusic() {
    gameOverMusic.play();
}

void Sounds::pauseGameOverMusic() {
    gameOverMusic.pause();
}