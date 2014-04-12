#include "Operator.h"


Operator::Operator(string identity)
{
	this->identity = identity;
}


Operator::~Operator()
{
}

float Operator::getFloatValue() {
	return 0;
}

Number *Operator::simplify() {
	return this;
}

string Operator::toString() {
	return this->identity;
}