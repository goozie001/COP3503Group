#pragma once
#include "Parse.h"

int main() {
	string s = "1 + 3 - 8 * 9 + (6+3)";
	Parse *p = new Parse();
	stack<string> sta = p->evaluateString(s);
	int i;
	cin >> i;
}