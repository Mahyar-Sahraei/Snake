#pragma once
#include <map>
#include "object.hpp"
#include "board.hpp"
#define WIDTH 423
#define T_SIZE 50

typedef std::vector<std::vector<Obj>> MAP;
typedef std::pair<Obj, sf::Vector2f> OBJ_PAIR;

class Tiles : public sf::Drawable {
private:
	sf::VertexArray vertices;
	sf::Texture texture;
	std::map<Obj, sf::Vector2f> texPositions;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		states.texture = &texture;
		target.draw(vertices, states);
	}
	void setTexture(int tileIndex, Obj objectType) {
		sf::Vector2f texPosition = texPositions[objectType];
		vertices[tileIndex++].texCoords = texPosition;
		texPosition.x += WIDTH;
		vertices[tileIndex++].texCoords = texPosition;
		texPosition.y += WIDTH;
		vertices[tileIndex++].texCoords = texPosition;
		texPosition.x -= WIDTH;
		vertices[tileIndex].texCoords = texPosition;
	}
	void setPosition(int tileIndex, int x, int y) {
		vertices[tileIndex++].position = sf::Vector2f(x, y);
		x += T_SIZE;
		vertices[tileIndex++].position = sf::Vector2f(x, y);
		y += T_SIZE;
		vertices[tileIndex++].position = sf::Vector2f(x, y);
		x -= T_SIZE;
		vertices[tileIndex].position = sf::Vector2f(x, y);
	}
public:
	Tiles() {
		texture.loadFromFile("images.png");
		vertices.resize(4 * B_SIZE * B_SIZE);
		vertices.setPrimitiveType(sf::Quads);
		std::initializer_list<OBJ_PAIR> texPairs = {
			OBJ_PAIR(Obj::Snake1, sf::Vector2f(WIDTH, 0)),
			OBJ_PAIR(Obj::Snake2, sf::Vector2f(WIDTH, WIDTH)),
			OBJ_PAIR(Obj::Snake1Head, sf::Vector2f(WIDTH / 2, WIDTH)),
			OBJ_PAIR(Obj::Snake2Head, sf::Vector2f(WIDTH, WIDTH / 2)),
			OBJ_PAIR(Obj::Stone, sf::Vector2f(0, WIDTH)),
			OBJ_PAIR(Obj::Fruit, sf::Vector2f(WIDTH, 2 * WIDTH)),
			OBJ_PAIR(Obj::Empty, sf::Vector2f(0, 0))
			};
		texPositions.insert(texPairs.begin(), texPairs.end());
	}
	void load(MAP stateMap) {
		for (size_t i = 0; i < B_SIZE; i++) {
			for (size_t j = 0; j < B_SIZE; j ++) {
				int tileIndex = (i * B_SIZE + j) * 4;
				setPosition(tileIndex, j * T_SIZE, i * T_SIZE);
				setTexture(tileIndex, stateMap[i][j]);
			}
		}
	}
};
