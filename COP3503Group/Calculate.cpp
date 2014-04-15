#include "Calculate.h"

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

	}

	if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (irr2)
		{
			Expression *t = new Expression(log1, irr2, plus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (log2)
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
	}
}

Number *Calculate::subtract(Number *num1, Number *num2) {

	Integer *int1 = dynamic_cast<Integer*>(num1);
	Integer *int2 = dynamic_cast<Integer*>(num2);
	Irrational *irr1 = dynamic_cast<Irrational*>(num1);
	Irrational *irr2 = dynamic_cast<Irrational*>(num2);
	Log *log1 = dynamic_cast<Log*>(num1);
	Log *log2 = dynamic_cast<Log*>(num2);
	Expression *exp1 = dynamic_cast<Expression*>(num1);
	Expression *exp2 = dynamic_cast<Expression*>(num2);
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

	}

	if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (irr2)
		{
			Expression *t = new Expression(log1, irr2, minus);
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (log2)
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
	}
}

Number *Calculate::multiply(Number *num1, Number *num2) {
	Integer *int1 = dynamic_cast<Integer*>(num1);
	Integer *int2 = dynamic_cast<Integer*>(num2);
	Irrational *irr1 = dynamic_cast<Irrational*>(num1);
	Irrational *irr2 = dynamic_cast<Irrational*>(num2);
	Log *log1 = dynamic_cast<Log*>(num1);
	Log *log2 = dynamic_cast<Log*>(num2);
	Operator *plus = new Operator("+");
	Operator *minus = new Operator("-");
	Operator *times = new Operator("*");
	Operator *divide = new Operator("/");

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
			if (irr1->getRootVal()->toString() == irr2->getRootVal()->toString())
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
	Operator *plus = new Operator("+");
	Operator *minus = new Operator("-");
	Operator *times = new Operator("*");
	Operator *quot = new Operator("/");
	if (int1)
	{
		if (int2)
		{
			if (int2->getIntValue() == 0)
			{
				return NULL;
			}
			else
			{
				int a = int1->getIntValue() / int2->getIntValue();
				Integer *t = new Integer(a);
				return t;
			}
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
			if (int2->getIntValue() == 0)
			{
				return NULL;
			}
			else
			{
				Expression *t = new Expression(irr1, int2, quot);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
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
			if (int2->getIntValue() == 0)
			{
				return NULL;
			}
			else
			{
				Expression *t = new Expression(log1, int2, quot);
				//change '+' to a term in order to work correctly with Number
				return t;
			}
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
	}
}