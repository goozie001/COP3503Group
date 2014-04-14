#include "Pi.h"


Pi::Pi()
{
}


Pi::~Pi()
{
}

float Pi::getFloatValue() {
	return 3.14159265359;
}

Number *Pi::simplify() {
	return this;
}

string Pi::toString() {
	return "Pi";
}
