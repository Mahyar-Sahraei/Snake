#include "HeaderFiles/initializer.hpp"

std::vector<int> Initializer::getRandomList(int min, int max, int count) {
	std::vector<int> randValues(count);
	int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);
	std::uniform_int_distribution<int> urDist(min, max);
	for (auto& randValue : randValues) {
		randValue = urDist(engine);
	}
	return randValues;
}