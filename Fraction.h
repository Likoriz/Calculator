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
	Fraction(std::string name, int n, int d);
	Variable* operator+(Variable* arg);
	Variable* operator+(Float* arg);

	Variable* operator*(Variable* arg);
	Variable* operator*(Float* arg);

	Variable* operator-(Variable* arg);
	Variable* operator-(Float* arg);

	Variable* operator/(Variable* arg);
	Variable* operator/(Float* arg);

	Variable* toUpDegree(Variable* arg);
	Variable* toUpDegree(Float* arg);

	void print(Variable* arg = nullptr);
	Fraction* minimize(Fraction* f = nullptr);
	static int LCD(int numerator, int denominator);
	Fraction* turnToFraction(double val);
};

