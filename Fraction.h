#pragma once
#include "Variable.h"

class Float;

class Fraction : public Variable
{
private:
	int integer = 0;
	int numerator;
	int denominator;
public:
	Fraction(std::string name);
	Fraction();
	Variable* operator+(Variable* arg);
	Variable* operator+(Float* arg);

	Variable* operator*(Variable* arg);
	Variable* operator*(Float* arg);

	Variable* operator-(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator/(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(int degree);
	void print(Variable* arg = nullptr);
	Fraction* minimize(Fraction* f = nullptr);
	int LCD(int numerator, int denominator);
	Fraction* turnToFraction(double val);
};

