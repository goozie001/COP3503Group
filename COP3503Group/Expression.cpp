#include "Expression.h"
#include "Operator.h"

Expression::Expression()
{

}

Expression::Expression(Number *num1, Number *num2, Operator *oper)
{
	Expression *expr1 = dynamic_cast<Expression*>(num1);
	Expression *expr2 = dynamic_cast<Expression*>(num2);
	if (expr1){
		for (size_t i = 0; i < expr1->getVector().size(); i++){
			this->exprVector.push_back(expr1->getVector()[i]);
		}
		if (expr2){
			exprVector.push_back(oper);
			for (size_t i = 0; i < expr2->getVector().size(); i++){
				this->exprVector.push_back(expr2->getVector()[i]);
			}
		}
		else{
			exprVector.push_back(oper);
			exprVector.push_back(num2);
		}
	}
	else if (expr2){
		exprVector.push_back(num1);
		exprVector.push_back(oper);
		for (size_t i = 0; i < expr2->getVector().size(); i++){
			this->exprVector.push_back(expr2->getVector()[i]);
		}
	}
}
Expression::~Expression()
{
	for (size_t i = 0; i < exprVector.size(); i++)
	{
		delete exprVector.at(i);
	}
	//delete exprVector;
}

string Expression::toString()
{
	string temp;
	for (size_t i = 0; i < exprVector.size(); i++)
	{
		temp += exprVector.at(i)->toString();
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