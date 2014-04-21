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
	/*
	I'm deleting every Number object from the NumberRPN in Parse, and in
	the Calculate class, when we put objects in to form an Expression, they're
	the original Numbers. Therefore, in order for the Expression class to not
	create a vector of pointers that will soon point to nothing, I am creating
	new objects. The excpetion to this rule is the Operator object, which is
	created in Calculate.
	*/
	if (dynamic_cast<Integer*>(num1)) {
		Integer *newNum1 = dynamic_cast<Integer*>(num1);
		num1 = new Integer(newNum1->getIntValue());
	}
	else if (dynamic_cast<Irrational*>(num1)) {
		Irrational *newNum1 = dynamic_cast<Irrational*>(num1);
		num1 = new Irrational(newNum1->getBase(), newNum1->getRootVal());
	}
	else if (dynamic_cast<Log*>(num1)) {
		Log *newLog = dynamic_cast<Log*>(num1);
		num1 = new Log(newLog->getBase(), newLog->getArgument());
	}
	else if (dynamic_cast<Pi*>(num1)) {
		num1 = new Pi();
	}
	else if (dynamic_cast<E*>(num1)) {
		num1 = new E();
	}
	else if (dynamic_cast<Expression*>(num1)) {
		Expression *newExp = dynamic_cast<Expression*>(num1);
		num1 = new Expression(newExp->exprVector[1], newExp->exprVector[3], dynamic_cast<Operator*>(newExp->exprVector[2]));
	}
	else throw exception("Error 2534C");
;

	if (dynamic_cast<Integer*>(num2)) {
		Integer *newNum2 = dynamic_cast<Integer*>(num2);
		num2 = new Integer(newNum2->getIntValue());
	}
	else if (dynamic_cast<Irrational*>(num2)) {
		Irrational *newNum2 = dynamic_cast<Irrational*>(num2);
		num2 = new Irrational(newNum2->getBase(), newNum2->getRootVal());
	}
	else if (dynamic_cast<Log*>(num2)) {
		Log *newLog = dynamic_cast<Log*>(num2);
		num2 = new Log(newLog->getBase(), newLog->getArgument());
	}
	else if (dynamic_cast<Pi*>(num2)) {
		num2 = new Pi();
	}
	else if (dynamic_cast<E*>(num2)) {
		num2 = new E();
	}
	else if (dynamic_cast<Expression*>(num2)) {
		Expression *newExp = dynamic_cast<Expression*>(num2);
		num2 = new Expression(newExp->exprVector[1], newExp->exprVector[3], dynamic_cast<Operator*>(newExp->exprVector[2]));
	}
	else throw exception("Error 2534C");

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
	delete newN1, newN2, newOp, calc;
	return newN3;
}