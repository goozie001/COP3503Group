
#include <stack>

#include "Parse.h"

Parse::Parse()
{
}


Parse::~Parse()
{
}

int Parse::pseudoMain(string str) {
	string newS = removeSpaces(str);
	newS = negativeCheck(newS);
	stringToObjectArray(newS);
	int a = 0;
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
			if (str[i + 1] == '-' && isNumber(str[i + 2])) {
				temp = '-';
				i++;
				while ((i + 1) < str.length() && isNumber(str[i + 1])) {
					temp = temp + str[i + 1];
					i++;
				}
				out.push_back(temp);
			}
			operators.push("(");
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

void Parse::stringToObjectArray(string str) {

	// We use the Shunting Yard Algorithm to store the operators separately from the numbers in
	// order of precedence to do all of the calculations in the future.
	// TODO: Handle exception of unmatching parentheses.
	if (!matchingParentheses(str)) return;

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
					Integer *integer_i = stringToInteger(numberStr);
					numberRPN.push_back(integer_i);
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
						Operator *operator_i = stringToOperator(operators.top());
						numberRPN.push_back(operator_i);
						operators.pop();
					}
				}
				//  o1 < o2
				else if (precedence(operators.top()[0]) > precedence(str[i])) {
					Operator *operator_i = stringToOperator(operators.top());
					numberRPN.push_back(operator_i);
					operators.pop();
				}
				operators.push(temp);
				i++;
			}
		}
		else if (isLeftParenthesis(str[i])) {
			if (str[i + 1] == '-' && isNumber(str[i + 2])) {
				temp = '-';
				i++;
				while ((i + 1) < str.length() && isNumber(str[i + 1])) {
					temp = temp + str[i + 1];
					i++;
				}
				Operator *operator_i = stringToOperator(temp);
				numberRPN.push_back(operator_i);
			}
			operators.push("(");
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

					Operator *operator_i = stringToOperator(operators.top());
					numberRPN.push_back(operator_i);
					operators.pop();
				}
			}
		}
		else if (isLog(str, i)) {
			i += 4;
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
						Integer *integer_i = stringToInteger(numberStr);
						numberRPN.push_back(integer_i);
						number = false;
					}
				}
			}
		}
	}
	while (!operators.empty()) {
		Operator *operator_i = stringToOperator(operators.top());
		numberRPN.push_back(operator_i);
		operators.pop();
		++i;
	}
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

bool Parse::isLog(string str, int i) {
	if (str[i] == 'L' || str[i] == 'l') {
		if (str[i + 1] == 'O' || str[i + 1] == 'o') {
			if (str[i + 2] == 'G' || str[i + 2] == 'g') {
				if (str[i + 3] == '_') return true;
			}
		}
	}
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
		bool changeToPositive = false;
		if (i == 0 && str[i] == '-') {
			if (isLeftParenthesis(str[i + 1])) {
				fixedString = fixedString + "(-1";
			}
			else {
				fixedString = fixedString + "(-1)(";
			}
			isNegative = true;
		}
		else if (str[i] == '-' && isNumber(str[i - 1]) && isNumber(str[i + 1])) {
			fixedString = fixedString + "+((-1)*(";
			changeToPositive = true;
			isNegative = true;
		}
		else if (i < (str.length() - 2) && !isNumber(str[i]) && (str[i + 1]) == '-' && !isRightParenthesis(str[i]) && isNumber(str[i + 2])) {
			fixedString = fixedString + str[i] + "(-1)*(";
			isNegative = true;
		}
		else {
			fixedString = fixedString + str[i];
		}

		if (isNegative) {
			while (i < str.length() - 1 && isNumber(str[i + 1])) {
				fixedString = fixedString + str[i + 1];
				i++;
			}
			if (changeToPositive) {
				fixedString = fixedString + ')';
			}
			fixedString = fixedString + ')';
		}
	}
	fixedString = fixedString + str[str.length() - 1];

	return fixedString;
}

Integer *Parse::stringToInteger(string str) {
	int a;
	istringstream(str) >> a;
	return new Integer(a);
}

Operator *Parse::stringToOperator(string str) {
	return new Operator(str);
}

