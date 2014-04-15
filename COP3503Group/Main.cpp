#pragma once
#include "Parse.h"
#include <sstream>

int main() {
	int i = 0;
	Parse *p = new Parse();
	while (i == 0) {
		string input;
		cout << "1) Compute New Expression" << endl;
		cout << "2) Review Previous Expressions and Answers" << endl;
		cout << "3) Help!" << endl;
		cout << "4) Exit" << endl;
		cout << "Please Select a Menu Option by entering an integer from 1-4" << endl;

		try {
			cin.clear();
			cin >> input;
			if (cin.fail() || !((int)input[0] >= 49 && (int)input[0] <= 52) || input.size() > 1) {
				throw invalid_argument("Only 1, 2, 3, or 4 may be input");
			}
		}
		catch (exception &exc){
			cerr << exc.what() << endl << endl;
			input[0] = '5';
		}

		switch (input[0]) {
		case '1':
		{
					string in1;
					cout << "Please input the expression to be calculated." << endl;
					try{
						cin >> in1;
						Number *num = p->pseudoMain(in1);
						cout << num->toString() << endl << endl;
					}
					catch (exception &e) {
						cerr << e.what() << endl << endl;
					}
					break;
					
		}
		case '2':
		{
					for (int i = 0; i < p->storedAnswers.size(); i++){
						cout << "Input:" << endl;
						cout << p->inputs[i] << endl;
						cout << "Output:" << endl;
						cout << p->storedAnswers[i]->toString() << endl;
					}
					cout << "Press enter to exit." << endl;
					string a;
					cin >> a;
					break;
		}
		case '3':
		{
					cout << "1) Input Format" << endl;
					cout << "2) Operators" << endl;
					cout << "3) Basic Usage Instructions" << endl;
					cin >> input;
					switch (input[0]) {
					case '1':
					{
								cout << "to raise a number or expression to a power use the ^ operator" << endl;
								cout << "to take the square root of a number use sqrt:x" << endl;
								cout << "to take the nth root of a number use nrt:x" << endl;
								cout << "to make a log base b of x, use log_b:x" << endl;
								cout << "to use e and pi, simply enter e and pi" << endl;
								cout << "Press enter to exit." << endl;
								char a;
								cin >> a;
								break;
					}
					case '2':
					{
								cout << "use the + operator to add" << endl;
								cout << "use the - operator to subtract" << endl;
								cout << "use the * operator to multiply" << endl;
								cout << "use the / operator to divide" << endl;
								cout << "any number of parentheses () are supported by this program" << endl;
								cout << "Press enter to exit." << endl;
								char a;
								cin >> a;
								break;
					}
					case'3':
					{
								cout << "In order to use this program, simply select 1 at the first menu in order to enter Calculation mode" << endl;
								cout << "this will allow you to enter in an equation to be computed by the calculator" << endl;
								cout << "You can select option 2 on the first menu to see your previous answers and inputs in a list" << endl;
								cout << "Select option 4 on the first menu to exit the program" << endl;
								cout << "Press enter to exit." << endl;
								char a;
								cin >> a;
								break;
								break;
					}
		}
		case '4':
		{
					i = 1;
					break;
		}
		}
		}
	}
}