#pragma once
#include "Variable.h"

class Float;

class Complex : public Variable
{
private:
	float real;
	float imaginary;
public: 
	Complex(std::string name);
	Complex();
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

