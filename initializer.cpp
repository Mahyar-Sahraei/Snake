#include "initializer.hpp"

std::vector<int> Initializer::getRandomList(int min, int max, int count) {
	std::vector<int> randValues(count);
	std::random_device randDevice;
	std::mt19937 engine(randDevice());
	std::uniform_real_distribution<double> urDist(min, max + 1);
	for (auto randValue : randValues) {
		randValue = urDist(engine);
	}
	return randValues;
}