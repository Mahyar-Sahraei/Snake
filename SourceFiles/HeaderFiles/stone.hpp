#pragma once
#include "object.hpp"

class Stone : public Object{
	Body body;
public:
	Stone();
    void changePlace();
};

