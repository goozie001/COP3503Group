#include "Irrational.h"


Irrational::Irrational()
{
}

Irrational::Irrational(Number *base, Number *rootVal) {
	this->base = base;
	this->rootVal = rootVal;
}


Irrational::~Irrational()
{
}

Number *Irrational::getBase() {
	return base;
}

Number *Irrational::getRootVal() {
	return rootVal;
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
	return this;
}

// TODO: Implement toString method
string Irrational::toString() {
	string s;
	return s;
}
