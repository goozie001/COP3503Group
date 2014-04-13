#include "Irrational.h"


Irrational::Irrational()
{
}

Irrational::Irrational(Expression *base, Expression *exponentNumerator, Expression *exponentDenominator) {
	this->base = base;
	this->exponentNumerator = exponentNumerator;
	this->exponentDenominator = exponentDenominator;
}


Irrational::~Irrational()
{
}

Expression *Irrational::getBase() {
	return base;
}

Expression *Irrational::getExponentNumerator() {
	return exponentNumerator;
}

Expression *Irrational::getExponentDenominator() {
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
Expression *Irrational::simplify() {
	return NULL;
}

// TODO: Implement toString method
string Irrational::toString() {
	string s;
	return s;
}
