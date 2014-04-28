#pragma once
#include "Number.h"
// #include "Expression.h"
// #include "Integer.h"
// #include "Operator.h"
#include <exception>
class Irrational :
	public Number
{
public:
	Irrational();
	Irrational(Number *base, Number *rootVal);
	~Irrational();

	Number *getBase();
	Number *getRootVal();
	void setBase(Number *newBase);
	void setRootVal(Number *newRootVal);
	string getValue();

	// Overridden values
	float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	Number *simplifyNegRootVal(Number*);

	Number *base;
	Number *rootVal;
	string value;
	float floatValue;
};