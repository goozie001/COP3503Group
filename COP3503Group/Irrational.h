#pragma once
#include "Number.h"

class Irrational :
	public Number
{
public:
	Irrational();
	Irrational(Number *base, Number *rootVal);
	~Irrational();

	Number *getBase();
	Number *getRootVal();
	string getValue();

	// Overridden values
	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	Number *base;
	Number *rootVal;
	string value;
	float floatValue;
};

