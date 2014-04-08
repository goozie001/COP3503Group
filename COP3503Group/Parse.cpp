#include "Parse.h"
#include <vector>
#include <stack>

Parse::Parse()
{
}


Parse::~Parse()
{
}

string Parse::evaluateString(string str) {

	// We use the Shunting Yard Algorithm to store the operators separately from the numbers in
	// order of precedence to do all of the calculations in the future.
	string modStr = removeSpaces(str);
	stack<string> out;
	stack<string> operators;

	int i = 0;
	while (i < modStr.length()) {
		if (isNumber(modStr.at(i))) {
			string temp;
			temp.push_back(modStr.at(i));
			i++;
			bool number = true;
			while (number) {
				if (isNumber(modStr.at(i))) {
					temp.push_back(modStr.at(i));
					i++;
				}
				else {
					out.push(temp);
					number = false;
				}
			}
		}
		if (isOperator(modStr.at(i))) {

		}
	}
}

string Parse::removeSpaces(string str) {
	string newS;

	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) != ' ') {
			newS = newS + str.at(i);
		}
	}

	return newS;
}

bool Parse::isNumber(char ch) {
	if (48 <= ch && ch <= 57) return true;
	return false;
}

bool Parse::isOperator(char ch) {
	if (40 <= ch && ch <= 43) return true;
	if (ch == 45) return true;
	if (ch == 47) return true;
	if (ch == 94) return true;
	return false;
}