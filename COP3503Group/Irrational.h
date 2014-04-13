#pragma once
#include "Number.h"

class Irrational :
	public Number
{
public:
	Irrational();
	Irrational(Expression *base, Expression *exponentNumerator, Expression *exponentDenominator);
	~Irrational();

	Expression *getBase();
	Expression *getExponentNumerator();
	Expression *getExponentDenominator();
	string getValue();

	// Overridden values
	virtual float getFloatValue();
	virtual Expression *simplify();
	virtual string toString();
private:
	Expression *base;
	Expression *exponentNumerator;
	Expression *exponentDenominator;
	string value;
	float floatValue;
};

