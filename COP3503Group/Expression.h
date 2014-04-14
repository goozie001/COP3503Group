#pragma once
#include "Number.h"
#include "Operator.h"
class Expression :
	public Number
{
public:
	Expression();
	Expression(Number*, Number*, Operator*);
	~Expression();

	string toString();
	float getFloatValue();
	vector<Number*> getVector();
private:
	vector<Number*> exprVector;

};
