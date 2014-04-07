#include "Log.h"


Log::Log()
{
}

Log::Log(Number* base, Number* argument) {
	this->base = base;
	this->argument = argument;
}

Log::~Log()
{
}

Number *Log::getBase() {
	return base;
}

Number *Log::getArgument() {
	return argument;
}

// Overridden methods

float Log::getFloatValue() {
	return floatValue;
}

// TODO: Implement simplify Log method
Number *Log::simplify() {

}

// TODO: Implement Log toString method
string Log::toString() {

}
