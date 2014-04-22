#include "Log.h"
#include "Integer.h"
#include "Expression.h"
#include "Operator.h"


Log::Log()
{
}

Log::Log(Number* base, Number* argument) {
	if (argument->getFloatValue() <= 0 || base->getFloatValue() <= 0) 
		throw out_of_range("The argument and base of log must be greater than zero.");
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
			int baseVal = baseInt->getIntValue();
			int argVal = argInt->getIntValue();

			if (argVal == 1) return new Integer(0);

			// Change of base to evaluate double value of the log.
			double result = log((double)argVal) / log((double)baseVal);
			double intpart;
			// This if statement and the else if aren't strictly necessary, but reduce the
			// runtime for simple logarithms: integer results and 1/integer results.
			if (modf(result, &intpart) == 0.0) {
				return new Integer((int)intpart);
			}

			// Check for common roots of base that equal the argument.
			else if (modf(1 / result, &intpart) == 0.0) {
				return new Expression(new Integer(1), new Integer((int)intpart), new Operator("/"));
			}

			// Check all other fractal representations of logarithms.
			else {
				double rootAns = 2;
				int i = 2;
				while (rootAns >= 2) {
					rootAns = pow(baseVal, 1 / (double)i);
					if (modf(rootAns, &intpart) == 0.0 || modf(rootAns, &intpart) > 0.9999999999) {
						double expAns = 0;
						int j = 2;
						while (expAns <= argVal) {
							expAns = pow(rootAns, j);
							if (expAns == argVal || (modf(expAns, &intpart) > 0.9999999999 && expAns < argVal && expAns + .00001 > argVal)) {
								return new Expression(new Integer(j), new Integer(i), new Operator("/"));
							}
							else {
								++j;
							}
						}
					}
					++i;
				}
			}
			
			// Simplify logs that aren't rational to logs containing smaller arguments.
			baseVal = baseInt->getIntValue();
			int divisor = smallestDivisor(argVal);
			if (divisor == argVal) {
				return new Log(baseInt, argInt);
			}
			else {
				Log *newLog1 = new Log(baseInt, new Integer(divisor));
				Log *newLog2 = new Log(baseInt, new Integer(argVal / divisor));
				Operator *plus = new Operator("+");
				Expression *newEx = new Expression(newLog1, newLog2, plus);
				Number *numb = newEx->simplify();
				delete newEx;
				return numb;
			}
		}
	}
	else {
		double rootAns = 2;
		double intpart;
		int i = 1;
		float baseVal = base->getFloatValue();
		float argVal = argument->getFloatValue();
		while (rootAns >= 1.1) {
			rootAns = pow(baseVal, 1 / (double)i);
			if (modf(rootAns, &intpart) == 0.0 || modf(rootAns, &intpart) > 0.9999999999) {
				double expAns = 0;
				int j = 2;
				while (expAns <= argVal) {
					expAns = pow(rootAns, j);
					if (expAns == argVal || (modf(expAns, &intpart) > 0.9999999999 && expAns < argVal && expAns + .00001 > argVal)) {
						return new Expression(new Integer(j), new Integer(i), new Operator("/"));
					}
					else {
						++j;
					}
				}
			}
			++i;
		}
	}
	return this;
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