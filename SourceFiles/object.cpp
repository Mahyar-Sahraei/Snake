#include "HeaderFiles/object.hpp"

Object::Object(Obj type) {
	this->type = type;
}

Obj Object::getType() {
	return type;
}