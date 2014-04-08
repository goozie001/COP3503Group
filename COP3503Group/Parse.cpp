#include "Parse.h"

Parse::Parse()
{
}


Parse::~Parse()
{
}

stack<string> Parse::evaluateString(string str) {

	// We use the Shunting Yard Algorithm to store the operators separately from the numbers in
	// order of precedence to do all of the calculations in the future.
	string modStr = removeSpaces(str);
	// TODO: Handle exception of unmatching parentheses.
	if (!matchingParentheses(modStr)) return NULL;
	stack<string> out;
	stack<string> operators;

	unsigned i = 0;
	while (i < modStr.length()) {
		string temp;
		temp.push_back(modStr[i]);
		if (isNumber(modStr[i])) {
			string numberStr;
			numberStr.push_back(modStr[i]);
			bool number = true;
			while (number) {
				if (isNumber(modStr[i])) {
					numberStr.push_back(modStr[i]);
					i++;
				}
				else {
					out.push(numberStr);
					number = false;
					i++;
				}
			}
		}
		else if (isOperator(modStr[i])) {
			if (operators.empty()) {
				operators.push(temp);
				i++;
			}
			else {
				// o1 == o2
				if (precedence(operators.top()[0]) == precedence(modStr[i])) {
					if (isLeftAssociative(modStr[i])) {
						out.push(operators.top());
						operators.pop();
					}
				}
				//  o1 < o2
				else if (precedence(operators.top()[0]) > precedence(modStr[i])) {
					out.push(operators.top());
					operators.pop();
				}
				operators.push(temp);
				i++;
			}
		}
		else if (isLeftParenthesis(modStr[i])) {
			operators.push(temp);
			i++;
		}
		else if (isRightParenthesis(modStr[i])) {
			bool foundLeft = false;
			while (!foundLeft) {
				if (isLeftParenthesis(operators.top()[0])) {
					operators.pop();
					i++;
					foundLeft = true;
				}
				else {
					out.push(operators.top());
					operators.pop();
				}
			}
		}
	}
	while (!operators.empty()) {
		out.push(operators.top());
		operators.pop();
	}
	return out;
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
	if (42 <= ch && ch <= 43) return true;
	if (ch == 45) return true;
	if (ch == 47) return true;
	if (ch == 94) return true;
	return false;
}

int Parse::precedence(char ch) {
	if (ch == '^') return 4;
	if (ch == '*' || ch == '/') return 3;
	if (ch == '+' || ch == '-') return 2;
	return 0;
}

bool Parse::isLeftAssociative(char ch) {
	if (ch == '^') return false;
	return true;
}

bool Parse::isLeftParenthesis(char ch) {
	if (ch == '(') return true;
	return false;
}

bool Parse::isRightParenthesis(char ch) {
	if (ch == ')') return true;
	return false;
}

bool Parse::matchingParentheses(string str) {
	// a counts left parentheses while b counts right parentheses.
	int a = 0;
	int b = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') a++;
		else if (str[i] == ')') b++;
	}

	if (a == b) return true;
	else return false;
}

