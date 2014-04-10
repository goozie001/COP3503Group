
#include <stack>

#include "Parse.h"

Parse::Parse()
{
	this->out;
}


Parse::~Parse()
{
}

int Parse::pseudoMain(string str) {
	string newS = removeSpaces(str);
	newS = negativeCheck(newS);
	int a = stringToRPN(newS);
	return a;
}

int Parse::stringToRPN(string str) {

	// We use the Shunting Yard Algorithm to store the operators separately from the numbers in
	// order of precedence to do all of the calculations in the future.
	// TODO: Handle exception of unmatching parentheses.
	if (!matchingParentheses(str)) return NULL;
	stack<string> operators;

	unsigned i = 0;
	while (i < str.length()) {
		string temp;
		temp.push_back(str[i]);
		if (isNumber(str[i])) {
			string numberStr;
			numberStr.push_back(str[i]);
			i++;
			bool number = true;
			while (number) {
				if (isNumber(str[i])) {
					numberStr.push_back(str[i]);
					i++;
				}
				else {
					out.push_back(numberStr);
					number = false;
				}
			}
		}
		else if (isOperator(str[i])) {
			if (operators.empty()) {
				operators.push(temp);
				i++;
			}
			else {
				// o1 == o2
				if (precedence(operators.top()[0]) == precedence(str[i])) {
					if (isLeftAssociative(str[i])) {
						out.push_back(operators.top());
						operators.pop();
					}
				}
				//  o1 < o2
				else if (precedence(operators.top()[0]) > precedence(str[i])) {
					out.push_back(operators.top());
					operators.pop();
				}
				operators.push(temp);
				i++;
			}
		}
		else if (isLeftParenthesis(str[i])) {
			operators.push(temp);
			i++;
		}
		else if (isRightParenthesis(str[i])) {
			bool foundLeft = false;
			while (!foundLeft) {
				if (isLeftParenthesis(operators.top()[0])) {
					operators.pop();
					i++;
					foundLeft = true;
				}
				else {
					out.push_back(operators.top());
					operators.pop();
				}
			}
		}
	}
	while (!operators.empty()) {
		out.push_back(operators.top());
		operators.pop();
	}
	return evaluateRPN();
}

int Parse::evaluateRPN() {
	int ans;
	int i = 0;
	vector<string> solution;
	while (i < out.size()) {
		solution.push_back(out[i]);

		if (solution.size() > 2) {
			char fin = (solution.back()[0]);
			if (isOperator(fin) && (solution.back().length() == 1)) {
				// Deletes operator
				solution.pop_back();

				// Converts last string to a type int.
				string last = solution.back();
				int a;
				istringstream(last) >> a;
				solution.pop_back();

				//Converts next string up in the out vector to type int.
				last = solution.back();
				int b;
				istringstream(last) >> b;
				solution.pop_back();

				if (fin == '+') {
					int val = b + a;

					stringstream myStringStream;
					myStringStream << val;
					string myString = myStringStream.str();

					solution.push_back(myString);
				}
				else if (fin == '-') {
					int val = b - a;

					stringstream myStringStream;
					myStringStream << val;
					string myString = myStringStream.str();

					solution.push_back(myString);
				}
				else if (fin == '*') {
					int val = b * a;

					stringstream myStringStream;
					myStringStream << val;
					string myString = myStringStream.str();

					solution.push_back(myString);
				}
				else if (fin == '^') {
					int val = b ^ a;

					stringstream myStringStream;
					myStringStream << val;
					string myString = myStringStream.str();

					solution.push_back(myString);
				}
			}
		}
		i++;
	}
	string end = solution[0];
	int z;
	istringstream(end) >> z;
	return z;
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
	int a = (int)ch;
	if (48 <= a && a <= 57) return true;
	return false;
}

bool Parse::isOperator(char ch) {
	if (ch == '+') return true;
	if (ch == '-') return true;
	if (ch == '*') return true;
	if (ch == '/') return true;
	if (ch == '^') return true;
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

string Parse::negativeCheck(string str) {
	string fixedString;

	for (int i = 0; i < (str.length() - 1); i++) {
		bool isNegative = false;
		if (i == 0 && str[i] == '-') {
			if (isLeftParenthesis(str[i + 1])) {
				fixedString = fixedString + "(-1";
			}
			else {
				fixedString = fixedString + "(-1)(";
			}
			isNegative = true;
		}
		else if (i < (str.length() - 2) && !isNumber(str[i]) && (str[i + 1]) == '-' && !isRightParenthesis(str[i]) && isNumber(str[i + 2])) {
			fixedString = fixedString + str[i] + "(-1)(";
			isNegative = true;
		}
		else {
			fixedString = fixedString + str[i];
		}

		if (isNegative) {
			while (i < str.length() - 1 && isNumber(str[i + 1])) {
				fixedString = fixedString + str[i + 1];
			}
			fixedString = fixedString + ')';
		}
	}
	fixedString = fixedString + str[str.length() - 1];

	return fixedString;
}

