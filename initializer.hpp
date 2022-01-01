#pragma once
#include <random>
#include <vector>
#include "object.hpp"
#include "board.hpp"

template <typename T>
class Initializer
{
private:
	std::random_device random_device;
	std::mt19937 engine;
public:
	std::vector<T> getRandomList(T min, T max, int count = 1);
};