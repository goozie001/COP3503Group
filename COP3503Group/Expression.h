#pragma once
class Expression
{
public:
	Expression();
	~Expression();
	Expression(Expression *expr1, Expression *expr2, Expression *oper);

	virtual Expression *simplify() = 0;
	virtual bool isOfTypeNumber() { return false; }
};

