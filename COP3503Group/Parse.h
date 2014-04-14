#pragma once

#include "Calculate.h"

class Parse
{
public:
	Parse();
	~Parse();
	
	vector<Number*> pseudoMain(string);
	vector<Number*> numberRPN;
	vector<Number*> storedAnswers;

private:
	string removeSpaces(string);
	string negativeCheck(string);

	bool isNumber(char);
	bool isNegativeNumber(string, int);
	bool isPosOrNegNumb(string, int);
	bool isPi(string, int);
	bool isE(char);
	bool isSpecial(string, int);
	bool isLog(string, int);
	bool isRoot(string, int);
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

	Number *evaluateRPNObject();
};

