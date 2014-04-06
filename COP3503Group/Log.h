#pragma once
#include "Number.h"
class Log :
	public Number
{
public:
	Log();
	~Log();
private:
	Number *base;
	Number *value;
};

