#pragma once
#include <random>
#include <vector>

class Initializer
{
private:
	std::random_device random_device;
	std::mt19937 engine;
public:
	template <typename T>
	T getRandomVal(T min, T max) {
		engine(random_device());
		std::uniform_real_distribution urDist(min, max);
		return (T)urDist(engine);
	}
	template <typename T>
	std::vector<T> getRandomList(T min, T max, int number) {
		std::vector<T> randValues(number);
		for (auto randValue : randValues) {
			randValue = getRandomVal(min, max);
		}
		return randValues;
	}
};

