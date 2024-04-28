#pragma once
#include "Variable.h"

class Float;

class Complex : public Variable
{
private:
	double real;
	double imaginary;
public: 
	Complex(std::string name);
	Complex();
	Complex(std::string name, double r, double i);
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
};

