#pragma once

#include "Number.h"

class Parse
{
public:
	Parse();
	~Parse();
	
	string evaluateString(string str);

private:
	string removeSpaces(string str);
	bool isNumber(char ch);
	bool isOperator(char ch);
};

