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
	virtual float getFloatValue();
private:
	int value;
	float floatValue;
};

