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
	vector<int> getPrimeFactors();
	vector<int> getPrimeFactorsHelper(int counter, int num, vector<int> temp);

	// Overridden methods
	virtual float getFloatValue();
	virtual Number *simplify();
	virtual string toString();
private:
	int intValue;
	float floatValue;
	vector<int> primeFactors;
};