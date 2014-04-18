#include "Calculate.h"
#include <vector>

Calculate::Calculate()
{
}


Calculate::~Calculate()
{
}

Number *Calculate::add(Number *num1, Number *num2) {
	Integer *int1 = dynamic_cast<Integer*>(num1);
	Integer *int2 = dynamic_cast<Integer*>(num2);
	Irrational *irr1 = dynamic_cast<Irrational*>(num1);
	Irrational *irr2 = dynamic_cast<Irrational*>(num2);
	Log *log1 = dynamic_cast<Log*>(num1);
	Log *log2 = dynamic_cast<Log*>(num2);
	E *e1 = dynamic_cast<E*>(num1);
	E *e2 = dynamic_cast<E*>(num2);
	Pi *pi1 = dynamic_cast<Pi*>(num1);
	Pi *pi2 = dynamic_cast<Pi*>(num2);
	Operator *plus = new Operator("+");
	Operator *minus = new Operator("-");
	Operator *times = new Operator("*");
	Operator *divide = new Operator("/");

	if (int1)
	{
		if (int2)
		{
			int a = int1->getIntValue() + int2->getIntValue();
			Integer *i = new Integer(a);
			//Number *j = new Number(i);
			return i;
		}
		else if (irr2)
		{
			Expression *t = new Expression(int1, irr2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(int1, log2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(int1, e2, plus);
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(int1, pi2, plus);
		}

	}

	if (irr1)
	{
		if (int2)
		{
			Expression *t = new Expression(irr1, int2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			if (irr1->getBase() == irr2->getBase() && irr1->getRootVal() == irr2->getRootVal())
			{
				Integer *temp = new Integer(2);
				Expression *t = new Expression(irr1, temp, times);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);7
				return t;
			}
			else
			{
				Expression *t = new Expression(irr1, irr2, plus);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (log2)
		{
			Expression *t = new Expression(irr1, log2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(irr1, e2, plus);
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(irr1, pi2, plus);
		}

	}

	if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(log1, irr2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			if (log1->getBase() == log2->getBase() && log1->getArgument() == log2->getArgument())
			{
				Integer *temp = new Integer(2);
				Expression *t = new Expression(log1, temp, times);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
			else
			{
				Expression *t = new Expression(log1, log2, plus);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (e2)
		{
			Expression *t = new Expression(log1, e2, plus);
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(log1, pi2, plus);
		}

	}
	if (e1)
	{
		if (int2)
		{
			Expression *t = new Expression(e1, int2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(e1, irr2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(e1, log2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Integer *temp = new Integer(2);
			Expression *t = new Expression(log1, temp, times);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(e1, pi2, plus);
		}

	}
	if (pi1)
	{
		if (int2)
		{
			Expression *t = new Expression(pi1, int2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(pi1, irr2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(pi1, log2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(pi1, e2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Integer *temp = new Integer(2);
			Expression *t = new Expression(pi1, temp, times);
			//change '+' to a term in order to work correctly with Number
			return t;
		}

	}
}

Number *Calculate::subtract(Number *num1, Number *num2) {

	Integer *int1 = dynamic_cast<Integer*>(num1);
	Integer *int2 = dynamic_cast<Integer*>(num2);
	Irrational *irr1 = dynamic_cast<Irrational*>(num1);
	Irrational *irr2 = dynamic_cast<Irrational*>(num2);
	Log *log1 = dynamic_cast<Log*>(num1);
	Log *log2 = dynamic_cast<Log*>(num2);
	E *e1 = dynamic_cast<E*>(num1);
	E *e2 = dynamic_cast<E*>(num2);
	Pi *pi1 = dynamic_cast<Pi*>(num1);
	Pi *pi2 = dynamic_cast<Pi*>(num2);
	Operator *plus = new Operator("+");
	Operator *minus = new Operator("-");
	Operator *times = new Operator("*");
	Operator *divide = new Operator("/");

	if (int1)
	{
		if (int2)
		{
			int a = int1->getIntValue() - int2->getIntValue();
			Integer *i = new Integer(a);
			//Number *j = new Number(i);
			return i;
		}
		else if (irr2)
		{
			Expression *t = new Expression(int1, irr2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(int1, log2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(int1, e2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(int1, pi2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}

	if (irr1)
	{
		if (int2)
		{
			Number *t = new Expression(irr1, int2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			if (irr1->getBase() == irr2->getBase() && irr1->getRootVal() == irr2->getRootVal())
			{
				int a = 0;
				Integer *i = new Integer(a);
				//Number *j = new Number(i);
				return i;
			}
			else
			{
				Expression *t = new Expression(irr1, irr2, minus);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (log2)
		{
			Expression *t = new Expression(irr1, log2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(irr1, e2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(e1, pi2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}

	}

	if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(log1, irr2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			if (log1->getBase() == log2->getBase() && log1->getArgument() == log2->getArgument())
			{
				int a = 0;
				Integer *i = new Integer(a);
				//Number *j = new Number(i);
				return i;
			}
			else
			{
				Expression *t = new Expression(log1, log2, minus);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (e2)
		{
			Expression *t = new Expression(log1, e2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(log1, pi2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}
	if (e1)
	{
		if (int2)
		{
			Expression *t = new Expression(e1, int2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(e1, irr2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(e1, log2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			int a = 0;
			Integer *i = new Integer(a);
			//Number *j = new Number(i);
			return i;
		}
		else if (pi2)
		{
			Expression *t = new Expression(irr1, pi2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}

	}
	if (pi1)
	{
		if (int2)
		{
			Expression *t = new Expression(pi1, int2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(pi1, irr2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(pi1, log2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(pi1, pi2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			int a = 0;
			Integer *i = new Integer(a);
			//Number *j = new Number(i);
			return i;
		}

	}
}

Number *Calculate::multiply(Number *num1, Number *num2)
{
	Integer *int1 = dynamic_cast<Integer*>(num1);
	Integer *int2 = dynamic_cast<Integer*>(num2);
	Irrational *irr1 = dynamic_cast<Irrational*>(num1);
	Irrational *irr2 = dynamic_cast<Irrational*>(num2);
	Log *log1 = dynamic_cast<Log*>(num1);
	Log *log2 = dynamic_cast<Log*>(num2);
	E *e1 = dynamic_cast<E*>(num1);
	E *e2 = dynamic_cast<E*>(num2);
	Pi *pi1 = dynamic_cast<Pi*>(num1);
	Pi *pi2 = dynamic_cast<Pi*>(num2);
	Expression *expr1 = dynamic_cast<Expression*>(num1);
	Expression *expr2 = dynamic_cast<Expression*>(num2);
	Operator *plus = new Operator("+");
	Operator *minus = new Operator("-");
	Operator *times = new Operator("*");
	Operator *quot = new Operator("/");
	Operator *power = new Operator("^");

	if (int1)
	{
		if (int2)
		{
			int a = int1->getIntValue() * int2->getIntValue();
			Integer *t = new Integer(a);
			return t;
		}
		else if (irr2)
		{
			if (int1->getIntValue() == 1)
			{
				return irr2;
			}
			else
			{
				Expression *t = new Expression(int1, irr2, times);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
	}
	else if (log2)
	{
		if (int1->getIntValue() == 1)
		{
			return log2;
		}
		else
		{
			Expression *t = new Expression(int1, log2, times);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}
	else if (e2)
	{
		if (int1->getIntValue() == 1)
		{
			return e2;
		}
		else
		{
			Expression *t = new Expression(int1, e2, times);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}
	else if (pi2)
	{
		if (int1->getIntValue() == 1)
		{
			return pi2;
		}
		else
		{
			Expression *t = new Expression(int1, pi2, times);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}

	if (irr1)
	{
		if (int2)
		{
			if (int2->getIntValue() == 1)
			{
				return irr1;
			}
			else
			{
				Expression *t = new Expression(irr1, int2, times);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (irr2)
		{
			if (irr1->getBase() == irr2->getBase())
			{
				Number *newRootVal = add(irr1->getRootVal(), irr2->getRootVal());
				irr1->setRootVal(newRootVal);
				//Irrational *newIrrational = new Irrational(irr1->getBase(), newrootVal, newconst);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);
				return irr1;
			}
			if (irr1->getRootVal() == irr2->getRootVal())
			{
				Number *newBase = multiply(irr1->getBase(), irr2->getBase());
				irr1->setBase(newBase);
				//Irrational *newIrrational = new Irrational(irr1->getBase(), newrootVal, newconst);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);
				return irr1;
			}
			else
			{
				//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
				Expression *t = new Expression(irr1, irr2, times);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		else if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, log2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, e2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (pi2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, pi2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
	}

	if (log1)
	{
		if (int2)
		{
			if (int2->getIntValue() == 1)
			{
				return log1;
			}
			else
			{
				//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
				Expression *t = new Expression(log1, int2, times);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, irr2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, log2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, e2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (pi2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, pi2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
	}
	if (e1)
	{
		if (int2)
		{
			if (int2->getIntValue() == 1)
			{
				return e1;
			}
			else
			{
				//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
				Expression *t = new Expression(e1, int2, times);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, irr2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, log2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			Integer *temp = new Integer(2);
			Expression *t = new Expression(e1, temp, power);
			return t;
		}
		else if (pi2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, pi2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
	}
	if (pi1)
	{
		if (int2)
		{
			if (int2->getIntValue() == 1)
			{
				return pi1;
			}
			else
			{
				//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
				Expression *t = new Expression(pi1, int2, times);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, irr2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, log2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, e2, times);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (pi2)
		{
			Integer *temp = new Integer(2);
			Expression *t = new Expression(e1, temp, power);
			return t;
		}
	}
}

Number *Calculate::divide(Number *num1, Number *num2)
{
	Integer *int1 = dynamic_cast<Integer*>(num1);
	Integer *int2 = dynamic_cast<Integer*>(num2);
	Irrational *irr1 = dynamic_cast<Irrational*>(num1);
	Irrational *irr2 = dynamic_cast<Irrational*>(num2);
	Log *log1 = dynamic_cast<Log*>(num1);
	Log *log2 = dynamic_cast<Log*>(num2);
	E *e1 = dynamic_cast<E*>(num1);
	E *e2 = dynamic_cast<E*>(num2);
	Pi *pi1 = dynamic_cast<Pi*>(num1);
	Pi *pi2 = dynamic_cast<Pi*>(num2);
	Operator *plus = new Operator("+");
	Operator *minus = new Operator("-");
	Operator *times = new Operator("*");
	Operator *quot = new Operator("/");

	if (int2){
		if (int2->getIntValue() == 0){
			throw invalid_argument("Cannot divide by 0");
		}
	}

	if (int1)
	{
		if (int2)
		{
			int divisor = gcd(int1->getIntValue(), int2->getIntValue());

			Integer *i = new Integer(int1->getIntValue()/divisor);
			Integer *j = new Integer(int2->getIntValue()/divisor);
			if (j->getIntValue() == 1) {
				delete j;
				return i;
			}
			return new Expression(i, j, quot);
		}
		else if (irr2)
		{
			Expression *t = new Expression(int1, irr2, quot);
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(int1, log2, quot);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}

	if (irr1)
	{
		if (int2)
		{
			Expression *t = new Expression(irr1, int2, quot);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			if (irr1->getBase() == irr2->getBase())
			{
				Number *newrootVal = subtract(irr1->getRootVal(), irr2->getRootVal());
				irr1->setRootVal(newrootVal);
				//Irrational *newIrrational = new Irrational(irr1->getBase(), newrootVal, newconst);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);
				return irr1;
			}
			else if (irr1->getRootVal() == irr2->getRootVal())
			{
				Number *newBase = divide(irr1->getRootVal(), irr2->getRootVal());
				irr1->setBase(newBase);
				//Irrational *newIrrational = new Irrational(irr1->getBase(), newrootVal, newconst);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);
				return irr1;
			}
			else if (irr1->getBase() == irr2->getBase() && irr1->getRootVal() == irr2->getRootVal())
			{
				int a = 1;
				Integer *t = new Integer(a);
				return t;

			}
			else
			{
				//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
				Expression *t = new Expression(irr1, irr2, quot);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		else if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, log2, quot);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}

	}

	if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, quot);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, irr2, quot);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			if (log1->getBase() == log2->getBase() && log1->getArgument() == log1->getArgument())
			{
				int a = 1;
				Integer *t = new Integer(a);
				return t;
			}
			else
			{
				//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
				Expression *t = new Expression(log1, log2, quot);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, pi2, quot);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, pi2, quot);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
	}
	if (e1)
	{
		if (int2)
		{
			Expression *t = new Expression(e1, int2, quot);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, irr2, quot);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, log2, quot);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			int a = 1;
			Integer *t = new Integer(a);
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(e1, pi2, quot);
			return t;
		}
	}
	if (pi1)
	{
		if (int2)
		{
			Expression *t = new Expression(pi1, int2, quot);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, irr2, quot);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, log2, quot);
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{

			Expression *t = new Expression(pi1, e2, quot);
			return t;
		}
		else if (pi2)
		{
			int a = 1;
			Integer *t = new Integer(a);
			return t;
		}
	}
}

Number *Calculate::exponentiate(Number *num1, Number *num2){
	Integer *int1 = dynamic_cast<Integer*>(num1);
	Integer *int2 = dynamic_cast<Integer*>(num2);
	Irrational *irr1 = dynamic_cast<Irrational*>(num1);
	Irrational *irr2 = dynamic_cast<Irrational*>(num2);
	Log *log1 = dynamic_cast<Log*>(num1);
	Log *log2 = dynamic_cast<Log*>(num2);
	Pi *pi1 = dynamic_cast<Pi*>(num1);
	Pi *pi2 = dynamic_cast<Pi*>(num2);
	E *e1 = dynamic_cast<E*>(num1);
	E *e2 = dynamic_cast<E*>(num2);

	Operator *plus = new Operator("+");
	Operator *minus = new Operator("-");
	Operator *times = new Operator("*");
	Operator *quot = new Operator("/");
	Operator *power = new Operator("^");

	if (int1)
	{
		int a = int1->getIntValue();
		if (int2)
		{
			int b = 1;
			for (int i = 0; i < int2->getIntValue(); i++)
			{
				b = b*a;
			}
			Integer *t = new Integer(b);
			return t;
		}
	}

	if (irr1)
	{
		if (int2)
		{

			int a = int1->getIntValue() * int2->getIntValue();
			Integer *t = new Integer(a);
			return t;

			Number *newRootVal = multiply(irr1->getRootVal(), int2);
			Irrational *newIrr = new Irrational(irr1->getBase(), newRootVal);
			return newIrr;
		}
	}

	if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, power);
			return t;
		}
	}

	if (e1)
	{
		if (int2)
		{
			Expression *t = new Expression(e1, int2, power);
			return t;
		}
		if (log2)
		{
			Number *newBase = log2->getBase();
			E *e3 = dynamic_cast<E*>(newBase);
			if (e3)
			{
				Number *newArg = log2->getArgument();
				return newArg;
			}
		}
	}
}

int Calculate::gcd(int x, int y)
{
	if (y != 0) {
		x = x % y;
		gcd(y, x); //recursive call by using arithmetic rules
	}

	return x; //base case,return x when y equals 0

}