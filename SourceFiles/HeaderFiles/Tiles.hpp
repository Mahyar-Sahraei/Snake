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
	Tiles();
	void load(MAP stateMap);
	~Tiles();
};
