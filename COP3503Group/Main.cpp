#pragma once
#include "Parse.h"

int main() {
	string s = "8^(-4/3) * 4";
	Parse *p = new Parse();
	vector<Number*> vec = p->pseudoMain(s);
	int i;
	cin >> i;
}