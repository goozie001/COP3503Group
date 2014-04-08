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
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

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

Number *Calculate::subtract(Number *numb1, Number *numb2) {
	Number *newNumb1 = numb1->simplify();
	Number *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Fraction *frac1 = dynamic_cast<Fraction*>(newNumb1);
	Fraction *frac2 = dynamic_cast<Fraction*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}

Number *Calculate::multiply(Number *numb1, Number *numb2) {
	Number *newNumb1 = numb1->simplify();
	Number *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Fraction *frac1 = dynamic_cast<Fraction*>(newNumb1);
	Fraction *frac2 = dynamic_cast<Fraction*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}

Number *Calculate::divide(Number *numb1, Number *numb2) {
	Number *newNumb1 = numb1->simplify();
	Number *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Fraction *frac1 = dynamic_cast<Fraction*>(newNumb1);
	Fraction *frac2 = dynamic_cast<Fraction*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}

Number *Calculate::exponentiate(Number *numb1, Number *numb2) {
	Number *newNumb1 = numb1->simplify();
	Number *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Fraction *frac1 = dynamic_cast<Fraction*>(newNumb1);
	Fraction *frac2 = dynamic_cast<Fraction*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}

Number *Calculate::logarithm(Number *numb1, Number *numb2) {
	Number *newNumb1 = numb1->simplify();
	Number *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Fraction *frac1 = dynamic_cast<Fraction*>(newNumb1);
	Fraction *frac2 = dynamic_cast<Fraction*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}