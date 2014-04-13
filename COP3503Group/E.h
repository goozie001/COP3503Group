#pragma once
#include "Number.h"
class E :
	public Number
{
public:
	E();
	~E();

	virtual float getFloatValue();
	virtual Expression *simplify();
	virtual string toString();
};

