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
			int base = baseInt->getIntValue();
			int argument = argInt->getIntValue();
			int c = 1;
			int d = 0;
		/*	while (d <= b) {
				d = pow(a, c);
				if (d == b) {
					return new Integer(c);
				}
				else {
					++c;
				}
			}*/
			// Change of base to evaluate double value of the log.
			double result = log((double)argument) / log((double)base);
			double intpart;
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
					rootAns = pow(base, 1 / (double)i);
					if (modf(rootAns, &intpart) == 0.0 || modf(rootAns, &intpart) > 0.9999999999) {
						double expAns = 0;
						int j = 2;
						while (expAns <= argument) {
							expAns = pow(rootAns, j);
							if (expAns == argument || (modf(expAns, &intpart) > 0.9999999999 && expAns < argument && expAns + .00001 > argument)) {
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
			base = baseInt->getIntValue();
			int divisor = smallestDivisor(argument);
			if (divisor == argument) {
				return new Log(baseInt, argInt);
			}
			else {
				Log *newLog1 = new Log(baseInt, new Integer(divisor));
				Log *newLog2 = new Log(baseInt, new Integer(argument / divisor));
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