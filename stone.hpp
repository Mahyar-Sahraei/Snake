#pragma once
#include "object.hpp"

class Stone : public Object {
private:
	Obj name = Obj::Stone;
    sf::Texture texture;
public:
    sf::VertexArray setPositionStone(std::vector<std::vector<float>>);
    void initializer();
};

