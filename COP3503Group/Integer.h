#pragma once
#include "Number.h"
class Integer :
	public Number
{
public:
	Integer();
	Integer(int value);
	~Integer();

	int getIntValue();

	// Overridden methods
	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	int intValue;
	float floatValue;
};

