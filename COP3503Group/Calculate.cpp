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
			if (irr1->getBase() == irr2->getBase() && irr1->getRootVal() == irr2->getRootVal())
			{
				Integer *temp = new Integer(2);
				Expression *t = new Expression(irr1, temp, new Operator("*"));
				//Const is not implemented yet
				//Number *t = new Number(newIrrational);7
				return t;
			}
			else
			{
				Expression *t = new Expression(irr1, irr2, new Operator("+"));
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
			if (log1->getBase() == log2->getBase() && log1->getArgument() == log2->getArgument())
			{
				Integer *temp = new Integer(2);
				Expression *t = new Expression(log1, temp, new Operator("*"));
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
			Expression *t = new Expression(log1, temp, new Operator("*"));
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
			Expression *t = new Expression(pi1, temp, new Operator("*"));
			//change '+' to a term in order to work correctly with Number
			return t;
		}

	}

	return new Expression(num1, num2, new Operator("+"));

	/* if(expr1){
	vector<Number*> exprVector1 = expr1->getVector();
	if(int2){
	int a;
	int j;
	vector<Number*> tempExprVect;
	bool intfound = false;
	for(int i = 0; i < exprVector1.size(); i++){
	Integer *int3 = dynamic_cast<Integer*>(exprVector1[i]);
	if(int3){
	intfound = true;
	if(i != exprVector1.size()-1){
	if(exprVector1[i-1] == new Operator("+") || exprVector1[i-1] == new Operator("-")){ //check operation implementation
	a = int3->getIntValue() + int2->getIntValue();
	j = i;
	}
	}
	else if(exprVector1[i-1] == new Operator("+")){
	a = int3->getIntValue() + int2->getIntValue();
	j = i;
	}
	else if(exprVector1[i-1] ==  new Operator("-")){
	a = int2->getIntValue()-int3->getIntValue();
	j = i;
	}
	}
	}
	if(intfound){
	for(int i = 0; i < j-1; i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	for(int i = j+1; i < exprVector1.size(); i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	Integer *int4 = new Integer(a);
	tempExprVect.push_back(new Operator("-"));
	tempExprVect.push_back(int4);
	Expression *t = new Expression(tempExprVect);
	return t;
	}
	else{
	Expression *t = new Expression(expr1, int2, new Operator("+"));
	return t;
	}
	}
	else if(irr2){
	int a;
	int j;
	vector<Number*> tempExprVect;
	bool irrfound = false;
	bool coeffound = false;
	for(int i = 0; i < exprVector1.size(); i++){
	Irrational *irr3 = dynamic_cast<Irrational*>(exprVector1[i]);
	if(irr3){
	irrfound = true;
	if(irr2->getBase() == irr3->getBase() && irr2->getRootVal() == irr3->getRootVal()){
	if(i != exprVector1.size()-1){
	if(exprVector1[i-1] == new Operator("+") || exprVector1[i-1] ==  new Operator("-")){ //check operation implementation
	if (i != 0) {
	if(exprVector1[i-1] == new Operator("*")){
	Integer *int3 = dynamic_cast<Integer*>(exprVector1[i-2]);
	if(int3){
	coeffound = true;
	if(exprVector1[i-3] == new Operator("+")){
	a = 1+int3->getIntValue();
	j = i;
	}
	else if(exprVector1[i-3] == new Operator("-")){
	a = 1-int3->getIntValue();
	j = i;
	}
	}
	}
	if(exprVector1[i-1] == new Operator("+")){
	a = 2;
	j=i;
	}
	else if(exprVector1[i-1] == new Operator("-")) {
	a = 0;
	j = i;
	}
	}
	}
	}
	else{
	if(exprVector1[i-1] == new Operator("*")){
	Integer *int3 = dynamic_cast<Integer*>(exprVector1[i-2]);
	if(int3){
	coeffound = true;
	if(exprVector1[i-3] == new Operator("+")){
	a = 1+int3->getIntValue();
	j=i;
	}
	else if(exprVector1[i-3] == new Operator("-")){
	a = 1-int3->getIntValue();
	j=i;
	}
	}
	}
	if(exprVector1[i-1] == new Operator("+")){
	a = 2;
	j=i;
	}
	else if(exprVector1[i-1] == new Operator("-")) {
	a = 0;
	j = i;
	}
	}
	}
	}
	}

	if(irrfound){
	Irrational *irr3 = dynamic_cast<Irrational*>(exprVector1[j]);
	if(irr2->getBase() == irr3->getBase() && irr2->getRootVal() == irr3->getRootVal()){
	if(coeffound){
	for(int i = 0; i < j-2; i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	for(int i = j+1; i < exprVector1.size(); i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	}
	else{
	for(int i = 0; i < j-1; i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	for(int i = j+1; i < exprVector1.size(); i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	}
	Integer *int4 = new Integer(a);
	Expression *tempExpr = new Expression(int4, irr2, new Operator("*"));
	vector<Number*> tempVect = tempExpr->getVector();
	for(int i = 0; i < 3; i++){
	tempExprVect.push_back(tempVect[i]);
	}
	Expression *t = new Expression(tempExprVect);
	return t;
	}
	}

	else{
	Expression *t = new Expression(expr1, irr2, new Operator("+"));
	return t;
	}

	}
	else if(log2){
	int a;
	int j;
	vector<Number*> tempExprVect;
	bool logfound = false;
	bool coeffound = false;
	for(int i = 0; i < exprVector1.size(); i++){
	Log *log3 = dynamic_cast<Log*>(exprVector1[i]);
	if(log3){
	logfound = true;
	if(log3->getBase() == log2->getBase() || log3->getArgument() == log2->getArgument()){
	if(i != exprVector1.size()-1){
	if(exprVector1[i-1] == new Operator("+") || exprVector1[i-1] ==  new Operator("-")){ //check operation implementation
	if(i != 0) {
	if(exprVector1[i-1] == new Operator("*")){
	Integer *int3 = dynamic_cast<Integer*>(exprVector1[i-2]);
	if(int3){
	coeffound = true;
	a = int3->getIntValue()+1;
	j = i;
	}
	}
	else{
	if(exprVector1[i-1] == new Operator("+")){
	a = 2;
	j = i;
	}
	else if(exprVector1[i-1] == new Operator("-")){
	a = 0;
	j = i;
	}
	}
	}
	}
	}
	else{  // if at the end
	if(exprVector1[i-1] == new Operator("*")){
	Integer *int3 = dynamic_cast<Integer*>(exprVector1[i-2]);
	if(int3){
	coeffound = true;
	if(exprVector1[i-3] == new Operator("+")){
	a = 1+int3->getIntValue();
	j = i;
	}
	else if(exprVector1[i-3] == new Operator("-")){
	a = 1-int3->getIntValue();
	j = i;
	}
	}
	}
	if(exprVector1[i-1] == new Operator("+")){
	a = 2;
	j = i;
	}
	else if( exprVector1[i-1] ==  new Operator("-")){
	a = 0;
	j = i;
	}
	}
	}
	}
	}

	if(logfound){
	Log *log3 = dynamic_cast<Log*>(exprVector1[j]);
	if(log2->getBase() == log3->getBase() && log2->getArgument() == log3->getArgument()){
	if(coeffound){
	for(int i = 0; i < j-2; i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	for(int i = j+1; i < exprVector1.size(); i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	}
	else{
	for(int i = 0; i < j-1; i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	for(int i = j+1; i < exprVector1.size(); i++){
	tempExprVect.push_back(exprVector1[i]);
	}
	}
	Integer *int4 = new Integer(a);
	Expression *tempExpr = new Expression(int4, log2, new Operator("*"));
	vector<Number*> tempVect = tempExpr->getVector();
	for(int i = 0; i < 3; i++){
	tempExprVect.push_back(tempVect[i]);
	}
	Expression *t = new Expression(tempExprVect);
	return t;
	}
	}
	else{
	Expression *t = new Expression(expr1, log2, new Operator("+"));
	return t;
	}
	}
	}*/
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
			if (irr1->getBase() == irr2->getBase() && irr1->getRootVal() == irr2->getRootVal())
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
			if (log1->getBase() == log2->getBase() && log1->getArgument() == log2->getArgument())
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
			Expression *t = new Expression(pi1, pi2, new Operator("-"));
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
				Expression *t = new Expression(irr1, int2, new Operator("*"));
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
				Expression *t = new Expression(log1, int2, new Operator("*"));
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
			Expression *t = new Expression(e1, temp, new Operator("^"));
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
				return new Expression(divide(expr1->getVector()[0], num2), expr1->getVector()[2], new Operator("*"));
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
			if (log1->getBase() == log2->getBase() && log1->getArgument() == log1->getArgument())
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

	else if (log1)
	{
		if (int2)
		{
			Expression *t = new Expression(log1, int2, new Operator("^"));
			return t;
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
	else if (expr1) {
		if (expr2) {

		}
		else {

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