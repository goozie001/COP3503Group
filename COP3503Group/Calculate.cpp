#include "Calculate.h"


Calculate::Calculate()
{
}


Calculate::~Calculate()
{
}

Expression *Calculate::add(Expression *numb1, Expression *numb2) {
	Expression *newNumb1 = numb1->simplify();
	Expression *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	int1->getFloatValue();
	if (int1) {
		if (int2) {
			int a = int1->getIntValue() + int2->getIntValue();
			Integer *i = new Integer(a);
			return i;
		}
	}

}

Expression *Calculate::subtract(Expression *numb1, Expression *numb2) {
	Expression *newNumb1 = numb1->simplify();
	Expression *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}

Expression *Calculate::multiply(Expression *numb1, Expression *numb2) {
	Expression *newNumb1 = numb1->simplify();
	Expression *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}

Expression *Calculate::divide(Expression *numb1, Expression *numb2) {
	Expression *newNumb1 = numb1->simplify();
	Expression *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}

Expression *Calculate::exponentiate(Expression *numb1, Expression *numb2) {
	Expression *newNumb1 = numb1->simplify();
	Expression *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}

Expression *Calculate::logarithm(Expression *numb1, Expression *numb2) {
	Expression *newNumb1 = numb1->simplify();
	Expression *newNumb2 = numb2->simplify();

	Integer *int1 = dynamic_cast<Integer*>(newNumb1);
	Integer *int2 = dynamic_cast<Integer*>(newNumb2);
	Irrational *irr1 = dynamic_cast<Irrational*>(newNumb1);
	Irrational *irr2 = dynamic_cast<Irrational*>(newNumb2);
	Log *log1 = dynamic_cast<Log*>(newNumb1);
	Log *log2 = dynamic_cast<Log*>(newNumb2);

	return NULL;
}