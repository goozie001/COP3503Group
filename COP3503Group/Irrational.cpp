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

// Overridden methods

float Irrational::getFloatValue() {
	return floatValue;
}

// TODO: Implement simplify Irrational method
Number *Irrational::simplify() {

}

// TODO: Implement toString method
string Irrational::toString() {

}
