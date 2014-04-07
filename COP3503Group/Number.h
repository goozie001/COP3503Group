/*
* This will be the abstract class that everything will include,
* hence the libraries and header files that will be necessary in every class
* will be declared publicly here.
*/


#pragma once
#include <iostream>
#include <cmath>
#include <sstream>
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
	virtual string toString();
private:
	float e;
	float pi;
	float floatValue;
};
