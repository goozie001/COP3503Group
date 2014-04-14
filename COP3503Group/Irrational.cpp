#include "Irrational.h"


Irrational::Irrational()
{
}

Irrational::Irrational(Number *base, Number *exponentNumerator, Number *exponentDenominator) {
	this->base = base;
	this->exponentNumerator = exponentNumerator;
	this->exponentDenominator = exponentDenominator;
}


Irrational::~Irrational()
{
}

Number *Irrational::getBase() {
	return base;
}

Number *Irrational::getExponentNumerator() {
	return exponentNumerator;
}

Number *Irrational::getExponentDenominator() {
	return exponentDenominator;
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
