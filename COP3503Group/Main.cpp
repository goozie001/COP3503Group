#pragma once
#include "Parse.h"

int main() {
	string s = "1 + 3 - 8 * 9 + (6+3)";
	Parse *p = new Parse();
	int str = p->pseudoMain(s);
	cout << str << endl;
	int i;
	cin >> i;
}