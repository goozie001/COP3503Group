#include "Expression.h"
#include "Operator.h"
#include "Integer.h"
#include "Irrational.h"
#include "Pi.h"
#include "E.h"
#include "Log.h"
#include "Calculate.h"

Expression::Expression()
{

}

Expression::Expression(Number *num1, Number *num2, Operator *oper)
{
	exprVector.push_back(num1);
	exprVector.push_back(oper);
	exprVector.push_back(num2);
}

Expression::Expression(vector<Number*> vec) {
	this->exprVector = vec;
}

Expression::~Expression()
{
	for (size_t i = 0; i < exprVector.size(); i++)
	{
		delete exprVector[i];
	}
	//delete all items in exprVector.
}

string Expression::toString()
{
	string temp;
	for (size_t i = 0; i < exprVector.size(); i++)
	{
		if (dynamic_cast<Expression*>(exprVector[i])) {
			// How do you like this name?
			string incepVecOpString = dynamic_cast<Operator*>(dynamic_cast<Expression*>(exprVector[i])->getVector()[1])->toString();
			if ((dynamic_cast<Operator*>(exprVector[1])->toString() == "/" || dynamic_cast<Operator*>(exprVector[1])->toString() == "^") && (incepVecOpString == "+" || incepVecOpString == "-"))
				temp += "(" + exprVector[i]->toString() + ")";
			else
				temp += exprVector[i]->toString();
		}
		else {
			temp += exprVector[i]->toString();
		}
	}
	return temp;
}

float Expression::getFloatValue()
{
	float temp = 0;
	switch (exprVector.at(1)->toString().at(0))
	{
	case '+': temp = exprVector.at(0)->getFloatValue() + exprVector.at(2)->getFloatValue();
		break;
	case '-': temp = exprVector.at(0)->getFloatValue() - exprVector.at(2)->getFloatValue();
		break;
	case '*': temp = exprVector.at(0)->getFloatValue() * exprVector.at(2)->getFloatValue();
		break;
	case '/': temp = exprVector.at(0)->getFloatValue() / exprVector.at(2)->getFloatValue();
		break;
	case '^': temp = pow(exprVector.at(0)->getFloatValue(), exprVector.at(2)->getFloatValue());
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
	if (exprVector[1]->toString() == "/") {
		if (newN1->getFloatValue() > 0.0 && newN2->getFloatValue() < 0.0) {
			Integer *neg = new Integer(-1);
			Calculate *calc = new Calculate();
			newN1 = calc->multiply(neg, newN1);
			newN2 = calc->multiply(neg, newN2);
			delete calc;
			if (neg != newN1 && neg != newN2) {
				delete neg;
			}
		}
	}
	Number *newN3;
	Operator *newOp = new Operator(dynamic_cast<Operator*>(exprVector[1])->toString());
	Calculate *calc = new Calculate();
	if (newOp->toString() == "+") {
		newN3 = calc->add(newN1, newN2);
	}
	else if (newOp->toString() == "-") {
		newN3 = calc->subtract(newN1, newN2);
	}
	else if (newOp->toString() == "*") {
		newN3 = calc->multiply(newN1, newN2);
	}
	else if (newOp->toString() == "/") {
		newN3 = calc->divide(newN1, newN2);
	}
	else if (newOp->toString() == "^") {
		newN3 = calc->exponentiate(newN1, newN2);
	}
	else {
		throw exception("Operator not recognized.");
	}
	delete newOp, calc;
	if (!dynamic_cast<Expression*>(newN3)) {
		if (&newN1 != &newN3) delete newN1;
		if (&newN2 != &newN3) delete newN2;
	}
	return newN3;
}