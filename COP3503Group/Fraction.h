#pragma once
#include "Number.h"
class Fraction :
	public Number
{
public:
	Fraction();
	~Fraction();
private:
	Number *numerator;
	Number *denominator;
};

