#include "Irrational.h"
#include "Integer.h"
#include "Expression.h"
#include "Log.h"
#include "E.h"
#include "Pi.h"
#include <stdexcept>


Irrational::Irrational()
{
}

Irrational::Irrational(Number *base, Number *rootVal) {
	Integer *int1 = dynamic_cast<Integer*>(base);
	Irrational *irr1 = dynamic_cast<Irrational*>(base);
	Log *log1 = dynamic_cast<Log*>(base);
	E *e1 = dynamic_cast<E*>(base);
	Pi *pi1 = dynamic_cast<Pi*>(base);

	Integer *int2 = dynamic_cast<Integer*>(rootVal);


	if (base->getFloatValue() < 0) {
		if (int2 != 0) {
			if (int2->getIntValue() % 2 == 0){
				throw invalid_argument("Cannot take an even root of a negative number");
			}
		}
	}

	this->base = base;
	this->rootVal = rootVal;
}


Irrational::~Irrational()
{
}

Number *Irrational::getBase() {
	return base;
}

Number *Irrational::getRootVal() {
	return rootVal;
}

string Irrational::getValue() {
	return value;
}

// Overridden methods

float Irrational::getFloatValue() {
	return pow(base->getFloatValue(), rootVal->getFloatValue());
}

// TODO: Implement simplify Irrational method
Number *Irrational::simplify() {
	Expression *expr1 = dynamic_cast<Expression*>(base);
	double intpart;
	double nthRoot = pow(base->getFloatValue(), 1 / rootVal->getFloatValue());
	double negRoot = pow(-1 * base->getFloatValue(), 1 / rootVal->getFloatValue());

	if (base->getFloatValue() == 0){
		return new Integer(0);
	}
	if ((modf(nthRoot, &intpart) == 0.0 || modf(nthRoot, &intpart) > .999999999999) && (base->getFloatValue() > 0)){
		return new Integer((int)nthRoot);
	}
	else if (base->getFloatValue() < 0){
		if (modf(negRoot, &intpart) == 0.0 || modf(negRoot, &intpart) > .999999999999){
			return new Integer(-1 * (int)negRoot);
		}
		else if (modf(-base->getFloatValue(), &intpart) == 0.0 || modf(-base->getFloatValue(), &intpart) > .999999999999){
			int intBase = -base->getFloatValue();
			int j = 1;
			for (int i = 2; i < intBase; i++){
				if (intBase % i == 0){
					double baseRoot = pow((double)i, 1 / (double)rootVal->getFloatValue());
					if (modf(baseRoot, &intpart) == 0.0 || modf(baseRoot, &intpart) > .999999999999){
						intBase = intBase / i;
						j = j * baseRoot;
						i--;
					}
				}
			}
			if (j == 1){
				return new Irrational(base, rootVal);
			}
			else{
				return new Expression(new Integer(j), new Irrational(new Integer(-(int)intBase), rootVal), new Operator("*"));
			}
		}
		else if (expr1){
			vector<Number*> exprVector = expr1->getVector();
			int numeratorBase = exprVector[0]->getFloatValue();
			int denominatorBase = exprVector[2]->getFloatValue();
			if (numeratorBase < 0){
				numeratorBase = -numeratorBase;
			}
			if (denominatorBase < 0){
				denominatorBase = -denominatorBase;
			}
			int j = 1;
			int k = 1;
			for (int i = 2; i <= numeratorBase; i++){
				if (numeratorBase % i == 0){
					double baseRoot = pow((double)i, 1 / (double)rootVal->getFloatValue());
					if (modf(baseRoot, &intpart) == 0.0 || modf(baseRoot, &intpart) > .999999999999){
						numeratorBase = numeratorBase / i;
						j = j * baseRoot;
						i--;
					}
				}
			}
			for (int i = 2; i <= denominatorBase; i++){
				if (denominatorBase % i == 0){
					double baseRoot = pow((double)i, 1 / (double)rootVal->getFloatValue());
					if (modf(baseRoot, &intpart) == 0.0 || modf(baseRoot, &intpart) > .999999999999){
						denominatorBase = denominatorBase / i;
						k = k * baseRoot;
						i--;
					}
				}
			}
			if (exprVector[1]->toString() == "/"){
				double numeratorRoot = pow(-1 * exprVector[0]->getFloatValue(), 1 / rootVal->getFloatValue());
				double denominatorRoot = pow(exprVector[2]->getFloatValue(), 1 / rootVal->getFloatValue());
				if ((modf(numeratorRoot, &intpart) == 0.0 || modf(numeratorRoot, &intpart) > .999999999999) && (modf(denominatorRoot, &intpart) == 0.0 || modf(denominatorRoot, &intpart) > .999999999999)){
					return new Expression(new Integer(-1 * (int)numeratorRoot), new Integer((int)denominatorRoot), new Operator("/"));
				}
				else if ((modf(numeratorRoot, &intpart) == 0.0 || modf(numeratorRoot, &intpart) > .999999999999) && numeratorRoot != 1 && k == 1){
					return new Expression(new Integer(-1 * (int)numeratorRoot), new Irrational(new Expression(new Integer(1), exprVector[2], new Operator("/")), rootVal), new Operator("*"));
				}
				else if ((modf(denominatorRoot, &intpart) == 0.0 || modf(denominatorRoot, &intpart) > .999999999999) && j == 1){
					return new Expression(new Irrational(exprVector[0], rootVal), new Integer((int)denominatorRoot), new Operator("/"));
				}
				else{
					if (j == 1 && k == 1){
						return new Irrational(new Expression(new Integer(-numeratorBase), new Integer(denominatorBase), new Operator("/")), rootVal);
					}
					else if (j > 1 && k == 1){
						return new Expression(new Integer(j), new Irrational(new Expression(new Integer(-numeratorBase), new Integer(denominatorBase), new Operator("/")), rootVal), new Operator("*"));
					}
					else if (j == 1 && k > 1){
						if (denominatorBase == 1){
							return new Expression(new Integer(k), new Irrational(new Integer(numeratorBase), rootVal), new Operator("*"));
						}
						return new Expression(new Integer(k), new Irrational(new Expression(new Integer(numeratorBase), new Integer(denominatorBase), new Operator("/")), rootVal), new Operator("*"));
					}
					else if (j > 1 && k > 1){
						if (denominatorBase == 1){
							return new Expression(new Expression(new Integer(j), new Integer(k), new Operator("/")), new Irrational(new Integer(-numeratorBase), rootVal), new Operator("*"));
						}
						return new Expression(new Expression(new Integer(j), new Integer(k), new Operator("/")), new Irrational(new Expression(new Integer(-numeratorBase), new Integer(denominatorBase), new Operator("/")), rootVal), new Operator("*"));
					}
				}
			}
		}
	}
	else if (expr1){
		vector<Number*> exprVector = expr1->getVector();

		int numeratorBase = exprVector[0]->getFloatValue();
		int denominatorBase = exprVector[2]->getFloatValue();
		int j = 1;
		int k = 1;
		for (int i = 2; i <= numeratorBase; i++){
			if (numeratorBase % i == 0){
				double baseRoot = pow((double)i, 1 / (double)rootVal->getFloatValue());
				if (modf(baseRoot, &intpart) == 0.0 || modf(baseRoot, &intpart) > .999999999999){
					numeratorBase = numeratorBase / i;
					j = j * baseRoot;
					i--;
				}
			}
		}
		for (int i = 2; i <= denominatorBase; i++){
			if (denominatorBase % i == 0){
				double baseRoot = pow((double)i, 1 / (double)rootVal->getFloatValue());
				if (modf(baseRoot, &intpart) == 0.0 || modf(baseRoot, &intpart) > .999999999999){
					denominatorBase = denominatorBase / i;
					k = k * baseRoot;
					i--;
				}
			}
		}
		if (exprVector[1]->toString() == "/"){
			double numeratorRoot = pow(exprVector[0]->getFloatValue(), 1 / rootVal->getFloatValue());
			double denominatorRoot = pow(exprVector[2]->getFloatValue(), 1 / rootVal->getFloatValue());
			if ((modf(numeratorRoot, &intpart) == 0.0 || modf(numeratorRoot, &intpart) > .999999999999) && (modf(denominatorRoot, &intpart) == 0.0 || modf(denominatorRoot, &intpart) > .999999999999)){
				return new Expression(new Integer((int)numeratorRoot), new Integer((int)denominatorRoot), new Operator("/"));
			}
			else if ((modf(numeratorRoot, &intpart) == 0.0 || modf(numeratorRoot, &intpart) > .999999999999) && numeratorRoot != 1 && k == 1){
				return new Expression(new Integer((int)numeratorRoot), new Irrational(new Expression(new Integer(1), exprVector[2], new Operator("/")), rootVal), new Operator("*"));
			}
			else if ((modf(denominatorRoot, &intpart) == 0.0 || modf(denominatorRoot, &intpart) > .999999999999) && j == 1){
				return new Expression(new Irrational(exprVector[0], rootVal), new Integer((int)denominatorRoot), new Operator("/"));

			}
			else{
				if (j == 1 && k == 1){
					return new Irrational(base, rootVal);
				}
				else if (j > 1 && k == 1){
					return new Expression(new Integer(j), new Irrational(new Expression(new Integer(numeratorBase), new Integer(denominatorBase), new Operator("/")), rootVal), new Operator("*"));
				}
				else if (j == 1 && k > 1){
					if (denominatorBase == 1){
						return new Expression(new Integer(k), new Irrational(new Integer(numeratorBase), rootVal), new Operator("*"));
					}
					return new Expression(new Integer(k), new Irrational(new Expression(new Integer(numeratorBase), new Integer(denominatorBase), new Operator("/")), rootVal), new Operator("*"));
				}
				else if (j > 1 && k > 1){
					if (denominatorBase == 1){
						return new Expression(new Expression(new Integer(j), new Integer(k), new Operator("/")), new Irrational(new Integer(numeratorBase), rootVal), new Operator("*"));
					}
					return new Expression(new Expression(new Integer(j), new Integer(k), new Operator("/")), new Irrational(new Expression(new Integer(numeratorBase), new Integer(denominatorBase), new Operator("/")), rootVal), new Operator("*"));
				}
			}
		}
	}
	else if (modf(base->getFloatValue(), &intpart) == 0.0 || modf(base->getFloatValue(), &intpart) > .999999999999){
		int intBase = base->getFloatValue();
		int j = 1;
		for (int i = 2; i < intBase; i++){
			if (intBase % i == 0){
				double baseRoot = pow((double)i, 1 / (double)rootVal->getFloatValue());
				if (modf(baseRoot, &intpart) == 0.0 || modf(baseRoot, &intpart) > .999999999999){
					intBase = intBase / i;
					j = j * baseRoot;
					i--;
				}
			}
		}
		if (j == 1){
			return new Irrational(base, rootVal);
		}
		else{
			return new Expression(new Integer(j), new Irrational(new Integer((int)intBase), rootVal), new Operator("*"));
		}
	}
	if (modf(nthRoot, &intpart) != 0.0 || modf(nthRoot, &intpart) < .999999999999){
		return new Irrational(base, rootVal);
	}
}

// TODO: Implement toString method
string Irrational::toString() {
	string s;
	s = rootVal->toString();
	s += "rt:";
	s += "(";
	s += base->toString();
	s += ")";
	return s;
}

void Irrational::setBase(Number *newBase)
{
	base = newBase;
}

void Irrational::setRootVal(Number *newRootVal)
{
	rootVal = newRootVal;
}