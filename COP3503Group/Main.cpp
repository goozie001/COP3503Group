#pragma once
#include "Parse.h"

int main() {
	string s = "3-log_9:(-3)";
	Parse *p = new Parse();
	vector<Number*> vec = p->pseudoMain(s);
	int i;
	cin >> i;
}