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
	return new Pi();
}

string Pi::toString() {
	return "pi";
}
