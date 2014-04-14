#pragma once
#include "Number.h"

class Irrational :
	public Number
{
public:
	Irrational();
	Irrational(Number *base, Number *exponentNumerator, Number *exponentDenominator);
	~Irrational();

	Number *getBase();
	Number *getExponentNumerator();
	Number *getExponentDenominator();
	string getValue();

	// Overridden values
	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	Number *base;
	Number *exponentNumerator;
	Number *exponentDenominator;
	string value;
	float floatValue;
};

