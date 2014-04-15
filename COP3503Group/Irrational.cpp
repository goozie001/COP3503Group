#include "Irrational.h"
#include "Integer.h"
#include "Expression.h"


Irrational::Irrational()
{
}

Irrational::Irrational(Number *base, Number *rootVal) {
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
	if (base->getFloatValue() < 0 && (int)(1 / rootVal->getFloatValue()) % 2 == 0)
	{
		//throw out_of_range("Can't take even root of negative number!");
	}
	else
	{
		return pow(base->getFloatValue(), rootVal->getFloatValue());
	}
}

// TODO: Implement simplify Irrational method
Number *Irrational::simplify() {
	Integer *int1 = dynamic_cast<Integer*>(base);
	if (int1 != 0)
	{
		float invertedRootVal = 1 / rootVal->getFloatValue();
		vector<int> primeFactors = int1->getPrimeFactors();
		vector<int> outsideFactors;
		vector<int> insideFactors;
		vector<int> counter;
		int max = 0;
		for (unsigned i = 0; i < primeFactors.size(); i++)
		{
			if (primeFactors.at(i) > max)
			{
				max = primeFactors.at(i);
			}
			counter.push_back(0);
		}
		for (int i = 2; i <= max; i++)
		{
			for (unsigned j = 0; j < primeFactors.size(); j++)
			{
				if (primeFactors.at(j) == i)
				{
					counter.at(i) += 1;
				}
			}
		}
		for (int i = 2; i < counter.size(); i++)
		{
			if (counter.at(i) >= invertedRootVal)
			{
				int temp = counter.at(i) * (int)(counter.at(i) / invertedRootVal);
				for (int j = 0; i < temp; j++)
				{
					outsideFactors.push_back(i);
				}
			}
			for (int k = 0; k < (counter.at(i) % (int)invertedRootVal); k++)
			{
				insideFactors.push_back(i);
			}
		}

		int inside = 1;
		int outside = 1;
		for (int i = 0; i < insideFactors.size(); i++)
		{
			inside *= insideFactors.at(i);
		}
		for (int i = 0; i < outsideFactors.size(); i++)
		{
			outside *= insideFactors.at(i);
		}
		return new Expression(new Integer(outside), new Irrational(new Integer(inside), new Expression(new Integer(1), new Integer((int)invertedRootVal), new Operator("/"))), new Operator("*"));
	}
}

// TODO: Implement toString method
string Irrational::toString() {
	string s;
	s = "( ";
	s += base->toString();
	s += " ) ^ ( ";
	s += rootVal->toString();
	s += " )";
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