#pragma once
#include "Number.h"
class Operator :
	public Number
{
public:
	Operator(string);
	~Operator();

	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	string identity;
};

