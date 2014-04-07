#include "Calculate.h"


Calculate::Calculate()
{
}


Calculate::~Calculate()
{
}

Number *Calculate::add(Number *numb1, Number *numb2) {
	Number *newNumb1 = numb1->simplify();
	Number *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Fraction *frac1 = dynamic_cast<Fraction*>(newNumb1);
	Fraction *frac2 = dynamic_cast<Fraction*>(newNumb2);
	int1->getFloatValue();
	frac2->getNumerator();
	if (int1) {
		if (int2) {
			int a = int1->getIntValue() + int2->getIntValue();
			Integer *i = new Integer(a);
			return i;
		}
		if (frac2) {
			//int numerator = (int1->getIntValue() * frac2->getNumerator()) + frac2->getNumerator();
		}
	}

}