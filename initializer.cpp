#include "initializer.hpp"

template <typename T>
std::vector<T> Initializer<T>::getRandomList(T min, T max, int count) {
	std::vector<T> randValues(count);
	engine(random_device());
	std::uniform_real_distribution urDist(min, max + 1);
	for (auto randValue : randValues) {
		randValue = urDist(engine);
	}
	return randValues;
}