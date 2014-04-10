#pragma once
#include <vector>

#include "Calculate.h"

class Parse
{
public:
	Parse();
	~Parse();
	
	int pseudoMain(string);

private:
	string removeSpaces(string);
	string negativeCheck(string);

	bool isNumber(char);
	bool isOperator(char);
	bool isLeftAssociative(char);
	bool isLeftParenthesis(char);
	bool isRightParenthesis(char);
	bool matchingParentheses(string);

	int precedence(char);
	int evaluateRPN();
	int stringToRPN(string);

	vector<string> out;
};

