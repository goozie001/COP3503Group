#include "E.h"


E::E()
{
}


E::~E()
{
}

float E::getFloatValue() {
	return exp(1);
}

Number *E::simplify() {
	return this;
}

string E::toString() {
	return "e";
}