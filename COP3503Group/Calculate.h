#pragma once
#include "Integer.h"
#include "Log.h"
#include "Irrational.h"
#include "Operator.h"
#include "Pi.h"
#include "E.h"
#include "Expression.h"
#include "Parse.h"

class Calculate
{
public:
	Calculate();
	~Calculate();

	Number *add(Number *numb1, Number *numb2);
	Number *subtract(Number *numb1, Number *numb2);
	Number *multiply(Number *numb1, Number *numb2);
	Number *divide(Number *numb1, Number *numb2);
	Number *exponentiate(Number *numb1, Number *numb2);
	float toFloat(Number *numb);

	Integer *gcd(Integer *num, Integer *denom);
};