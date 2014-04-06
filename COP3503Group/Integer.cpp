#include "Integer.h"


Integer::Integer()
{
}

Integer::Integer(int value) {
	this->value = value;
}


Integer::~Integer()
{
}

int Integer::getIntValue() {
	return value;
}

float Integer::getFloatValue() {
	return floatValue;
}