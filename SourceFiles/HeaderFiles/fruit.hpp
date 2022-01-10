#pragma once
#include "object.hpp"

class Fruit : public Object{
	bool isEaten = false;
public:
	Fruit();
    void changePlace();
};

