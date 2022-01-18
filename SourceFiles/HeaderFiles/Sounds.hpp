#include <SFML/Audio.hpp>

class Sounds {
private:
    sf::Music menuMusic,gameMusic,gameOverMusic;
    sf::SoundBuffer eatApple,snakeDie,clickEnter;
public:
    Sounds();
    void playMenuMusic();
    void pauseMenuMusic();
    void playGameMusic();
    void pauseGameMusic();
    void playGameOverMusic();
    void pauseGameOverMusic();
    void playEatApple();
    void playSnakeDie();
    void playClickEnter();
};