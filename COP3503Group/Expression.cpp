#include "Expression.h"

Expression::Expression()
{
}

Expression::Expression(Number *numb1, Number *numb2, Operator *oper)
{
	exprVector[0] = numb1;
	exprVector[1] = numb2;
	exprVector[2] = oper;

}
Expression::~Expression()
{
	for (int i = 0; i < exprVector.size(); i++)
	{
		delete exprVector.at(i);
	}
	// delete[] exprVector;
}

string Expression::toString()
{
	string temp;
	for (int i = 0; i < exprVector.size(); i++)
	{
		temp += exprVector.at(i)->toString();
	}
	return temp;
}

float Expression::getFloatValue()
{
	float temp = 0;
	for (int i = 0; i < exprVector.size(); i++)
	{
		temp += exprVector.at(i)->getFloatValue();
	}
	return temp;
}

vector<Number*> Expression::getVector()
{
	return exprVector;
}