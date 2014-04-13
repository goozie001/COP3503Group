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

Expression *Pi::simplify() {
	return this;
}

string Pi::toString() {
	return "Pi";
}
