#include "Log.h"


Log::Log()
{
}

Log::Log(Number* base, Expression* argument) {
	this->base = base;
	this->argument = argument;
}

Log::~Log()
{
}

Number *Log::getBase() {
	return base;
}

Expression *Log::getArgument() {
	return argument;
}

// Overridden methods

float Log::getFloatValue() {
	return floatValue;
}

// TODO: Implement simplify Log method
Number *Log::simplify() {
	return NULL;
}

// TODO: Implement Log toString method
string Log::toString() {
	string s;
	return s;
}
