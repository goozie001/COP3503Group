#pragma once
#include <iostream>
#include <cmath>
using namespace std;

#include "Integer.h"
#include "Fraction.h"
#include "Log.h"
#include "Irrational.h"

class Number
{
public:
	Number();
	~Number();

	virtual float getFloatValue();
	virtual Number *simplify();
private:
	float e;
	float pi;
	float floatValue;
};
