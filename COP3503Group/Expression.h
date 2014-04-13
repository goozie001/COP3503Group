#pragma once
class Expression
{
public:
	Expression();
	~Expression();

	virtual Expression *simplify() = 0;
	virtual bool isOfTypeNumber() { return false; }
};

