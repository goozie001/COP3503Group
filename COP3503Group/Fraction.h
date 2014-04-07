#pragma once
#include "Number.h"
class Fraction :
	public Number
{
public:
	Fraction();
	Fraction(Number *numerator, Number *denominator);
	~Fraction();

	//Getters
	Number *getNumerator();
	Number *getDenominator();

	//overridden functions
	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	Number *numerator;
	Number *denominator;
	float floatValue;
};

