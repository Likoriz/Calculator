#pragma once
#include "Variable.h"
class Fraction :
    public Variable
{
public:
	Fraction(std::string name);
	Variable* operator +(Variable* arg);
	Variable* operator *(Variable* arg);
	Variable* operator -(Variable* arg);
	void operator /(Variable* arg);
	Variable* toUpDegree(int degree);
};

