#include "Irrational.h"


Irrational::Irrational()
{
}

Irrational::Irrational(Number *base, Number *exponent) {
	this->base = base;
	this->exponent = exponent;
	this->value = value;
}


Irrational::~Irrational()
{
}

Number *Irrational::getBase() {
	return base;
}

Number *Irrational::getExponent() {
	return exponent;
}

string Irrational::getValue() {
	return value;
}

float Irrational::getFloatValue() {
	return floatValue;
}
