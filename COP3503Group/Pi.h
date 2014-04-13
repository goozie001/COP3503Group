#pragma once
#include "Number.h"
class Pi :
	public Number
{
public:
	Pi();
	~Pi();

	virtual float getFloatValue();
	virtual Expression *simplify();
	virtual string toString();
};

