#pragma once
#include <stack>

#include "Calculate.h"

class Parse
{
public:
	Parse();
	~Parse();
	
	stack<string> evaluateString(string str);

private:
	string removeSpaces(string str);
	bool isNumber(char ch);
	bool isOperator(char ch);
	int precedence(char ch);
	bool isLeftAssociative(char ch);
	bool isLeftParenthesis(char ch);
	bool isRightParenthesis(char ch);
	bool matchingParentheses(string str);
};

