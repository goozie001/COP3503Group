#pragma once
#include "Parse.h"

int main() {
	string s = "2*sqrt:2 + 3*sqrt:2";
	Parse *p = new Parse();
	Number *vec = p->pseudoMain(s);
	int i;
	cin >> i;
}