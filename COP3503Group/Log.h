#pragma once
#include "Number.h"
class Log :
	public Number
{
public:
	Log();
	Log(Number* base, Number* argument);
	~Log();

	Number *getBase();
	Number *getArgument();
	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	Number *base;
	Number *argument;
	float floatValue;
};

