#include "HeaderFiles/Tiles.hpp"

Tiles::Tiles() {
		texture.loadFromFile("images.png");
		vertices.resize(4 * B_SIZE * B_SIZE);
		vertices.setPrimitiveType(sf::Quads);
		std::initializer_list<OBJ_PAIR> texPairs = {
			OBJ_PAIR(Obj::Snake1, sf::Vector2f(WIDTH, 0)),
			OBJ_PAIR(Obj::Snake2, sf::Vector2f(WIDTH, WIDTH)),
			OBJ_PAIR(Obj::Snake1Head, sf::Vector2f(0, 3 * WIDTH)),
			OBJ_PAIR(Obj::Snake2Head, sf::Vector2f(WIDTH, 3 * WIDTH)),
			OBJ_PAIR(Obj::Stone, sf::Vector2f(0, WIDTH)),
			OBJ_PAIR(Obj::Fruit, sf::Vector2f(WIDTH, 2 * WIDTH)),
			OBJ_PAIR(Obj::Empty, sf::Vector2f(0, 0))
			};
		texPositions.insert(texPairs.begin(), texPairs.end());
}

void Tiles::load(MAP stateMap) {
	for (size_t i = 0; i < B_SIZE; i++) {
		for (size_t j = 0; j < B_SIZE; j ++) {
			int tileIndex = (i * B_SIZE + j) * 4;
			setPosition(tileIndex, j * T_SIZE, i * T_SIZE);
			setTexture(tileIndex, stateMap[i][j]);
		}
	}
}

Tiles::~Tiles(){
    texture.~Texture();
    vertices.resize(0);
    texPositions.erase(texPositions.begin(), texPositions.end());
    delete &texture;
    delete &vertices;
    delete &texPositions;
}