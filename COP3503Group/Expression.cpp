#include "Expression.h"
#include "Operator.h"

Expression::Expression()
{

}

Expression::Expression(Number *num1, Number *num2, Operator *oper)
{
	exprVector.push_back(num1);
	exprVector.push_back(oper);
	exprVector.push_back(num2);
}
Expression::~Expression()
{
	for (size_t i = 0; i < exprVector.size(); i++)
	{
		delete exprVector[i];
	}
	//delete exprVector;
}

string Expression::toString()
{
	string temp;
	for (size_t i = 0; i < exprVector.size(); i++)
	{
		temp += exprVector[i]->toString();
	}
	return temp;
}

float Expression::getFloatValue()
{
	float temp = 0;
	switch (exprVector.at(2)->toString().at(0))
	{
	case '+': temp = exprVector.at(0)->getFloatValue() + exprVector.at(1)->getFloatValue();
		break;
	case '-': temp = exprVector.at(0)->getFloatValue() - exprVector.at(1)->getFloatValue();
		break;
	case '*': temp = exprVector.at(0)->getFloatValue() * exprVector.at(1)->getFloatValue();
		break;
	case '/': temp = exprVector.at(0)->getFloatValue() / exprVector.at(1)->getFloatValue();
		break;
	case '^': temp = pow(exprVector.at(0)->getFloatValue(), exprVector.at(1)->getFloatValue());
		break;
	default: break;
	}
	return temp;
}

vector<Number*> Expression::getVector()
{
	return exprVector;
}

Number *Expression::simplify() {
	Number *newN1 = exprVector[0]->simplify();
	Number *newN2 = exprVector[2]->simplify();
	Operator *newOp = new Operator(dynamic_cast<Operator*>(exprVector[1])->toString());
	return new Expression(newN1, newN2, newOp);
}