#pragma once
#include "Number.h"
class Log :
	public Number
{
public:
	Log();
	Log(Number* base, Expression* argument);
	~Log();

	Number *getBase();
	Expression *getArgument();

	// Overridden methods
	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	Number *base;
	Expression *argument;
	float floatValue;
};

