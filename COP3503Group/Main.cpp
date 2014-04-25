#pragma once
#include "Parse.h"
#include <sstream>

int main() {
	int i = 0;
	Parse *p = new Parse();
	string ans;
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
				cin.clear();
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
						ans = num->toString();
					}
					catch (exception &e) {
						cerr << e.what() << endl << endl;
						p->inputs.pop_back();
					}
					break;

		}
		case '2':
		{
					bool exit2 = false;
					while (!exit2){
						for (int i = 0; i < p->storedAnswers.size(); i++){
							cout << "Input " << i + 1 << ":  " << endl;
							cout << p->inputs[i] << endl;
							cout << "Output " << i + 1 << ":  " << endl;
							cout << p->storedAnswers[i]->toString() << endl;
						}
						cout << "1) Show floating-point form for an answer" << endl;
						cout << "2) Set ans keyword to a previous expression's answer" << endl;
						cout << "3) Return to main menu" << endl;
						cout << "Please Select a Menu Option by entering an integer from 1-3" << endl;
						int a;
						cin >> a;
						if (a == 1){
							int n = 0;
							bool exit = false;
							while (!exit){
								cout << "Which output would you like to see Floating-Point form of?" << endl;
								cin >> n;
								if (n < 1 || n > p->storedAnswers.size()){
									cout << "Invalid entry, please try again." << endl;
								}
								else{
									exit = true;
								}
							}
							float result = p->storedAnswers[n - 1]->getFloatValue();
							cout << "Float value of ans" << n << " is:  " << result << endl;
						}
						else if (a == 2){
							bool exit = false;
							int n = 0;
							while (!exit){
								cout << "Which expression's answer would you like to set as keyword ans" << endl;
								
								if (n < 1 || n > p->storedAnswers.size()){
									cout << "Invalid entry, please try again." << endl;
								}
								else{
									exit = true;
								}
							}
							ans = p->storedAnswers[n - 1]->toString();
							cout << "Keyword ans is now:  " << ans << endl;
						}
						else if (a == 3){
							cout << "Returning to Main Menu." << endl;
							exit2 = true;
						}
						else{
							cout << "Invalid input, please enter an integer from 1-3." << endl;
						}
						break;
					}
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