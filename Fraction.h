#pragma once
#include "Variable.h"
class Fraction :
    public Variable
{
public:
	Fraction(std::string name);
	void operator +(Variable* arg);
	void operator *(Variable* arg);
	void operator -(Variable* arg);
	void operator /(Variable* arg);
};

