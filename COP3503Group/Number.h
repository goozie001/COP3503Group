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

#include "Expression.h"

class Number
	:public Expression
{
public:
	Number();
	~Number();

	virtual float getFloatValue() = 0;
	virtual string toString() = 0;
	bool isOfTypeNumber() { return true; }
private:
	float e;
	float pi;
	float floatValue;
};