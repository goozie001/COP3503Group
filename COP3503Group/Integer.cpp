#include <sstream>
#include "Integer.h"


Integer::Integer()
{
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
