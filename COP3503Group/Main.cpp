#pragma once
#include "Parse.h"

int main() {
	string s = "3rt:-8";
	Parse *p = new Parse();
	vector<Number*> vec = p->pseudoMain(s);
	int i;
	cin >> i;
}