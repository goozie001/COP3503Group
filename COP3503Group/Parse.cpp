
#include <stack>
#include <sstream>

#include "Parse.h"

Parse::Parse()
{
}


Parse::~Parse()
{
}

vector<Number*> Parse::pseudoMain(string str) {
	string newS = removeSpaces(str);
	//newS = negativeCheck(newS);
	stringToObjectArray(newS);
	return numberRPN;
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
		if (isRoot(str, i)) {
			vector<Number*> exponent;
			bool isExpression = false;
			string negativeBase;
			if (isPosOrNegNumb(str, i)) {
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
						number = false;
					}
				}
				Integer *integer_i = stringToInteger(numberStr);
				exponent.push_back(integer_i);
				i += 3;
			}
			// Parenthesis at the base
			else if (isLeftParenthesis(str[i])) {
				int c = 1;
				bool isNegativeBase = false;
				if (str[i + 2] == '-') {
					i += 7;
					isNegativeBase = true;
					if (isNumber(str[i])) {
						negativeBase.push_back(str[i]);
						i++;
						bool number = true;
						while (number) {
							if (isNumber(str[i])) {
								negativeBase.push_back(str[i]);
								i++;
							}
							else {
								number = false;
							}
						}
					}
				}
				else if (!isRightParenthesis(str[++i])) {
					if (isLeftParenthesis(str[i])) c++;
					temp = str[i];
				}
				if (!isNegativeBase) {
					while (c != 0) {
						++i;
						if (isLeftParenthesis(str[i])) {
							temp = temp + str[i];
							c++;
						}
						else if (isRightParenthesis(str[i])) {
							c--;
							if (c != 0) temp = temp + str[i];
						}
						else temp = temp + str[i];
					}
					i += 4;
				}
				else {
					int a;
					istringstream(negativeBase) >> a;
					a *= -1;
					Integer *integer_i = new Integer(a);
					exponent.push_back(integer_i);
					i += 5;
				}
			}
			// Parenthesis at the argument
			if (isLeftParenthesis(str[i])) {
				isExpression = true;
				if (!isRightParenthesis(str[++i])) {
					temp = str[i];
				}
				int c = 1;
				while (c != 0) {
					++i;
					if (isLeftParenthesis(str[i])) {
						temp = temp + str[i];
						c++;
					}
					else if (isRightParenthesis(str[i])) {
						c--;
						if (c != 0) temp = temp + str[i];
					}
					else temp = temp + str[i];
				}
				Parse *inception = new Parse;
				exponent = inception->pseudoMain(temp);
				++i;
			}
			if (isExpression) {
				vector<Number*> newVector;
				Parse *inception = new Parse;
				newVector = inception->pseudoMain(temp);
				if (exponent.size() != 1) {
					int a;
				}
				if (newVector.size() == 1) {
					Irrational *irrational_i = new Irrational(newVector[0], exponent[0]);
					numberRPN.push_back(irrational_i);
				}
				else {
					//TODO: Have expression class store multiple numbers in this vector.
				}
				
			}
			else if (isNumber(str[i])) {
				string numberStr;
				numberStr.push_back(str[i]);
				i++;
				bool number = true;
				while (number) {
					if (isNumber(str[i])) {
						numberStr.push_back(str[i]);
						i++;
					}
					else number = false;
				}
				Integer *integer_i = stringToInteger(numberStr);
				number = false;
				Irrational *irrational_i = new Irrational(integer_i, exponent[0]);
				numberRPN.push_back((irrational_i));
			}
		}
		else if (isPosOrNegNumb(str,i)) {
			string numberStr;
			numberStr.push_back(str[i]);
			i++;
			bool number = true;
			while (number) {
				if (isNumber(str[i])) {
					numberStr.push_back(str[i]);
					i++;
				}
				else number = false;
			}
			Integer *integer_i = stringToInteger(numberStr);
			numberRPN.push_back(integer_i);
		}
		else if (isSpecial(str, i)) {
			if (str[i] == 'P' || str[i] == 'p') {
				Pi *pi_i = new Pi();
				numberRPN.push_back(pi_i);
				i += 2;
			}
			else if (str[i] == 'e') {
				E *e_i = new E();
				numberRPN.push_back(e_i);
				++i;
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
				Integer *integer_i = stringToInteger(temp);
				numberRPN.push_back(integer_i);
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
			vector<Number*> base;
			bool isExpression = false;
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
						base.push_back(integer_i);
						number = false;
						++i;
					}
				}
				if (isLeftParenthesis(str[i])) {
					isExpression = true;
					if (!isRightParenthesis(str[++i])) {
						temp = str[i];
					}
					int c = 1;
					while (c != 0) {
						++i;
						if (isLeftParenthesis(str[i])) {
							temp = temp + str[i];
							c++;
						}
						else if (isRightParenthesis(str[i])) {
							c--;
							if (c != 0) temp = temp + str[i];
						}
						else temp = temp + str[i];
					}
					++i;

				}
				else if (isNumber(str[i])) {
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
							Log *log_i = new Log(base[0], integer_i);
							numberRPN.push_back(log_i);
							number = false;
						}
					}
				}
				if (isExpression) {
					vector<Number*> newVector;
					Parse *inception = new Parse;
					newVector = inception->pseudoMain(temp);
					if (newVector.size() == 1) {
						Log *log_i = new Log(base[0], newVector[0]);
						numberRPN.push_back(log_i);
					}
					else {
						//TODO: Have expression class store multiple numbers in this vector.
					}
				}
			}
			else if (isSpecial(str, i)) {
				if (str[i] == 'e') {
					E *e_i = new E();
					base.push_back(e_i);
					i+=2;
					if (isLeftParenthesis(str[i])) {
						isExpression = true;
						if (!isRightParenthesis(str[++i])) {
							temp = str[i];
						}
						int c = 1;
						while (c != 0) {
							++i;
							if (isLeftParenthesis(str[i])) {
								temp = temp + str[i];
								c++;
							}
							else if (isRightParenthesis(str[i])) {
								c--;
								if (c != 0) temp = temp + str[i];
							}
							else temp = temp + str[i];
						}
						++i;

					}
					else if (isNumber(str[i])) {
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
								Log *log_i = new Log(base[0], integer_i);
								numberRPN.push_back(log_i);
								number = false;
							}
						}
					}
					if (isExpression) {
						vector<Number*> newVector;
						Parse *inception = new Parse;
						newVector = inception->pseudoMain(temp);
						if (newVector.size() == 1) {
							Log *log_i = new Log(base[0], newVector[0]);
							numberRPN.push_back(log_i);
						}
						else {
							//TODO: Have expression class store multiple numbers in this vector.
						}
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

Number *Parse::evaluateRPNObject() {
	unsigned i = 0;
	vector<Number*> solution;
	Calculate *calc = new Calculate();

	while (i < numberRPN.size()) {
		solution.push_back(numberRPN[i]);

		if (solution.size() > 2) {
			Number *fin = (solution.back());
			if (dynamic_cast<Operator*>(fin) != 0) {
				Operator *op_i = dynamic_cast<Operator*>(fin);
				// Deletes the operator.
				solution.pop_back();

				Number *a = solution.back();
				solution.pop_back();

				Number *b = solution.back();
				solution.pop_back();

				if (op_i->toString() == "+") {
					Number *numb_i = calc->add(a, b);
					solution.push_back(numb_i);
				}
				else if (op_i->toString() == "-") {
					Number *numb_i = calc->subtract(b, a);
					solution.push_back(numb_i);
				}
				else if (op_i->toString() == "*") {
					Number *numb_i = calc->multiply(b, a);
					solution.push_back(numb_i);
				}
				else if (op_i->toString() == "/") {
					Number *numb_i = calc->divide(b, a);
					solution.push_back(numb_i);
				}
				else if (op_i->toString() == "^") {
					Number *numb_i = calc->exponentiate(b, a);
					solution.push_back(numb_i);
				}
			}
		}
		++i;
	}
	Number *end = solution[0];
	storedAnswers.push_back(end);
	return end;
}

int Parse::evaluateRPN() {
	unsigned i = 0;
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

	for (unsigned i = 0; i < str.length(); i++) {
		if (str[i] == 's') {
			if (str[++i] == 'q') {
				if (str[++i] == 'r') {
					if (str[++i] == 't') {
						newS = newS + "2rt";
					}
				}
			}
		}
		else if (str[i] != ' ') {
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

bool Parse::isRoot(string str, int i) {
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
				number = false;
			}
		}
	}
	else if (isLeftParenthesis(str[i])) {
		int c = 1;
		++i;
		while (c != 0) {
			if (isLeftParenthesis(str[i])) c++;
			else if (isRightParenthesis(str[i])) c--;
			++i;
		}
	}
	if (str[i] == 'r') {
		if (str[i + 1] == 't') {
			if (str[i + 2] == ':') return true;
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
	for (unsigned i = 0; i < str.length(); i++) {
		if (str[i] == '(') a++;
		else if (str[i] == ')') b++;
	}

	if (a == b) return true;
	else return false;
}

string Parse::negativeCheck(string str) {
	string fixedString;
	bool isNegative;
	for (unsigned i = 0; i < (str.length() - 1); i++) {
		isNegative = false;
		bool changeToPositive = false;
		if (i == 0 && str[i] == '-') {
			if (isLeftParenthesis(str[i + 1])) {
				fixedString = fixedString + "(-1";
			}
			else {
				fixedString = fixedString + "((-1)*(";
				changeToPositive = true;
			}
			isNegative = true;
		}
		else if ((str[i] == '-') && (isNumber(str[i - 1]) || isSpecial(str, i - 1) || isPi(str, i - 2)) && (isNumber(str[i + 1]) || isSpecial(str, i + 1))) {
			fixedString = fixedString + "+((-1)*(";
			changeToPositive = true;
			isNegative = true;
		}
		else if (i < (str.length() - 2) && !(isNumber(str[i]) || isSpecial(str, i) || isPi(str, i - 1)) && (str[i + 1]) == '-' && !isRightParenthesis(str[i]) && (isNumber(str[i + 2]) || isSpecial(str, i + 2) || isPi(str, i + 1))) {
			fixedString = fixedString + str[i] + "(-1)*(";
			isNegative = true;
			++i;
		}
		else {
			fixedString = fixedString + str[i];
		}

		if (isNegative) {
			while (i < str.length() - 1 && (isNumber(str[i + 1]) || isSpecial(str, i + 1) || isPi(str, i) || str[i+1] == '/')) {
				fixedString = fixedString + str[++i];
			}
			if (changeToPositive) {
				fixedString = fixedString + ')';
			}
			fixedString = fixedString + ')';
		}
	}
	if (!isNegative || str[str.length() - 1] == ')') {
		fixedString = fixedString + str[str.length() - 1];
	}

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

bool Parse::isSpecial(string str, int i) {
	if (str[i] == 'e') return true;
	else if (str[i] == 'P' || str[i] == 'p') {
		if (str[i + 1] == 'i') return true;
	}
	return false;
}

bool Parse::isPi(string str, int i) {
	if (i >= 0) {
		if (str[i] == 'P' || str[i] == 'p') {
			int a = i + 1;
			if ((a < (str.size() - 1)) && str[a] == 'i') {
				return true;
			}
		}
	}
	return false;
}

bool Parse::isNegativeNumber(string str, int i) {
	if (str[i] == '-' && isNumber(str[i + 1]) && (i == 0 || !isNumber(str[i - 1]))) return true;
	if (str[i] == '-' && (str[i + 1] == 'l' || str[i + 1] == 'L') && !isRightParenthesis(str[i - 1]) && !isNumber(str[i - 1])) return true;
	return false;
}

bool Parse::isPosOrNegNumb(string str, int i) {
	if (isNumber(str[i]) || isNegativeNumber(str, i)) return true;
	return false;
}