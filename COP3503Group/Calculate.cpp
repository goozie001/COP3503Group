#include "Calculate.h"
#include <vector>
#include <stdexcept>
#include "Number.h"

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
	Expression *expr1 = dynamic_cast<Expression*>(num1);
	Expression *expr2 = dynamic_cast<Expression*>(num2);
	E *e1 = dynamic_cast<E*>(num1);
	E *e2 = dynamic_cast<E*>(num2);
	Pi *pi1 = dynamic_cast<Pi*>(num1);
	Pi *pi2 = dynamic_cast<Pi*>(num2);

	if (expr1 && expr2) {
		if (expr2->getVector()[1]->toString() == "+"){
			return add(add(expr1, expr2->getVector()[0]), expr2->getVector()[2]);
		}
		else if (expr2->getVector()[1]->toString() == "-"){
			return subtract(add(expr1, expr2->getVector()[0]), expr2->getVector()[2]);
		}
		else if (expr2->getVector()[1]->toString() == "*"){ // going to need to run mass if statements, checking if they are the same expression
			if (expr1->getVector()[1]->toString() == "+"){
				return add(add(expr1->getVector()[0], expr2), expr1->getVector()[2]);
			}
			if (expr1->getVector()[1]->toString() == "-"){
				return add(subtract(expr1->getVector()[0], expr2), expr1->getVector()[2]);
			}
			if (expr1->getVector()[1]->toString() == "*"){
				Integer *intA = dynamic_cast<Integer*>(expr1->getVector()[2]);
				Integer *intB = dynamic_cast<Integer*>(expr2->getVector()[2]);
				Irrational *irrA = dynamic_cast<Irrational*>(expr1->getVector()[2]);
				Irrational *irrB = dynamic_cast<Irrational*>(expr2->getVector()[2]);
				Log *logA = dynamic_cast<Log*>(expr1->getVector()[2]);
				Log *logB = dynamic_cast<Log*>(expr2->getVector()[2]);
				Expression *exprA = dynamic_cast<Expression*>(expr1->getVector()[2]);
				Expression *exprB = dynamic_cast<Expression*>(expr2->getVector()[2]);
				E *eA = dynamic_cast<E*>(expr1->getVector()[2]);
				E *eB = dynamic_cast<E*>(expr2->getVector()[2]);
				Pi *piA = dynamic_cast<Pi*>(expr1->getVector()[2]);
				Pi *piB = dynamic_cast<Pi*>(expr2->getVector()[2]);
				if (intA){
					if (intB){
						return multiply(add(expr1->getVector()[0], expr2->getVector()[0]), add(intA, intB));
					}
				}
				if (eA){
					if (eB){
						return multiply(add(expr1->getVector()[0], expr2->getVector()[0]), eA);
					}
				}
				if (irrA){
					if (irrB){
						if (irrA->getBase()->getFloatValue() == irrB->getBase()->getFloatValue() && irrA->getRootVal()->getFloatValue() == irrB->getRootVal()->getFloatValue()){
							return multiply(add(expr1->getVector()[0], expr2->getVector()[0]), irrA);
						}
					}
				}
				if (logA){
					if (logB){
						if (logA->getBase()->getFloatValue() == logB->getBase()->getFloatValue() && logA->getArgument()->getFloatValue() == logB->getArgument()->getFloatValue()){
							return multiply(add(expr1->getVector()[0], expr2->getVector()[0]), logA);
						}
					}
				}
				if (piA){
					if (piB){
						return multiply(add(expr1->getVector()[0], expr2->getVector()[0]), piA);
					}
				}
				else{
					return new Expression(expr1, expr2, new Operator("+"));
				}

			}
		}
		else if (expr2->getVector()[1]->toString() == "/"){
			if (expr1->getVector()[1]->toString() == "+"){
				return add(add(expr1->getVector()[0], expr2), expr1->getVector()[2]);
			}
			if (expr1->getVector()[1]->toString() == "-"){
				return add(subtract(expr1->getVector()[0], expr2), expr1->getVector()[2]);
			}
			if (expr1->getVector()[1]->toString() == "/"){
				Integer *intA = dynamic_cast<Integer*>(expr1->getVector()[2]);
				Integer *intB = dynamic_cast<Integer*>(expr2->getVector()[2]);
				Irrational *irrA = dynamic_cast<Irrational*>(expr1->getVector()[2]);
				Irrational *irrB = dynamic_cast<Irrational*>(expr2->getVector()[2]);
				Log *logA = dynamic_cast<Log*>(expr1->getVector()[2]);
				Log *logB = dynamic_cast<Log*>(expr2->getVector()[2]);
				Expression *exprA = dynamic_cast<Expression*>(expr1->getVector()[2]);
				Expression *exprB = dynamic_cast<Expression*>(expr2->getVector()[2]);
				E *eA = dynamic_cast<E*>(expr1->getVector()[2]);
				E *eB = dynamic_cast<E*>(expr2->getVector()[2]);
				Pi *piA = dynamic_cast<Pi*>(expr1->getVector()[2]);
				Pi *piB = dynamic_cast<Pi*>(expr2->getVector()[2]);
				if (intA){
					if (intB){
						return divide(add(multiply(expr1->getVector()[0], intB), multiply(expr2->getVector()[0], intA)), multiply(intA, intB));
					}
				}
				if (eA){
					if (eB){
						return divide(add(expr1->getVector()[0], expr2->getVector()[0]), eA);
					}
				}
				if (irrA){
					if (irrB){
						if (irrA->getBase()->getFloatValue() == irrB->getBase()->getFloatValue() && irrA->getRootVal()->getFloatValue() == irrB->getRootVal()->getFloatValue()){
							return divide(add(expr1->getVector()[0], expr2->getVector()[0]), irrA);
						}
					}
				}
				if (logA){
					if (logB){
						if (logA->getBase()->getFloatValue() == logB->getBase()->getFloatValue() && logA->getArgument()->getFloatValue() == logB->getArgument()->getFloatValue()){
							return divide(add(expr1->getVector()[0], expr2->getVector()[0]), logA);
						}
					}
				}
				if (piA){
					if (piB){
						return divide(add(expr1->getVector()[0], expr2->getVector()[0]), piA);
					}
				}
				else{
					return new Expression(expr1, expr2, new Operator("+"));
				}

			}
		}
		/*
		else if (expr2->getVector()[1]->toString() == "^"){
		if (expr1->getVector()[1]->toString() == "^"){
		Integer *intA2 = dynamic_cast<Integer*>(expr1->getVector()[2]);
		Integer *intB2= dynamic_cast<Integer*>(expr2->getVector()[2]);
		Irrational *irrA2 = dynamic_cast<Irrational*>(expr1->getVector()[2]);
		Irrational *irrB2 = dynamic_cast<Irrational*>(expr2->getVector()[2]);
		Log *logA2 = dynamic_cast<Log*>(expr1->getVector()[2]);
		Log *logB2 = dynamic_cast<Log*>(expr2->getVector()[2]);
		E *eA2 = dynamic_cast<E*>(expr1->getVector()[2]);
		E *eB2 = dynamic_cast<E*>(expr2->getVector()[2]);
		Pi *piA2 = dynamic_cast<Pi*>(expr1->getVector()[2]);
		Pi *piB2 = dynamic_cast<Pi*>(expr2->getVector()[2]);
		Integer *intA = dynamic_cast<Integer*>(expr1->getVector()[0]);
		Integer *intB = dynamic_cast<Integer*>(expr2->getVector()[0]);
		Irrational *irrA = dynamic_cast<Irrational*>(expr1->getVector()[0]);
		Irrational *irrB = dynamic_cast<Irrational*>(expr2->getVector()[0]);
		Log *logA = dynamic_cast<Log*>(expr1->getVector()[0]);
		Log *logB = dynamic_cast<Log*>(expr2->getVector()[0]);
		Expression *exprA = dynamic_cast<Expression*>(expr1->getVector()[0]);
		Expression *exprB = dynamic_cast<Expression*>(expr2->getVector()[0]);
		E *eA = dynamic_cast<E*>(expr1->getVector()[0]);
		E *eB = dynamic_cast<E*>(expr2->getVector()[0]);
		Pi *piA = dynamic_cast<Pi*>(expr1->getVector()[0]);
		Pi *piB = dynamic_cast<Pi*>(expr2->getVector()[0]);
		if (intA2 && intB2 || irrA2 && irrB2 || logA2 && logB2 || eA2 && eB2 || piA2 && piB2){
		if (intA2->getIntValue() == intB2->getIntValue() || irrA2->getBase()->getFloatValue() == irrB2->getBase()->getFloatValue() && irrA2->getRootVal()->getFloatValue() == irrB2->getBase()->getFloatValue())
		}
		if (intA){
		if (intB){
		if (intA->getIntValue() == intB->getIntValue()){
		return exponentiate(add(multiply(expr1->getVector()[0], intB), multiply(expr2->getVector()[0], intA)), multiply(intA, intB));
		}
		}
		}
		if (eA){
		if (eB){
		return divide(add(expr1->getVector()[0], expr2->getVector()[0]), eA);
		}
		}
		if (irrA){
		if (irrB){
		if (irrA->getBase()->getFloatValue() == irrB->getBase()->getFloatValue() && irrA->getRootVal()->getFloatValue() == irrB->getRootVal()->getFloatValue()){
		return divide(add(expr1->getVector()[0], expr2->getVector()[0]), irrA);
		}
		}
		}
		if (logA){
		if (logB){
		if (logA->getBase()->getFloatValue() == logB->getBase()->getFloatValue() && logA->getArgument()->getFloatValue() == logB->getArgument()->getFloatValue()){
		return divide(add(expr1->getVector()[0], expr2->getVector()[0]), logA);
		}
		}
		}
		if (piA){
		if (piB){
		return divide(add(expr1->getVector()[0], expr2->getVector()[0]), piA);
		}
		}
		}
		else{
		return add(add(expr1->getVector()[0], expr2), expr1->getVector()[2]);
		}
		}
		*/
		Number *testNum = add(expr1, expr2->getVector()[0]);
		Expression *testExpr = dynamic_cast<Expression*>(testNum);
		return testExpr;
		// return add(add(expr1, expr2->getVector()[0]), expr2->getVector()[2]);
	}
	if (expr1) {
		if (expr1->getVector()[1]->toString() == "+") { // should be working properly
			Number *newN = add(expr1->getVector()[2], num2);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			if (expr3) { // if it is an expression
				if (expr3->getVector()[1]->toString() == "*"){
					return add(expr1->getVector()[0], newN);
				}
				else{
					return add(add(expr1->getVector()[0], num2), expr1->getVector()[2]);
				}
			}
			else{
				return add(expr1->getVector()[0], newN);
			}
		}
		else if (expr1->getVector()[1]->toString() == "-") { // should be working properly
			Number *newN = add(expr1->getVector()[2], num2);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			Integer *int3 = dynamic_cast<Integer*>(newN);
			if (expr3) {
				if (expr3->getVector()[1]->toString() == "*"){
					return add(expr1->getVector()[0], subtract(num2, expr1->getVector()[2]));
				}
				else{
					return subtract(add(expr1->getVector()[0], num2), expr1->getVector()[2]);
				}
			}
			if (int3){
				Number *newN2 = subtract(num2, expr1->getVector()[2]);
				Integer *int4 = dynamic_cast<Integer*>(newN2);
				if (int4->getIntValue() == 0){
					return expr1->getVector()[0];
				}
				else{
					if (int4->getIntValue() < 0){
						Integer *i = new Integer(-1);
						return new Expression(expr1->getVector()[0], multiply(i, newN2), new Operator("-"));
					}
					if (int4->getIntValue() > 0){
						return new Expression(expr1->getVector()[0], newN2, new Operator("+"));
					}
				}
			}
		}
		else if (expr1->getVector()[1]->toString() == "*") { // should be working properly
			Number *newN = add(expr1->getVector()[2], num2);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			if (expr3){ // if it is an expression
				if (expr3->getVector()[1]->toString() == "*"){ // if the expression has a multiply, must have been pi + pi = 2*pi or etc.
					Integer *int3 = dynamic_cast<Integer*>(expr1->getVector()[0]);
					if (int3){ // if the first term is an integer
						Integer *i = new Integer(1);
						return new Expression(add(expr1->getVector()[0], i), expr1->getVector()[2], new Operator("*")); // return int+1 * pi/log/etc.
					}
				}
			}
			else{
				return new Expression(num2, expr1, new Operator("+"));
			}
		}
		else if (expr1->getVector()[1]->toString() == "^") {
			return new Expression(expr1, num2, new Operator("+"));  // an add with an expression that has a ^ should never combine essentially.  log2 ^ 2 can't add with log2, etc.
		}
		else if (expr1->getVector()[1]->toString() == "/") {
			return new Expression(add(multiply(expr1->getVector()[2], num2), expr1->getVector()[0]), expr1->getVector()[2], new Operator("/"));
		}
	}
	if (expr2) { // actually seemingly unable to test these, or just can't think of a way, usually defaults to add(expr,term) I think.
		if (expr2->getVector()[1]->toString() == "+") {
			Number *newN = add(expr2->getVector()[2], num1);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			if (expr3) {
				if (expr3->getVector()[1]->toString() == "*"){
					return add(expr2->getVector()[0], newN);
				}
				else{
					return add(add(expr2->getVector()[0], num2), expr2->getVector()[2]);
				}
			}
			else{
				return add(expr2->getVector()[0], newN);
			}
		}
		else if (expr2->getVector()[1]->toString() == "-") {
			Number *newN = add(expr2->getVector()[2], num1);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			Integer *int3 = dynamic_cast<Integer*>(newN);
			if (expr3) {
				if (expr3->getVector()[1]->toString() == "*"){
					return add(expr2->getVector()[0], subtract(num1, expr2->getVector()[2]));
				}
				else{
					return subtract(add(expr2->getVector()[0], num1), expr2->getVector()[2]);
				}
			}
			if (int3){
				Number *newN2 = subtract(num1, expr2->getVector()[2]);
				Integer *int4 = dynamic_cast<Integer*>(newN2);
				if (int4->getIntValue() == 0){
					return expr2->getVector()[0];
				}
				else{
					if (int4->getIntValue() < 0){
						Integer *i = new Integer(-1);
						return new Expression(expr2->getVector()[0], multiply(i, newN2), new Operator("-"));
					}
					if (int4->getIntValue() > 0){
						return new Expression(expr2->getVector()[0], newN2, new Operator("+"));
					}
				}
			}
		}
		else if (expr2->getVector()[1]->toString() == "*") {
			Number *newN = add(expr2->getVector()[2], num1);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			if (expr3){
				if (expr3->getVector()[1]->toString() == "*"){
					Integer *int3 = dynamic_cast<Integer*>(expr2->getVector()[0]);
					if (int3){
						Integer *i = new Integer(1);
						return new Expression(add(expr2->getVector()[0], i), expr1->getVector()[2], new Operator("*"));
					}
				}
			}
			else{
				return new Expression(num1, expr1, new Operator("+"));
			}
		}
		else if (expr2->getVector()[1]->toString() == "^") {
			return new Expression(expr2, num1, new Operator("+"));
		}
		else if (expr2->getVector()[1]->toString() == "/") {
			return new Expression(add(multiply(expr2->getVector()[2], num1), expr2->getVector()[0]), expr2->getVector()[2], new Operator("/"));
		}
	}

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
			Expression *t = new Expression(int1, irr2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(int1, log2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(int1, e2, new Operator("+"));
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(int1, pi2, new Operator("+"));
		}

	}

	else if (irr1)
	{
		if (int2)
		{
			Expression *t = new Expression(irr1, int2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			if (irr1->getBase()->getFloatValue() == irr2->getBase()->getFloatValue() && irr1->getRootVal()->getFloatValue() == irr2->getRootVal()->getFloatValue())
			{
				Integer *temp = new Integer(2);
				Expression *t = new Expression(temp, irr1, new Operator("*"));
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);7
				return t;
			}
			else
			{
				Number *t = (new Expression(irr1, irr2, new Operator("+")))->simplify();
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (log2)
		{
			Expression *t = new Expression(irr1, log2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(irr1, e2, new Operator("+"));
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(irr1, pi2, new Operator("+"));
		}

	}

	else if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(log1, irr2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			if (log1->getBase()->getFloatValue() == log2->getBase()->getFloatValue() && log1->getArgument()->getFloatValue() == log2->getArgument()->getFloatValue())
			{
				Integer *temp = new Integer(2);
				Expression *t = new Expression(temp, log1, new Operator("*"));
				//change '+' to a term in order to work correctly with Number
				return t;
			}
			else
			{
				Expression *t = new Expression(log1, log2, new Operator("+"));
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (e2)
		{
			Expression *t = new Expression(log1, e2, new Operator("+"));
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(log1, pi2, new Operator("+"));
		}

	}
	else if (e1)
	{
		if (int2)
		{
			Expression *t = new Expression(e1, int2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(e1, irr2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(e1, log2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Integer *temp = new Integer(2);
			Expression *t = new Expression(temp, e1, new Operator("*"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(e1, pi2, new Operator("+"));
		}

	}
	else if (pi1)
	{
		if (int2)
		{
			Expression *t = new Expression(pi1, int2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(pi1, irr2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(pi1, log2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(pi1, e2, new Operator("+"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Integer *temp = new Integer(2);
			Expression *t = new Expression(temp, pi1, new Operator("*"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}

	}

	return new Expression(num1, num2, new Operator("+"));
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
	Expression *expr1 = dynamic_cast<Expression*>(num1);
	Expression *expr2 = dynamic_cast<Expression*>(num2);

	if (expr1 && expr2) {

	}
	if (int2) {
		if (int2->getFloatValue() < 0.0) {
			Integer *newInt = new Integer(abs(int2->getIntValue()));
			delete int2;
			return add(newInt, num1);
		}
	}
	if (expr1) {
		if (expr1->getVector()[1]->toString() == "+") { // should be good
			Number *newN = subtract(expr1->getVector()[2], num2);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			Integer *int3 = dynamic_cast<Integer*>(newN);
			if (expr3) { // if it is an expression
				Number *newN2 = subtract(expr1->getVector()[0], num2);
				Integer *i = dynamic_cast<Integer*>(newN2);
				if (i){
					if (i->getIntValue() == 0){
						return expr1->getVector()[2];
					}
					else{
						return add(newN2, expr1->getVector()[2]);
					}
				}
				else{
					return new Expression(expr1, num2, new Operator("-"));
				}

			}
			if (int3){
				if (int3->getIntValue() == 0){
					return expr1->getVector()[0];
				}
				if (int3->getIntValue() < 0){
					return add(int3, expr1->getVector()[0]);
				}
				if (int3->getIntValue() > 0){
					return add(int3, expr1->getVector()[0]);
				}
			}
			else{
				return subtract(expr1->getVector()[0], newN);
			}
		}
		else if (expr1->getVector()[1]->toString() == "-") {
			Number *newN = add(expr1->getVector()[2], num2);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			Integer *int3 = dynamic_cast<Integer*>(newN);
			Number *newN2 = add(expr1->getVector()[0], num2);
			Expression *expr4 = dynamic_cast<Expression*>(newN2);
			Integer *int4 = dynamic_cast<Integer*>(newN2);
			if (int3){
				return subtract(expr1->getVector()[0], newN);
			}
			if (int4){
				Number *newN3 = subtract(expr1->getVector()[0], num2);
				Integer *int5 = dynamic_cast<Integer*>(newN3);
				if (int5->getIntValue() == 0){
					return expr1->getVector()[2];
				}
				else{
					return subtract(newN3, expr1->getVector()[2]);
				}
			}
			if (expr3) {
				if (expr3->getVector()[1]->toString() == "*"){
					return subtract(expr1->getVector()[0], newN);
				}
				if (expr4->getVector()[1]->toString() == "*"){
					Integer *i = new Integer(-1);
					return multiply(i, expr1->getVector()[2]);
				}
				else{
					return new Expression(expr1, num2, new Operator("-"));
				}
			}
		}
		else if (expr1->getVector()[1]->toString() == "*") {
			Number *newN = add(expr1->getVector()[2], num2);
			Expression *expr3 = dynamic_cast<Expression*>(newN);
			if (expr3){ // if it is an expression
				if (expr3->getVector()[1]->toString() == "*"){ // if the expression has a multiply, must have been pi + pi = 2*pi or etc.
					Integer *int3 = dynamic_cast<Integer*>(expr3->getVector()[0]);
					if (int3){ // if the first term is an integer
						Integer *i = new Integer(1);
						Number *newN3 = subtract(expr1->getVector()[0], i);
						Integer *int4 = dynamic_cast<Integer*>(newN3);
						if (int4->getIntValue() == 1){
							return expr1->getVector()[2];
						}
						if (int4->getIntValue() == 0){
							return int4;
						}
						else{
							return new Expression(newN3, expr1->getVector()[2], new Operator("*")); // return int+1 * pi/log/etc.
						}
					}
				}
			}
			else{
				return new Expression(num2, expr1, new Operator("-"));
			}
		}
		else if (expr1->getVector()[1]->toString() == "^") {
			return new Expression(expr1, num2, new Operator("-"));
		}
		else if (expr1->getVector()[1]->toString() == "/") {
			Number *newN = multiply(expr1->getVector()[2], num2);
			Number *newN2 = subtract(expr1->getVector()[0], newN);
			Number *newN3 = divide(newN2, expr1->getVector()[2]);
			int a = 0;
			return new Expression(subtract(expr1->getVector()[0], multiply(expr1->getVector()[2], num2)), expr1->getVector()[2], new Operator("/"));
		}
	}
	if (expr2) {
		Integer *i = new Integer(-1);
		return multiply(i, subtract(expr2, num1));
	}

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
			Expression *t = new Expression(int1, irr2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(int1, log2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(int1, e2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(int1, pi2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}

	if (irr1)
	{
		if (int2)
		{
			Number *t = new Expression(irr1, int2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			if (irr1->getBase()->getFloatValue() == irr2->getBase()->getFloatValue() && irr1->getRootVal()->getFloatValue() == irr2->getRootVal()->getFloatValue())
			{
				int a = 0;
				Integer *i = new Integer(a);
				//Number *j = new Number(i);
				return i;
			}
			else
			{
				Expression *t = new Expression(irr1, irr2, new Operator("-"));
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (log2)
		{
			Expression *t = new Expression(irr1, log2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(irr1, e2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(e1, pi2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}

	}

	if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(log1, irr2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			if (log1->getBase()->getFloatValue() == log2->getBase()->getFloatValue() && log1->getArgument()->getFloatValue() == log2->getArgument()->getFloatValue())
			{
				int a = 0;
				Integer *i = new Integer(a);
				//Number *j = new Number(i);
				return i;
			}
			else
			{
				Expression *t = new Expression(log1, log2, new Operator("-"));
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (e2)
		{
			Expression *t = new Expression(log1, e2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (pi2)
		{
			Expression *t = new Expression(log1, pi2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}
	if (e1)
	{
		if (int2)
		{
			Expression *t = new Expression(e1, int2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(e1, irr2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(e1, log2, new Operator("-"));
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
			Expression *t = new Expression(irr1, pi2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}

	}
	if (pi1)
	{
		if (int2)
		{
			Expression *t = new Expression(pi1, int2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			Expression *t = new Expression(pi1, irr2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(pi1, log2, new Operator("-"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (e2)
		{
			Expression *t = new Expression(pi1, e2, new Operator("-"));
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
	return new Expression(num1, num2, new Operator("-"));
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

	if (expr1 && expr2) {
		// FOIL
		string a = expr1->getVector()[1]->toString();
		string b = expr2->getVector()[1]->toString();
		Number *n1 = expr1->getVector()[0];
		Number *n2 = expr1->getVector()[2];
		Number *n3 = expr2->getVector()[0];
		Number *n4 = expr2->getVector()[2];
		if (a == "+" && b == "+") {
			return add(add(multiply(n1, n3), multiply(n1, n4)), add(multiply(n2, n3), multiply(n2, n4)));
		}
		else if (a == "+" && b == "-") {
			return add(subtract(multiply(n1, n3), multiply(n1, n4)), subtract(multiply(n2, n3), multiply(n2, n4)));
		}
		else if (a == "-" && b == "+") {
			return subtract(add(multiply(n1, n3), multiply(n1, n4)), subtract(multiply(n2, n3), multiply(n2, n4)));
		}
		else if (a == "-" && b == "-") {
			return subtract(subtract(multiply(n1, n3), multiply(n1, n4)), add(multiply(n2, n3), multiply(n2, n4)));
		}
	}
	if (expr1) {
		if (expr1->getVector()[1]->toString() == "+") {
			return new Expression(multiply(num2, expr1->getVector()[0]), multiply(num2, expr1->getVector()[2]), new Operator("+"));
		}
		else if (expr1->getVector()[1]->toString() == "-") {
			return new Expression(multiply(num2, expr1->getVector()[0]), multiply(num2, expr1->getVector()[2]), new Operator("-"));
		}
		else if (expr1->getVector()[1]->toString() == "*") {
			if (dynamic_cast<Pi*>(num2) || dynamic_cast<E*>(num2)) {
				if ((dynamic_cast<Pi*>(expr1->getVector()[0]) && dynamic_cast<Pi*>(num2)) || (dynamic_cast<E*>(num2) && dynamic_cast<E*>(expr1->getVector()[0]))) {
					return multiply(expr1->getVector()[2], exponentiate(num2, new Integer(2)));
				}
				else if ((dynamic_cast<Pi*>(expr1->getVector()[2]) && dynamic_cast<Pi*>(num2)) || (dynamic_cast<E*>(num2) && dynamic_cast<E*>(expr1->getVector()[2]))) {
					return multiply(expr1->getVector()[0], exponentiate(num2, new Integer(2)));
				}
			}
			Number *nu2 = multiply(num2, expr1->getVector()[2]);
			if (!dynamic_cast<Expression*>(nu2)) {
				return new Expression(expr1->getVector()[0], nu2, new Operator("*"));
			}
			delete nu2;
			Number *nu1 = multiply(num2, expr1->getVector()[0]);
			return new Expression(nu1, expr1->getVector()[2], new Operator("*"));
		}
		else if (expr1->getVector()[1]->toString() == "/") {
			return new Expression(multiply(expr1->getVector()[0], num2), expr1->getVector()[2], new Operator("/"));
		}
		else if (expr1->getVector()[1]->toString() == "^") {
			if ((dynamic_cast<Pi*>(expr1->getVector()[0]) && dynamic_cast<Pi*>(num2)) || (dynamic_cast<E*>(expr1->getVector()[0]) && dynamic_cast<E*>(num2))) {
				return exponentiate(expr1->getVector()[0], add(expr1->getVector()[2], new Integer(1)));
			}
			return new Expression(num2, expr1, new Operator("*"));
		}
		else throw invalid_argument("Operator not recognized.");
	}
	else if (expr2) {
		if (expr2->getVector()[1]->toString() == "+") {
			return new Expression(multiply(num1, expr2->getVector()[0]), multiply(num1, expr2->getVector()[2]), new Operator("+"));
		}
		else if (expr2->getVector()[1]->toString() == "-") {
			return new Expression(multiply(num1, expr2->getVector()[0]), multiply(num1, expr2->getVector()[2]), new Operator("-"));
		}
		else if (expr2->getVector()[1]->toString() == "*") {
			if (dynamic_cast<Pi*>(num1) || dynamic_cast<E*>(num1)) {
				if ((dynamic_cast<Pi*>(expr2->getVector()[0]) && dynamic_cast<Pi*>(num1)) || (dynamic_cast<E*>(num1) && dynamic_cast<E*>(expr2->getVector()[0]))) {
					return multiply(expr2->getVector()[2], exponentiate(num1, new Integer(2)));
				}
				else if ((dynamic_cast<Pi*>(expr2->getVector()[2]) && dynamic_cast<Pi*>(num1)) || (dynamic_cast<E*>(num1) && dynamic_cast<E*>(expr2->getVector()[2]))) {
					return multiply(expr2->getVector()[0], exponentiate(num1, new Integer(2)));
				}
			}
			Number *nu2 = multiply(num1, expr2->getVector()[2]);
			if (!dynamic_cast<Expression*>(nu2)) {
				return new Expression(expr2->getVector()[0], nu2, new Operator("*"));
			}
			delete nu2;
			Number *nu1 = multiply(num1, expr2->getVector()[0]);
			return new Expression(nu1, expr2->getVector()[2], new Operator("*"));
		}
		else if (expr2->getVector()[1]->toString() == "/") {
			return new Expression(multiply(expr2->getVector()[0], num1), expr2->getVector()[2], new Operator("/"));
		}
		else if (expr2->getVector()[1]->toString() == "^") {
			if ((dynamic_cast<Pi*>(expr2->getVector()[0]) && dynamic_cast<Pi*>(num1)) || (dynamic_cast<E*>(expr2->getVector()[0]) && dynamic_cast<E*>(num1))) {
				return exponentiate(expr2->getVector()[0], add(expr2->getVector()[2], new Integer(1)));
			}
			return new Expression(num1, expr2, new Operator("*"));
		}
		else throw invalid_argument("Operator not recognized.");
	}

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
				Expression *t = new Expression(int1, irr2, new Operator("*"));
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
	}
	if (log2)
	{
		if (int1) {
			if (int1->getIntValue() == 1)
			{
				return log2;
			}
			else
			{
				Expression *t = new Expression(int1, log2, new Operator("*"));
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
	}
	else if (e2)
	{
		if (int1) {
			if (int1->getIntValue() == 1)
			{
				return e2;
			}
			else
			{
				Expression *t = new Expression(int1, e2, new Operator("*"));
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
	}
	else if (pi2)
	{
		if (int1) {
			if (int1->getIntValue() == 1)
			{
				return pi2;
			}
			else
			{
				Expression *t = new Expression(int1, pi2, new Operator("*"));
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
				Expression *t = new Expression(int2, irr1, new Operator("*"));
				//change '+' to a term in order to work correctly with Number
				return t;
			}
		}
		else if (irr2)
		{
			if (irr1->getBase()->getFloatValue() == irr2->getBase()->getFloatValue())
			{
				Integer *i = new Integer(1);
				Number *newRootVal = add(divide(i, irr1->getRootVal()), divide(i, irr2->getRootVal()));
				irr1->setRootVal(newRootVal);
				//Irrational *newIrrational = new Irrational(irr1->getBase(), newrootVal, newconst);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);
				return irr1;
			}
			if (irr1->getRootVal()->getFloatValue() == irr2->getRootVal()->getFloatValue())
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
				Expression *t = new Expression(irr1, irr2, new Operator("*"));
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		else if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, log2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, e2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (pi2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, pi2, new Operator("*"));
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
				Expression *t = new Expression(int2, log1, new Operator("*"));
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, irr2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, log2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, e2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (pi2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, pi2, new Operator("*"));
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
				Expression *t = new Expression(int2, e1, new Operator("*"));
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, irr2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, log2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			Integer *temp = new Integer(2);
			Expression *t = new Expression(e1, temp, new Operator("^"));
			return t;
		}
		else if (pi2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, pi2, new Operator("*"));
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
				Expression *t = new Expression(int2, pi1, new Operator("*"));
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, irr2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, log2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, e2, new Operator("*"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (pi2)
		{
			Integer *temp = new Integer(2);
			Expression *t = new Expression(pi1, temp, new Operator("^"));
			return t;
		}
	}
	return new Expression(num1, num2, new Operator("*"));
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
	Expression *expr1 = dynamic_cast<Expression*>(num1);
	Expression *expr2 = dynamic_cast<Expression*>(num2);

	if (num2->getFloatValue() == 0.0){
		throw invalid_argument("Cannot divide by 0");
	}

	if (expr1) {
		if (expr1->getVector()[1]->toString() == "+") {
			Number *newN1 = divide(expr1->getVector()[0], num2);
			Number *newN2 = divide(expr1->getVector()[2], num2);
			return new Expression(newN1, newN2, new Operator("+"));
		}
		else if (expr1->getVector()[1]->toString() == "-") {
			Number *newN1 = divide(expr1->getVector()[0], num2);
			Number *newN2 = divide(expr1->getVector()[2], num2);
			if (!dynamic_cast<Expression*>(newN1) || !dynamic_cast<Expression*>(newN2)) {
				return new Expression(newN1, newN2, new Operator("-"));
			}
			else {
				if (&newN1 != &num1 && &newN1 != &num2) {
					delete newN1;
				}
				if (&newN2 != &num1 && &newN2 != &num2) {
					delete newN2;
				}
				return new Expression(num1, num2, new Operator("/"));
			}
		}
		else if (expr1->getVector()[1]->toString() == "*") {
			Number *newN1 = divide(expr1->getVector()[2], num2);
			if (!dynamic_cast<Expression*>(newN1)) {
				return new Expression(expr1->getVector()[0], newN1, new Operator("*"));
			}
			else {
				if (&newN1 != &num2 && &newN1 != &expr1->getVector()[2]) {
					delete newN1;
				}
				return new Expression(expr1->getVector()[0], divide(expr1->getVector()[2], num2), new Operator("*"));
			}
		}
		else if (expr1->getVector()[1]->toString() == "/") {
			return new Expression(expr1->getVector()[0], multiply(expr1->getVector()[2], num2), new Operator("/"));
		}
		else if (expr1->getVector()[1]->toString() == "^") {
			return new Expression(expr1, num2, new Operator("/"));
		}
		else throw invalid_argument("Operator not recognized.");
	}
	if (expr2) {
		if (expr2->getVector()[1]->toString() == "+") {
			return new Expression(num1, expr2, new Operator("/"));
		}
		else if (expr2->getVector()[1]->toString() == "-") {
			return new Expression(num1, expr2, new Operator("/"));
		}
		else if (expr2->getVector()[1]->toString() == "*") {
			Number * newN = divide(num1, expr2->getVector()[2]);
			if (!dynamic_cast<Expression*>(newN)) {

			}
		}
		else if (expr2->getVector()[1]->toString() == "/") {

		}
		else if (expr2->getVector()[1]->toString() == "^") {

		}
		else throw invalid_argument("Operator not recognized.");
	}

	if (int1)
	{
		if (int2)
		{
			if (int1->getIntValue() == int2->getIntValue()) {
				return new Integer(1);
			}
			int divisor = gcd(int1->getIntValue(), int2->getIntValue());

			Integer *i = new Integer(int1->getIntValue() / divisor);
			Integer *j = new Integer(int2->getIntValue() / divisor);
			if (j->getIntValue() == 1) {
				delete j;
				return i;
			}
			return new Expression(i, j, new Operator("/"));
		}
		else if (irr2)
		{
			Expression *t = new Expression(int1, irr2, new Operator("/"));
			return t;
		}
		else if (log2)
		{
			Expression *t = new Expression(int1, log2, new Operator("/"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
	}

	if (irr1)
	{
		if (int2)
		{
			Expression *t = new Expression(irr1, int2, new Operator("/"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		else if (irr2)
		{
			if (irr1->getBase()->getFloatValue() == irr2->getBase()->getFloatValue())
			{
				Number *newrootVal = subtract(irr1->getRootVal(), irr2->getRootVal());
				irr1->setRootVal(newrootVal);
				//Irrational *newIrrational = new Irrational(irr1->getBase(), newrootVal, newconst);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);
				return irr1;
			}
			else if (irr1->getRootVal()->getFloatValue() == irr2->getRootVal()->getFloatValue())
			{
				Number *newBase = divide(irr1->getRootVal(), irr2->getRootVal());
				irr1->setBase(newBase);
				//Irrational *newIrrational = new Irrational(irr1->getBase(), newrootVal, newconst);
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);
				return irr1;
			}
			else if (irr1->getBase()->getFloatValue() == irr2->getBase()->getFloatValue() && irr1->getRootVal()->getFloatValue() == irr2->getRootVal()->getFloatValue())
			{
				int a = 1;
				Integer *t = new Integer(a);
				return t;

			}
			else
			{
				//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
				Expression *t = new Expression(irr1, irr2, new Operator("/"));
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		else if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(irr1, log2, new Operator("/"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}

	}

	if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, new Operator("/"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, irr2, new Operator("/"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			if (log1->getBase()->getFloatValue() == log2->getBase()->getFloatValue() && log1->getArgument()->getFloatValue() == log1->getArgument()->getFloatValue())
			{
				int a = 1;
				Integer *t = new Integer(a);
				return t;
			}
			else
			{
				//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
				Expression *t = new Expression(log1, log2, new Operator("/"));
				//Const is not implemented yet
				//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
				return t;
			}
		}
		if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, pi2, new Operator("/"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (e2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(log1, pi2, new Operator("/"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
	}
	if (e1)
	{
		if (int2)
		{
			Expression *t = new Expression(e1, int2, new Operator("/"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, irr2, new Operator("/"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(e1, log2, new Operator("/"));
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
			Expression *t = new Expression(e1, pi2, new Operator("/"));
			return t;
		}
	}
	if (pi1)
	{
		if (int2)
		{
			Expression *t = new Expression(pi1, int2, new Operator("/"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}
		if (irr2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, irr2, new Operator("/"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		if (log2)
		{
			//Irrational *newIrrational = new Irrational(irr1->getBase(), irr1->getRootVal, newconst);
			Expression *t = new Expression(pi1, log2, new Operator("/"));
			//Const is not implemented yet
			//Number *t = new Number(newIrrational, irr2); //unsure how Number is going to deal with multiplication operator
			return t;
		}
		else if (e2)
		{

			Expression *t = new Expression(pi1, e2, new Operator("/"));
			return t;
		}
		else if (pi2)
		{
			int a = 1;
			Integer *t = new Integer(a);
			return t;
		}
	}
	return new Expression(num1, num2, new Operator("/"));
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
	Expression *expr1 = dynamic_cast<Expression*>(num1);
	Expression *expr2 = dynamic_cast<Expression*>(num2);

	if (int1)
	{
		int a = int1->getIntValue();
		if (int2)
		{
			int b = 1;
			for (int i = 0; i < abs(int2->getIntValue()); i++)
			{
				b = b*a;
			}
			if (int2->getIntValue() < 0)
				return new Expression(new Integer(1), new Integer(b), new Operator("/"));
			else {
				return new Integer(b);
			}
		}
		if (expr2) {
			if (expr2->getFloatValue() < 0) {
				if (expr2->getVector()[1]->toString() == "/" && dynamic_cast<Integer*>(expr2->getVector()[2])) {
					return new Expression(new Integer(1), new Irrational(new Integer((int)pow(a, abs(dynamic_cast<Integer*>(expr2->getVector()[0])->getIntValue()))), new Integer((int)abs(dynamic_cast<Integer*>(expr2->getVector()[2])->getIntValue()))), new Operator("/"));
				}
			}
			else {
				if (expr2->getVector()[1]->toString() == "/" && dynamic_cast<Integer*>(expr2->getVector()[0])) {
					return new Irrational(new Integer((int)pow(a, dynamic_cast<Integer*>(expr2->getVector()[0])->getIntValue())), expr2->getVector()[2]);
				}
			}
		}
	}

	else if (irr1)
	{
		if (int2)
		{

			Number *newRootVal = multiply(irr1->getRootVal(), int2);
			Irrational *newIrr = new Irrational(irr1->getBase(), newRootVal);
			return newIrr;
		}
	}


	else if (e1)
	{
		if (int2)
		{
			Expression *t = new Expression(e1, int2, new Operator("^"));
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
	if (expr2) {
		string expr2op = expr2->getVector()[1]->toString();
		if (expr2op == "+") {
			return multiply(exponentiate(num1, expr2->getVector()[0]), exponentiate(num1, expr2->getVector()[2]));
		}
		else if (expr2op == "-") {
			return divide(exponentiate(num1, expr2->getVector()[0]), exponentiate(num1, expr2->getVector()[2]));
		}
	}
	return new Expression(num1, num2, new Operator("^"));
}

int Calculate::gcd(int x, int y)
{
	if (y == 0) {
		return x; //base case,return x when y equals 0
	}
	else {
		return gcd(y, x % y);
	}
}