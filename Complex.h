#pragma once
#include "Variable.h"

class Complex : public Variable
{
private:
	float real;
	float imaginary;
public: 
	Complex(std::string name);
	Complex();
	Variable* operator +(Variable* arg);
	Variable* operator *(Variable* arg);
	Variable* operator -(Variable* arg);
	Variable* operator /(Variable* arg);
	Variable* toUpDegree(int degree);
	void print(Variable* arg = nullptr);
};

