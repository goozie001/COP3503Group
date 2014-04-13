#pragma once
#include "Integer.h"
#include "Log.h"
#include "Irrational.h"
#include "Operator.h"

//Example commit

class Calculate
{
public:
	Calculate();
	~Calculate();

	Expression *add(Expression *numb1, Expression *numb2);
	Expression *subtract(Expression *numb1, Expression *numb2);
	Expression *multiply(Expression *numb1, Expression *numb2);
	Expression *divide(Expression *numb1, Expression *numb2);
	Expression *exponentiate(Expression *numb1, Expression *numb2);
	Expression *logarithm(Expression *numb1, Expression *numb2);
	float toFloat(Expression *numb);
};

