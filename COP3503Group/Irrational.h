#pragma once
#include "Number.h"

class Irrational :
	public Number
{
public:
	Irrational();
	Irrational(Number *base, Number *exponent);
	~Irrational();

	Number *getBase();
	Number *getExponent();
	string getValue();

	// Overridden values
	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	Number *base;
	Number *exponent;
	string value;
	float floatValue;
};

