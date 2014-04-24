#pragma once
#include "Number.h"
#include "Operator.h"
class Expression :
	public Number
{
public:
	Expression();
	Expression(Number*, Number*, Operator*);
	Expression(vector<Number*>);
	~Expression();

	string toString();
	float getFloatValue();
	Number *simplify();
	vector<Number*> getVector();
private:
	vector<Number*> exprVector;

};
