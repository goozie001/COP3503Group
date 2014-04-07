#include "Fraction.h"
#include "Calculate.h"

// Constructors

Fraction::Fraction()
{
}

Fraction::Fraction(Number *numerator, Number *denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	this->floatValue = numerator->getFloatValue() / denominator->getFloatValue();
}


Fraction::~Fraction()
{
}

// Getters

Number *Fraction::getNumerator() {
	return numerator;
}

Number *Fraction::getDenominator() {
	return denominator;
}

// Overridden functions

float Fraction::getFloatValue() {
	return floatValue;
}

// FIXME: Fix this entire method
Number *Fraction::simplify() {
	Number *n = numerator->simplify();
	Number *d = denominator->simplify();

	Log *logN = dynamic_cast<Log*>(n);
	if (logN != 0) {
		Log *logD = dynamic_cast<Log*>(d);
		if (logD != 0) {
			if (logN->getBase() == logD->getBase()) {
				Log *newLog = new Log(logD->getArgument(), logN->getArgument());
				return newLog;
			}
		}
	}
	Calculate *calc = new Calculate();
	Irrational *irrD = dynamic_cast<Irrational*>(d);
	if (irrD != 0) {
		Number *originalBase = irrD->getBase();
		Number *exponent = irrD->getExponent();
		if (exponent < 0) {
			Number *temp = new Integer(-1);
			Number *newExponent = calc->multiply(temp, exponent);
			Number *newIrrat = new Irrational(originalBase, newExponent);
			Number *newNumerator = calc->multiply(n, newIrrat);
			Number *newDenominator = calc->divide(d, irrD);
		}
		Number *newDenom = originalBase;
		
	}
}

// TODO: Implement toString method
string Fraction::toString() {

}