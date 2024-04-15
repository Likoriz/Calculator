#pragma once
#include "Variable.h"

class Fraction : public Variable
{
private:
	int integer = 0;
	int numerator;
	int denominator;
public:
	Fraction(std::string name);
	Fraction();
	Variable* operator +(Variable* arg);
	Variable* operator *(Variable* arg);
	Variable* operator -(Variable* arg);
	Variable* operator /(Variable* arg);
	Variable* toUpDegree(int degree);
	void print(Variable* arg = nullptr);
};

