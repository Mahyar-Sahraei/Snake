#include "stone.hpp"

sf::VertexArray Stone::setPositionStone(std::vector<std::vector<float>> pointsPosition) {
    sf::VertexArray stone(sf::Quads, 4);

    stone[0].position = sf::Vector2f(pointsPosition[0][0], pointsPosition[0][1]);
    stone[1].position = sf::Vector2f(pointsPosition[1][0], pointsPosition[1][1]);
    stone[2].position = sf::Vector2f(pointsPosition[2][0], pointsPosition[2][1]);
    stone[3].position = sf::Vector2f(pointsPosition[3][0], pointsPosition[3][1]);

    stone[0].texCoords=sf::Vector2f (0,0);
    stone[1].texCoords=sf::Vector2f (10,0);
    stone[2].texCoords=sf::Vector2f (10,10);
    stone[3].texCoords=sf::Vector2f (0,10);
    return stone;
}

void Stone::Object::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
    render();
}

void Stone::initializer() {
    if (!texture.loadFromFile("data/stone.png")){
        //error
    }
}

