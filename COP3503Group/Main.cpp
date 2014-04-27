#pragma once
#include "Parse.h"
#include <sstream>
#include <iostream>
#include <limits>
#include <conio.h>


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
						cin.ignore();
						getline(cin, in1);
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
						cout << "Previous Expressions and Answers:" << endl;
						for (unsigned i = 0; i < p->storedAnswers.size(); i++){
							cout << '\t' << "Input " << i + 1 << ":  " << endl;
							cout << '\t' << p->inputs[i] << endl;
							cout << '\t' << "Output " << i + 1 << ":  " << endl;
							cout << '\t' << p->storedAnswers[i]->toString() << endl;
							cout << endl;
						}
						cout << "1) Show floating-point form for an answer" << endl;
						cout << "2) Set ans keyword to a previous expression's answer" << endl;
						cout << "3) Display current value of ans keyword" << endl;
						cout << "4) Return to main menu" << endl;
						cout << "Please Select a Menu Option by entering an integer from 1-4" << endl;
						string a;

						try {
							cin.clear();
							cin >> a;
							if (cin.fail() || !((int)a[0] >= 49 && (int)a[0] <= 52) || a.size() > 1) {
								throw invalid_argument("Only 1, 2, 3, or 4 may be input");
							}
						}
						catch (exception &exc){
							cerr << exc.what() << endl << endl;
							a[0] = '5';
						}
						switch (a[0]) {
						case '1':
						{
									unsigned n = 0;
									bool exit = false;
									while (!exit){
										cout << "Which output would you like to see Floating-Point form of?" << endl;
										try{
											cin.clear();
											cin >> n;
											if (cin.fail()){
												throw invalid_argument("Only integers may be entered");
											}
										}
										catch (exception &exc){
											cerr << exc.what() << endl << endl;
										}
										if (n < 1 || n > p->storedAnswers.size()){
											cout << "Invalid entry, please try again." << endl;
										}
										else{
											exit = true;
										}
									}
									float result = p->storedAnswers[n - 1]->getFloatValue();
									cout << "Float value of Output" << n << " is:  " << result << endl << endl;
									break;
						}
						case '2':
						{
									bool exit = false;
									int n = 0;
									while (!exit){
										cout << "Which expression's answer would you like to set as keyword ans" << endl;
										try{
											cin.clear();
											cin >> n;
											if (cin.fail()){
												throw invalid_argument("Only integers may be entered");
											}
										}
										catch (exception &exc){
											cerr << exc.what() << endl << endl;
										}
										if (n < 1 || n > p->storedAnswers.size()){
											cout << "Invalid entry, please try again." << endl;
										}
										else{
											exit = true;
										}
									}
									ans = p->storedAnswers[n - 1]->toString();
									cout << "Keyword ans is now:  " << ans << endl << endl;
									break;
						}
						case '3':
						{
									cout << "The current value of the ans keyword is:  " << ans << endl;
									break;
						}
						case '4':
						{
									cout << "Returning to Main Menu." << endl;
									exit2 = true;
									break;
						}

							break;
						}
					}
					break;
		}
		case '3':
		{
					bool exit2 = false;
					while (!exit2)
					{
						cout << endl << "Help Menu" << endl;
						cout << "1) Input Format" << endl;
						cout << "2) Operators" << endl;
						cout << "3) Basic Usage Instructions" << endl;
						cout << "4) Return to Main Menu" << endl;
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
									cout << "To raise a number or expression to a power use the ^ operator" << endl;
									cout << "To take the square root of a number use sqrt:x" << endl;
									cout << "To take the nth root of a number use nrt:x" << endl;
									cout << "To make a log base b of x, use log_b:x" << endl;
									cout << "To use e and pi, simply enter e and pi" << endl;
									cout << "Press any key to return to help menu." << endl;
									_getch();
									break;
						}
						case '2':
						{
									cout << "Use the + operator to add" << endl;
									cout << "Use the - operator to subtract" << endl;
									cout << "Use the * operator to multiply" << endl;
									cout << "Use the / operator to divide" << endl;
									cout << "Use the ^ operator to exopentiate" << endl;
									cout << "Any number of parentheses () are supported by this program" << endl;
									cout << "Press any key to return to help menu." << endl;
									_getch();
									break;
						}
						case '3':
						{
									cout << "In order to use this program, simply select 1 at the first menu in order to" << endl;
									cout << "enter Calculation mode, this will allow you to enter in an equation to be" << endl;
									cout << "computed by the calculator." << endl;
									cout << "You can select option 2 on the first menu to see your previous answers" << endl;
									cout << "and inputs in a list." << endl;
									cout << "Select option 4 on the first menu to exit the program" << endl;
									cout << "Press any key to return to help menu." << endl;
									_getch();
									break;
						}
						case '4':
						{
									cout << "Returning to Main Menu." << endl << endl;
									exit2 = true;
									break;
						}
						}
					}
					break;
		}
		case '4':
		{
					i = 1;
					break;
		}
		}
	}
}