#include <sstream>
#include "Integer.h"


Integer::Integer()
{
	this->intValue = 1;
	this->floatValue = 1.0;
}

Integer::Integer(int value) {
	this->intValue = value;
	this->floatValue = (float)value;
}


Integer::~Integer()
{
}

int Integer::getIntValue() {
	return intValue;
}

// Overridden methods

float Integer::getFloatValue() {
	return floatValue;
}

Number *Integer::simplify() {
	return this;
}

string Integer::toString() {

	// converts int value to string
	string s = static_cast<ostringstream*>(&(ostringstream() << intValue))->str();
	return s;

}

vector<int> Integer::getPrimeFactors()
{
	vector<int> temp;
	int i = intValue;
	if (i < 0)
	{
		temp.push_back(-1);
		i = i * -1;
	}
	return getPrimeFactorsHelper(2, i, temp);
}

vector<int> Integer::getPrimeFactorsHelper(int counter, int num, vector<int> temp)
{
	if (counter > num)
	{
		return temp;
	}
	else if (num % counter == 0)
	{
		num = num / counter;
		temp.push_back(counter);
		getPrimeFactorsHelper(counter, num, temp);
	}
	else
	{
		getPrimeFactorsHelper(counter+1, num, temp);
	}


}