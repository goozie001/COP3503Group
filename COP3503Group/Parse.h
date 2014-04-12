#pragma once
#include <vector>

#include "Calculate.h"

class Parse
{
public:
	Parse();
	~Parse();
	
	int pseudoMain(string);

	vector<Number*> numberRPN;

private:
	string removeSpaces(string);
	string negativeCheck(string);

	bool isNumber(char);
	bool isLog(string, int);
	bool isOperator(char);
	bool isLeftAssociative(char);
	bool isLeftParenthesis(char);
	bool isRightParenthesis(char);
	bool matchingParentheses(string);

	int precedence(char);
	int evaluateRPN();
	int stringToRPN(string);

	Integer *stringToInteger(string);
	Operator *stringToOperator(string);

	vector<string> out;

	void stringToObjectArray(string);
};

