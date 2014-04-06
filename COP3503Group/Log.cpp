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

float Log::getFloatValue() {
	return floatValue;
}
