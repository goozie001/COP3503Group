#pragma once
#include "Parse.h"

int main() {
	string s = "2rt:(8)";
	Parse *p = new Parse();
	vector<Expression*> vec = p->pseudoMain(s);
	int i;
	cin >> i;
}