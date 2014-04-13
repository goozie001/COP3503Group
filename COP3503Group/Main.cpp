#pragma once
#include "Parse.h"

int main() {
	string s = "log_3:(108)";
	Parse *p = new Parse();
	vector<Number*> vec = p->pseudoMain(s);
	int i;
	cin >> i;
}