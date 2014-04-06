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
	virtual float getFloatValue();
private:
	Number *base;
	Number *exponent;
	string value;
	float floatValue;
};

