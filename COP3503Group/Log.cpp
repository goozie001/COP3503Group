#include "Log.h"
#include "Integer.h"
#include "Expression.h"
#include "Operator.h"


Log::Log()
{
}

Log::Log(Number* base, Number* argument) {
	this->base = base;
	this->argument = argument;
}

Log::~Log()
{
}

Number *Log::getBase() {
	return base;
}

Number *Log::getArgument() {
	return argument;
}

// Overridden methods

float Log::getFloatValue() {
	return floatValue;
}

// TODO: Implement simplify Log method
Number *Log::simplify() {
	if (dynamic_cast<Integer*>(base) != 0) {
		if (dynamic_cast<Integer*>(argument) != 0) {
			Integer *baseInt = dynamic_cast<Integer*>(base);
			Integer *argInt = dynamic_cast<Integer*>(argument);
			int a = baseInt->getIntValue();
			int b = argInt->getIntValue();
			int c = 1;
			int d = 0;
			while (d <= b) {
				d = pow(a, c);
				if (d == b) {
					return new Integer(c);
				}
				else {
					++c;
				}
			}
			a = baseInt->getIntValue();
			int divisor = smallestDivisor(b);
			if (divisor == b) {
				return new Log(baseInt, argInt);
			}
			else {
				Log *newLog1 = new Log(baseInt, new Integer(divisor));
				Log *newLog2 = new Log(baseInt, new Integer(b / divisor));
				Operator *plus = new Operator("+");
				Expression *newEx = new Expression(newLog1, newLog2, plus);
				return newEx;
			}
		}
	}
}

// TODO: Implement Log toString method
string Log::toString() {
	string s = "Log_" + base->toString() + ":(" + argument->toString() + ")";
	return s;
}

int Log::smallestDivisor(int number) {
	int i;
	for (i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			break;
		}
	}
	return i;
}