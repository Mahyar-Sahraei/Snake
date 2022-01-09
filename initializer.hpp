#pragma once
#include <random>
#include <vector>
#include "object.hpp"
#include "board.hpp"

class Initializer
{
public:
	std::vector<int> getRandomList(int min, int max, int count = 1);
};