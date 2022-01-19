#include "HeaderFiles/Sounds.hpp"

Sounds::Sounds() {
    if (!menuMusic.openFromFile("menuMusic.ogg")) {
        //error
    }
    if (!gameMusic.openFromFile("gameMusic.ogg")) {
        //error
    }
    if (!gameOverMusic.openFromFile("gameOverMusic.ogg")) {
        //error
    }
    menuMusic.setLoop(true);
    gameMusic.setLoop(true);
    gameOverMusic.setLoop(true);

//    if (!eatApple.loadFromFile("eatApple.wav")) {
//        //error
//    }
//    if (!snakeDie.loadFromFile("snakeDie.wav")) {
        //error
//    }
//    if (!clickEnter.loadFromFile("clickEnter.wav")) {
//        //error
//    }
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

void Sounds::playEatApple() {
    sf::Sound sound;
    sound.setBuffer(eatApple);
    sound.play();
}

void Sounds::playSnakeDie() {
    sf::Sound sound;
    sound.setBuffer(snakeDie);
    sound.play();
}

void Sounds::playClickEnter() {
    sf::Sound sound;
    sound.setBuffer(clickEnter);
    sound.play();
}