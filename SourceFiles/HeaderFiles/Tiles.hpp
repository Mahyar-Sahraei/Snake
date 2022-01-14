#include <map>
#include <SFML/Graphics.hpp>
#include "board.hpp"
#define WIDTH 200
#define T_SIZE 50

typedef std::vector<std::vector<Obj>> MAP;

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
		std::pair<Obj, sf::Vector2f>
			snake1(Obj::Snake1, sf::Vector2f(0, 0)),
			snake2(Obj::Snake2, sf::Vector2f(0, 0)),
			stone(Obj::Stone, sf::Vector2f(0, 300)),
			fruit(Obj::Fruit, sf::Vector2f(285, 300)),
			board(Obj::Empty, sf::Vector2f(300, 0));
		texPositions.insert({snake1, snake2, stone, fruit, board});
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
